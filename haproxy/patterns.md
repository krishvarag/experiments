* [Filter By IP](#filter-by-ip)
* [Stick Tables](https://www.haproxy.com/blog/introduction-to-haproxy-stick-tables/)

# Filter By IP

```
frontend ....
  acl is-blocked-ip src -f /.../ips.txt
  acl is-blocked-ip src 192.168.2.1
  http-request deny if is-blocked-ip
  # Block using anonymous or in-line ACL.
  http-request deny if { path -i -m beg /sensitive_data/ } { src 10.0.0.0/16 }
  
ips.txt
a.b.c.d
192.168.1.0/24

```

