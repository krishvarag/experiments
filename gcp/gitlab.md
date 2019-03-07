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
sudo gitlab-ctl start
```
## Change data location
```
sudo gitlab-ctl stop
sudo rsync -av /var/opt/gitlab/git-data/repositories /disk2/git-data/
; Modify  gitlab configuration
/etc/gitlab/gitlab.rb
git_data_dirs({"default" => "/disk2/git-data"})
sudo gitlab-ctl reconfigure
; start the service
sudo gitlab-ctl start
```
