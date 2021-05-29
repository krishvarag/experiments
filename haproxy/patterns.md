* [Filter By IP](#filter-by-ip)
* [Stick Tables](https://www.haproxy.com/blog/introduction-to-haproxy-stick-tables/)

# Filter By IP

```
frontend ....
  acl is-blocked-ip src -f /.../ips.txt
  acl is-blocked-ip src 192.168.2.1
  http-request deny if is-blocked-ip
  
ips.txt
a.b.c.d
192.168.1.0/24

```

