* [filter_by_ip](#filter)

# filter
** Filter By IP **
```
frontend ....
  acl is-blocked-ip src -f /.../ips.txt
  http-request deny if is-blocked-ip
  
ips.txt
a.b.c.d  
```

