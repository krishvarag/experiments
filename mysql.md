## Install Mysql Community Server

```
wget https://dev.mysql.com/get/mysql57-community-release-el7-9.noarch.rpm
sudo yum localinstall mysql57-community-release-el7-9.noarch.rpm

# yum repolist enabled | grep "mysql.*-community.*"
mysql-connectors-community/x86_64                      MySQL Connectors C     95
mysql-tools-community/x86_64                           MySQL Tools Commun     84
mysql57-community/x86_64                               MySQL 5.7 Communit    327
#  yum repolist all | grep mysql
yum-config-manager --disable mysql56-community
yum-config-manager --enable  mysql57-community

wget https://dev.mysql.com/get/Downloads/MySQL-5.7/mysql-community-server-5.7.25-1.el7.x86_64.rpm
;sudo rpm  -ivh mysql-community-server-5.7.24-1.el7.x86_64.rpm
yum localhostinstall mysql-community-server-5.7.24-1.el7.x86_64.rpm
# remove default Maria db config
sudo yum -y remove mariadb-config
# install mysql community server
yum -y install mysql-community-server
systemctl start mysqld.service
systemctl enable mysqld.service

```
* Get Server version
```
  use mysql
  show variables like "%version%";
```

* Get user List
```
use mysql
select Host,User,Show_db_priv  from user;
```


* Change root passworsd

```
use mysql
update user set authentication_string=PASSWORD("changeme") where User='root';
update user set Password=PASSWORD("changeme") where User='root';
flush privileges;
```

* Create DB T1 and give access to T1 
```
create database t1;
grant all privileges on t1.* to  't1'@'%' identified by 'set_my_password';
flush privileges;
```
