# Nomad cluster setup 
```
Download nomad from https://www.nomadproject.io/downloads.html
nomad -autocomplete-install
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
