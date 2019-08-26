server = true
bootstrap_expect = 1
ui = true
datacenter = "<dc_changeme>"
data_dir = "/opt/consul"
#encrypt = "change_me=="
retry_join = ["external_ip_address"]
performance {
  raft_multiplier = 1
}
verify_incoming = false
verify_outgoing = false
verify_server_hostname = false
#ca_file = "/etc/consul.d/ca.crt"
#cert_file = "/etc/consul.d/ssl.crt"
#key_file = "/etc/consul.d/ssl.key"
ports {
  http = 8501
# https = -1
  
}
