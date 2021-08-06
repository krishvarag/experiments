* [Filter By IP](#filter-by-ip)
* [Stick Tables](https://www.haproxy.com/blog/introduction-to-haproxy-stick-tables/)
* [Rate Limit](https://www.haproxy.com/blog/four-examples-of-haproxy-rate-limiting/)
* [Logging](#logging)
# Filter By IP

```
frontend ....
  acl is-blocked-ip src -f /.../ips.txt
  acl is-blocked-ip src 192.168.2.1
  http-request deny if is-blocked-ip
  # Block using anonymous or in-line ACL.
  #prevent any client in the 10.0.0.0/16 subnet from accessing
  http-request deny if { path -i -m beg /sensitive_data/ } { src 10.0.0.0/16 }
  # Allow only these ips to acees
  http-request deny if { path -i -m beg /sensitive_data/ } !{ src 10.0.0.0/16 }
ips.txt
a.b.c.d
192.168.1.0/24

```

# Logging
* [Intro](https://www.haproxy.com/blog/introduction-to-haproxy-logging/)
* [LogFormat](https://www.haproxy.com/documentation/hapee/latest/onepage/#8.2.3)
* Display  backend stats 
```
cat ha.log | halog -srv -H
#srv_name       1xx  2xx    3xx  4xx  5xx  other  tot_req  req_ok  pct_ok  avg_ct  avg_rt
```
* Display  URL  stats
```
cat ha.log |  halog -ut -H
#req   err  ttot      tavg   oktot     okavg  bavg    btot       src
requests
errors, 
Total computation time
Average computation time
Total computation time of successful requests
Average computation time of successful requests
Average bytes sent
Total bytes sent
Request URL
```
