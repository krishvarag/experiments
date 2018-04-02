 docker build -t etcd:v1 .
docker run -d  -p 2379:2379 -p 4001:4001 --name etcd etcd:v1 
docker ps -a
docker logs etcd
./etcdctl   mk key1 "SRI RAM "
./etcdctl  ls /
curl -L http://localhost:2379/v2/keys/key2  -XPUT -d value="from curl ..."
