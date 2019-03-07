# [Install](https://about.gitlab.com/install/#centos-7) gitlab on CENTOS 7
```
sudo yum install -y curl policycoreutils-python openssh-server
sudo systemctl enable sshd
sudo systemctl start sshd
sudo firewall-cmd --permanent --add-service=http
sudo systemctl reload firewall

sudo yum install postfix
sudo systemctl enable postfix
sudo systemctl start postfix
; Add the GitLab package repository.
curl https://packages.gitlab.com/install/repositories/gitlab/gitlab-ee/script.rpm.sh | sudo bash
; install
sudo EXTERNAL_URL="http://yuga.server.com" yum install -y gitlab-ee

```
## Starting and stopping
```
sudo gitlab-ctl stop
ok: down: alertmanager: 0s, normally up
ok: down: gitaly: 1s, normally up
ok: down: gitlab-monitor: 0s, normally up
ok: down: gitlab-workhorse: 1s, normally up
ok: down: logrotate: 0s, normally up
ok: down: nginx: 1s, normally up
ok: down: node-exporter: 0s, normally up
ok: down: postgres-exporter: 0s, normally up
ok: down: postgresql: 1s, normally up
ok: down: prometheus: 0s, normally up
ok: down: redis: 1s, normally up
ok: down: redis-exporter: 0s, normally up
ok: down: sidekiq: 0s, normally up
ok: down: unicorn: 0s, normally up

sudo gitlab-ctl start
```
## Change data location
```
sudo gitlab-ctl stop
; create new data location and change the permission
mkdir -p /disk2/git-data
chown git /disk2/git-data
chmod 700 /disk2/git-data
drwx------. 2 git  root  4096 Mar  7 04:20 git-data
sudo rsync -av /var/opt/gitlab/git-data/repositories /disk2/git-data/
; Modify  gitlab configuration
/etc/gitlab/gitlab.rb
git_data_dirs({"default" => "/disk2/git-data"})
sudo gitlab-ctl reconfigure
; start the service
sudo gitlab-ctl start
ok: run: alertmanager: (pid 8703) 0s
ok: run: gitaly: (pid 8711) 1s
ok: run: gitlab-monitor: (pid 8722) 0s
ok: run: gitlab-workhorse: (pid 8733) 0s
ok: run: logrotate: (pid 8740) 1s
ok: run: nginx: (pid 8753) 0s
ok: run: node-exporter: (pid 8758) 1s
ok: run: postgres-exporter: (pid 8762) 0s
ok: run: postgresql: (pid 8767) 1s
ok: run: prometheus: (pid 8775) 0s
ok: run: redis: (pid 8782) 1s
ok: run: redis-exporter: (pid 8862) 0s
ok: run: sidekiq: (pid 8867) 0s
ok: run: unicorn: (pid 8874) 1s

```
