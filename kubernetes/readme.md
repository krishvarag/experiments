
#  kubeadm-dind-cluster
* [https://github.com/Mirantis/kubeadm-dind-cluster](https://github.com/Mirantis/kubeadm-dind-cluster)
* DIND 
 [Docker In Docker](https://hub.docker.com/_/docker/)
 [https://github.com/jpetazzo/dind](https://github.com/jpetazzo/dind)
 ```
cd dind/
docker build -t dind .
docker pull dind
docker pull docker:dind
docker run --privileged -d docker:dind
docker ps -a
docker logs thirsty_joliot
docker stop thirsty_joliot
docker rm thirsty_joliot
```

* dind-cluster
```
wget https://cdn.rawgit.com/Mirantis/kubeadm-dind-cluster/master/fixed/dind-cluster-v1.9.sh
chmod +x dind-cluster-v1.9.sh 
kubectl nodes
./dind-cluster-v1.9.sh  up
kubectl
kubectl get nodes
./dind-cluster-v1.9.sh  down

```
