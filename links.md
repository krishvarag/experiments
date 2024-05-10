## General
* [https://regex101.com/](https://regex101.com/)
## Python
* [PYTHEX](https://pythex.org/)
* [CPython](https://python.org), [PyPy](https://www.pypy.org/features.html) , [https://nuitka.net/](https://nuitka.net/),
* [pyenv](https://github.com/pyenv/pyenv), [Python In Browser Transcrypt](https://www.transcrypt.org/)
## Linux

* [Commands] (http://www.pixelbeat.org/cmdline.html)
* [systemd] (https://access.redhat.com/videos/403833)
### networking
```
nmcli d Show the status of all network interfaces
nmcli d show enp2s0
nmcli d [connect|disconnect]  enp2s0
```

## Docker 
* [Docker EcoSystem] (https://www.digitalocean.com/community/tutorials/the-docker-ecosystem-an-introduction-to-common-components)

### Centos 7 Installation
```
journalctl -f -l -u docker   ; to list logs of docker service

nmcli d show docker0
GENERAL.DEVICE:                         docker0
GENERAL.TYPE:                           bridge
GENERAL.HWADDR:                         02:42:E0:2C:DE:F6
GENERAL.MTU:                            1500
GENERAL.STATE:                          100 (connected)
GENERAL.CONNECTION:                     docker0
GENERAL.CON-PATH:                       /org/freedesktop/NetworkManager/ActiveConnection/7
IP4.ADDRESS[1]:                         172.17.0.1/16
IP4.GATEWAY:                            --
IP6.GATEWAY:                            --

````

