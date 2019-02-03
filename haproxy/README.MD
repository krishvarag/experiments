## Harpoxy  Installation from Source on RedHat

## Build environment
```
yum install -y  gcc pcre-static pcre-devel openssl-devel 
```
## Haproxy Source Build
* [Source](http://www.haproxy.org/download/)
```
wget //www.haproxy.org/download/1.8/src/haproxy-1.8.17.tar.gz
tar xzvf haproxy-1.8.17.tar.gz
cd haproxy-1.8.17
make TARGET=linux2628 USE_LINUX_TPROXY=1 USE_ZLIB=1 USE_REGPARM=1 USE_OPENSSL=1 USE_PCRE=1
# the build generates haproxy executable
```

##  Install haproxy
```
sudo cp haproxy /usr/local/sbin/haproxy
sudo mkdir -p /etc/haproxy
sudo mkdir -p /var/lib/haproxy 
sudo touch /var/lib/haproxy/stats
sudo ln -s /usr/local/sbin/haproxy /usr/sbin/haproxy
```

## Create haproxy user
```
id -u haproxy &> /dev/null || useradd -s /usr/sbin/nologin -r haproxy 
```

## Enabling as service 
* Copy the following template as /lib/systemd/haproxy.service
```
[Unit]
Description=HAProxy Load Balancer
Documentation=man:haproxy(1)
Documentation=file:/usr/share/doc/haproxy/configuration.txt.gz
# allows us to do millisecond level restarts without triggering alert in Systemd
StartLimitInterval=0
StartLimitBurst=0
After=network.target syslog.service
Wants=syslog.service

[Service]
Environment="CONFIG=/etc/haproxy/haproxy.cfg" "PIDFILE=/run/haproxy.pid"
# EXTRAOPTS and RELOADOPS come from this default file
EnvironmentFile=-/etc/default/haproxy
ExecStartPre=/usr/sbin/haproxy -f $CONFIG -c -q
ExecStart=/usr/sbin/haproxy -W -f $CONFIG -p $PIDFILE $EXTRAOPTS
ExecReload=/usr/sbin/haproxy -f $CONFIG -c -q $EXTRAOPTS $RELOADOPTS
ExecReload=/bin/kill -USR2 $MAINPID
KillMode=mixed
Restart=always
Type=forking

[Install]
WantedBy=multi-user.target

```
```
sudo chmod 755 /lib/systemd/haproxy.service
sudo systemctl daemon-reload
```
# Running as service 
```
systemctl enablle haproxy.service
systemctl start haproxy.service
```
