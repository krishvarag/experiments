# Nomad cluster setup 
## Docker install
```
yum install -y unzip yum-utils device-mapper-persistent-data lvm2
yum-config-manager --add-repo https://download.docker.com/linux/centos/docker-ce.repo
yum install -y docker-ce docker-ce-cli containerd.io
systemctl enable docker
systemctl start docker
# Add additional users to docker group
usermod -aG docker <add_user>
```
## Nomad Cluster creation
```
Download nomad from https://www.nomadproject.io/downloads.html
nomad -autocomplete-install
# create data directory
mkdir -p /opt/nomad
# create service entry
touch /etc/systemd/system/nomad.service

mkdir -p /etc/nomad.d
chmod700 /etc/nomad.d/
chmod 700 /etc/nomad.d/
touch /etc/nomad.d/nomad.hcl
touch /etc/nomad.d/server.hcl
touch /etc/nomad.d/client.hcl
stemctl enable nomad
systemctl start nomad
systemctl status  nomad
```
## Client on Second node 
```
2 files : 
# nomad.hcl  ( datacenter + data dir location)
datacenter = "changeme"
data_dir = "/opt/nomad"
# client.hcl
client {
  enabled = true
  servers = ["10.x.y.z:4647"]
}

 nomad agent -config /etc/nomad.d/
```
## Start Consul 
```
#
/consul agent -config-dir=/etc/consul.d/ -bind=x.y.z.1  -advertise=x.y.z.a -ui -client=0.0.0.0
```
