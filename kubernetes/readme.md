## Kubernetes
* [getting-started-guides/docker.html] [http://jeffmendoza.github.io/kubernetes/v1.0/docs/getting-started-guides/docker.html]
* [https://kubernetes.io/docs/tutorials/kubernetes-basics/] (https://kubernetes.io/docs/tutorials/kubernetes-basics/)

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
Dashboard:
http://localhost:8080/api/v1/namespaces/kube-system/services/kubernetes-dashboard:/proxy/#!/workload?namespace=default

./dind-cluster-v1.9.sh  down

```
* Deploying nginx app
```
$ kubectl cluster-info
Kubernetes master is running at http://localhost:8080
KubeDNS is running at http://localhost:8080/api/v1/namespaces/kube-system/services/kube-dns:dns/proxy
$ kubectl -s http://localhost:8080 run nginx --image=nginx --port=80
 
docker ps
$ kubectl describe  pods
//will show Ip of pod

$ kubectl get all
// delete deployment
$ kubectl delete deploy/nginx
```
* Build docker image and Deploy
```
- create server.js
- create Dockerfile
- Build docker image 
$docker build -t hello-node:v1 .
$kubectl run hello-node --image=hello-node:v1 --port=8090
$kubegtl get deployments

```
