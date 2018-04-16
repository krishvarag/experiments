
[kubeadm-dind-cluster] (https://github.com/Mirantis/kubeadm-dind-cluster)
[Local Dashboard] (http://localhost:8080/api/v1/namespaces/kube-system/services/kubernetes-dashboard:/proxy)
```
./dind-cluster-v1.9.sh  up


Digest: sha256:9038dbdf67769ad5f18794e4c95f0e0dcac86a82b19c7f6694bfb952f1465070
Status: Downloaded newer image for mirantis/kubeadm-dind-cluster:v1.9
* Starting DIND container: kube-master
* Running kubeadm: init --config /etc/kubeadm.conf --skip-preflight-checks
Initializing machine ID from random generator.
Synchronizing state of docker.service with SysV init with /lib/systemd/systemd-sysv-install...
Executing /lib/systemd/systemd-sysv-install enable docker
Loaded image: gcr.io/google_containers/pause-amd64:3.0
Loaded image: mirantis/hypokube:base
Loaded image: gcr.io/google_containers/kube-discovery-amd64:1.0
Loaded image: gcr.io/google_containers/kubedns-amd64:1.7
Loaded image: gcr.io/google_containers/kube-dnsmasq-amd64:1.3
Loaded image: gcr.io/google_containers/etcd:2.2.1
Loaded image: gcr.io/google_containers/etcd-amd64:3.0.17
Loaded image: gcr.io/google_containers/exechealthz-amd64:1.1
Loaded image: gcr.io/google_containers/etcd-amd64:2.2.5
real	0m29.647s
user	0m1.177s
sys	0m1.223s
Sending build context to Docker daemon 252.6 MB
Step 1 : FROM mirantis/hypokube:base
 ---> 007709a1e7c2
Step 2 : COPY hyperkube /hyperkube
 ---> 5ee43a630225
Removing intermediate container f7de51dffcf1
Successfully built 5ee43a630225
Created symlink from /etc/systemd/system/multi-user.target.wants/kubelet.service to /lib/systemd/system/kubelet.service.
Flag --skip-preflight-checks has been deprecated, it is now equivalent to --ignore-preflight-errors=all
[init] Using Kubernetes version: v1.9.0
[init] Using Authorization modes: [Node RBAC]
[preflight] Running pre-flight checks.
	[WARNING FileContent--proc-sys-net-bridge-bridge-nf-call-iptables]: /proc/sys/net/bridge/bridge-nf-call-iptables does not exist
	[WARNING Swap]: running with swap on is not supported. Please disable swap
	[WARNING FileExisting-crictl]: crictl not found in system path
[certificates] Generated ca certificate and key.
[certificates] Generated apiserver certificate and key.
[certificates] apiserver serving cert is signed for DNS names [kube-master kubernetes kubernetes.default kubernetes.default.svc kubernetes.default.svc.cluster.local] and IPs [10.96.0.1 10.192.0.2]
[certificates] Generated apiserver-kubelet-client certificate and key.
[certificates] Generated sa key and public key.
[certificates] Generated front-proxy-ca certificate and key.
[certificates] Generated front-proxy-client certificate and key.
[certificates] Valid certificates and keys now exist in "/etc/kubernetes/pki"
[kubeconfig] Wrote KubeConfig file to disk: "admin.conf"
[kubeconfig] Wrote KubeConfig file to disk: "kubelet.conf"
[kubeconfig] Wrote KubeConfig file to disk: "controller-manager.conf"
[kubeconfig] Wrote KubeConfig file to disk: "scheduler.conf"
[controlplane] Wrote Static Pod manifest for component kube-apiserver to "/etc/kubernetes/manifests/kube-apiserver.yaml"
[controlplane] Wrote Static Pod manifest for component kube-controller-manager to "/etc/kubernetes/manifests/kube-controller-manager.yaml"
[controlplane] Wrote Static Pod manifest for component kube-scheduler to "/etc/kubernetes/manifests/kube-scheduler.yaml"
[etcd] Wrote Static Pod manifest for a local etcd instance to "/etc/kubernetes/manifests/etcd.yaml"
[init] Waiting for the kubelet to boot up the control plane as Static Pods from directory "/etc/kubernetes/manifests".
[init] This might take a minute or longer if the control plane images have to be pulled.
[apiclient] All control plane components are healthy after 35.503302 seconds
[uploadconfig] Storing the configuration used in ConfigMap "kubeadm-config" in the "kube-system" Namespace
[markmaster] Will mark node kube-master as master by adding a label and a taint
[markmaster] Master kube-master tainted and labelled with key/value: node-role.kubernetes.io/master=""
[bootstraptoken] Using token: dc1cfc.791408f18c82e44f
[bootstraptoken] Configured RBAC rules to allow Node Bootstrap tokens to post CSRs in order for nodes to get long term certificate credentials
[bootstraptoken] Configured RBAC rules to allow the csrapprover controller automatically approve CSRs from a Node Bootstrap Token
[bootstraptoken] Configured RBAC rules to allow certificate rotation for all node client certificates in the cluster
[bootstraptoken] Creating the "cluster-info" ConfigMap in the "kube-public" namespace
[addons] Applied essential addon: kube-dns
[addons] Applied essential addon: kube-proxy

Your Kubernetes master has initialized successfully!

To start using your cluster, you need to run the following as a regular user:

  mkdir -p $HOME/.kube
  sudo cp -i /etc/kubernetes/admin.conf $HOME/.kube/config
  sudo chown $(id -u):$(id -g) $HOME/.kube/config

You should now deploy a pod network to the cluster.
Run "kubectl apply -f [podnetwork].yaml" with one of the options listed at:
  https://kubernetes.io/docs/concepts/cluster-administration/addons/

You can now join any number of machines by running the following on each node
as root:

  kubeadm join --token dc1cfc.791408f18c82e44f 10.192.0.2:6443 --discovery-token-ca-cert-hash sha256:d01b604823cfe71ec0f000cf013a2afedfa4c39d5441c53e4e5bf34b11a15713


real	0m43.860s
user	0m5.386s
sys	0m0.155s
Warning: kubectl apply should be used on resource created by either kubectl create --save-config or kubectl apply
configmap "kube-proxy" configured
Warning: kubectl apply should be used on resource created by either kubectl create --save-config or kubectl apply
daemonset "kube-proxy" configured
No resources found
* Setting cluster config 
Cluster "dind" set.
Context "dind" modified.
Switched to context "dind".
* Starting node container: 1
* Starting DIND container: kube-node-1
* Node container started: 1
* Starting node container: 2
* Starting DIND container: kube-node-2
* Node container started: 2
* Joining node: 1
* Joining node: 2
* Running kubeadm: join --skip-preflight-checks --token dc1cfc.791408f18c82e44f 10.192.0.2:6443 --discovery-token-ca-cert-hash sha256:d01b604823cfe71ec0f000cf013a2afedfa4c39d5441c53e4e5bf34b11a15713
Initializing machine ID from random generator.
* Running kubeadm: join --skip-preflight-checks --token dc1cfc.791408f18c82e44f 10.192.0.2:6443 --discovery-token-ca-cert-hash sha256:d01b604823cfe71ec0f000cf013a2afedfa4c39d5441c53e4e5bf34b11a15713
Initializing machine ID from random generator.
Synchronizing state of docker.service with SysV init with /lib/systemd/systemd-sysv-install...
Executing /lib/systemd/systemd-sysv-install enable docker
Synchronizing state of docker.service with SysV init with /lib/systemd/systemd-sysv-install...
Executing /lib/systemd/systemd-sysv-install enable docker
Loaded image: gcr.io/google_containers/pause-amd64:3.0
Loaded image: mirantis/hypokube:base
Loaded image: gcr.io/google_containers/kube-discovery-amd64:1.0
Loaded image: gcr.io/google_containers/kubedns-amd64:1.7
Loaded image: gcr.io/google_containers/kube-dnsmasq-amd64:1.3
Loaded image: gcr.io/google_containers/etcd:2.2.1
Loaded image: gcr.io/google_containers/etcd-amd64:3.0.17
Loaded image: gcr.io/google_containers/exechealthz-amd64:1.1
Loaded image: gcr.io/google_containers/etcd-amd64:2.2.5

real	0m39.784s
user	0m1.200s
sys	0m1.282s
Loaded image: gcr.io/google_containers/pause-amd64:3.0
Loaded image: mirantis/hypokube:base
Loaded image: gcr.io/google_containers/kube-discovery-amd64:1.0
Loaded image: gcr.io/google_containers/kubedns-amd64:1.7
Loaded image: gcr.io/google_containers/kube-dnsmasq-amd64:1.3
Loaded image: gcr.io/google_containers/etcd:2.2.1
Loaded image: gcr.io/google_containers/etcd-amd64:3.0.17
Loaded image: gcr.io/google_containers/exechealthz-amd64:1.1
Loaded image: gcr.io/google_containers/etcd-amd64:2.2.5

real	0m40.294s
user	0m1.209s
sys	0m1.255s
Sending build context to Docker daemon 252.6 MB
Step 1 : FROM mirantis/hypokube:baseon 206.1 MB
 ---> 007709a1e7c2
Step 2 : COPY hyperkube /hyperkube
Sending build context to Docker daemon 252.6 MB
Step 1 : FROM mirantis/hypokube:base
 ---> 007709a1e7c2
Step 2 : COPY hyperkube /hyperkube
 ---> d80ae42d40cb
Removing intermediate container 325b2290db09
Successfully built d80ae42d40cb
 ---> 6a40293eb4ca
Removing intermediate container 46e4b8202a33
Successfully built 6a40293eb4ca
Created symlink from /etc/systemd/system/multi-user.target.wants/kubelet.service to /lib/systemd/system/kubelet.service.
Flag --skip-preflight-checks has been deprecated, it is now equivalent to --ignore-preflight-errors=all
[preflight] Running pre-flight checks.
Created symlink from /etc/systemd/system/multi-user.target.wants/kubelet.service to /lib/systemd/system/kubelet.service.
Flag --skip-preflight-checks has been deprecated, it is now equivalent to --ignore-preflight-errors=all
[preflight] Running pre-flight checks.
	[WARNING FileContent--proc-sys-net-bridge-bridge-nf-call-iptables]: /proc/sys/net/bridge/bridge-nf-call-iptables does not exist
	[WARNING Swap]: running with swap on is not supported. Please disable swap
	[WARNING FileExisting-crictl]: crictl not found in system path
[discovery] Trying to connect to API Server "10.192.0.2:6443"
[discovery] Created cluster-info discovery client, requesting info from "https://10.192.0.2:6443"
[discovery] Requesting info from "https://10.192.0.2:6443" again to validate TLS against the pinned public key
[discovery] Cluster info signature and contents are valid and TLS certificate validates against pinned roots, will use API Server "10.192.0.2:6443"
[discovery] Successfully established connection with API Server "10.192.0.2:6443"

This node has joined the cluster:
* Certificate signing request was sent to master and a response
  was received.
* The Kubelet was informed of the new secure connection details.

Run 'kubectl get nodes' on the master to see this node join the cluster.

real	0m0.768s
user	0m0.464s
sys	0m0.137s
* Node joined: 2
	[WARNING FileContent--proc-sys-net-bridge-bridge-nf-call-iptables]: /proc/sys/net/bridge/bridge-nf-call-iptables does not exist
	[WARNING Swap]: running with swap on is not supported. Please disable swap
	[WARNING FileExisting-crictl]: crictl not found in system path
[discovery] Trying to connect to API Server "10.192.0.2:6443"
[discovery] Created cluster-info discovery client, requesting info from "https://10.192.0.2:6443"
[discovery] Requesting info from "https://10.192.0.2:6443" again to validate TLS against the pinned public key
[discovery] Cluster info signature and contents are valid and TLS certificate validates against pinned roots, will use API Server "10.192.0.2:6443"
[discovery] Successfully established connection with API Server "10.192.0.2:6443"

This node has joined the cluster:
* Certificate signing request was sent to master and a response
  was received.
* The Kubelet was informed of the new secure connection details.

Run 'kubectl get nodes' on the master to see this node join the cluster.

real	0m0.574s
user	0m0.433s
sys	0m0.150s
* Node joined: 1
* Deploying k8s dashboard 
deployment "kubernetes-dashboard" created
service "kubernetes-dashboard" created
clusterrolebinding "add-on-cluster-admin" created
* Patching kube-dns deployment to make it start faster 
Warning: kubectl apply should be used on resource created by either kubectl create --save-config or kubectl apply
deployment "kube-dns" configured
* Taking snapshot of the cluster 
Error from server (NotFound): deployments.extensions "coredns" not found
deployment "kube-dns" scaled
deployment "kubernetes-dashboard" scaled
pod "kube-proxy-77q5p" deleted
pod "kube-proxy-rv629" deleted
pod "kube-proxy-xbgz2" deleted
NAME                         READY     STATUS        RESTARTS   AGE
etcd-kube-master             1/1       Running       0          1m
kube-apiserver-kube-master   1/1       Running       0          2m
kube-dns-6f4fd4bdf-mb2ft     3/3       Terminating   0          1m
kube-scheduler-kube-master   1/1       Running       0          2m
* Waiting for kube-proxy and the nodes 
............[done]
* Bringing up kube-dns and kubernetes-dashboard 
deployment "kube-dns" scaled
deployment "kubernetes-dashboard" scaled
...............[done]
NAME          STATUS    ROLES     AGE       VERSION
kube-master   Ready     master    4m        v1.9.6
kube-node-1   Ready     <none>    1m        v1.9.6
kube-node-2   Ready     <none>    1m        v1.9.6
* Access dashboard at: http://localhost:8080/api/v1/namespaces/kube-system/services/kubernetes-dashboard:/proxy

$kubectl get nodes
NAME          STATUS    ROLES     AGE       VERSION
kube-master   Ready     master    6m        v1.9.6
kube-node-1   Ready     <none>    3m        v1.9.6
kube-node-2   Ready     <none>    3m        v1.9.6

$docker ps -a
CONTAINER ID        IMAGE                                COMMAND                  CREATED             STATUS              PORTS                      NAMES
9753e99af10c        mirantis/kubeadm-dind-cluster:v1.9   "/sbin/dind_init sys…"   3 minutes ago       Up 3 minutes        8080/tcp                   kube-node-2
b519ceb322a5        mirantis/kubeadm-dind-cluster:v1.9   "/sbin/dind_init sys…"   3 minutes ago       Up 3 minutes        8080/tcp                   kube-node-1
bcf37bcb4e51        mirantis/kubeadm-dind-cluster:v1.9   "/sbin/dind_init sys…"   3 minutes ago       Up 3 minutes        127.0.0.1:8080->8080/tcp   kube-master

$docker images
REPOSITORY                      TAG                 IMAGE ID            CREATED             SIZE
mirantis/kubeadm-dind-cluster   v1.9                b92724d95140        6 days ago          1.38GB

# inspect mster
docker exec -it 63c876146b29 bash

$docker exec  b519ceb322a5 systemctl status kubelet
$docker exec  bcf37bcb4e51 cat /etc/kubernetes/kubelet.conf
# check Linux image used
docker exec  bcf37bcb4e51    cat  /etc/*release
# Ubuntu image ( MASTER /HEAD)
docker exec  bcf37bcb4e51    cat   /lib/systemd/system/kubelet.service
$docker exec  bcf37bcb4e51   ls -l   /etc/kubernetes/
total 40
-rw-------. 1 root root 5450 Apr 16 00:07 admin.conf
-rw-------. 1 root root 5486 Apr 16 00:07 controller-manager.conf
-rw-------. 1 root root 5486 Apr 16 00:07 kubelet.conf
drwxr-xr-x. 2 root root 4096 Apr 16 01:33 manifests
drwxr-xr-x. 2 root root 4096 Apr 16 01:33 pki
-rw-------. 1 root root 5430 Apr 16 00:07 scheduler.conf


docker exec  bcf37bcb4e51    ls  -l /etc/kubernetes/manifests
docker exec  bcf37bcb4e51    ls  -l /etc/kubernetes/manifests
total 16
-rwx------. 1 root root  876 Apr 16 00:07 etcd.yaml
-rwx------. 1 root root 2872 Apr 16 00:08 kube-apiserver.yaml
-rwx------. 1 root root 2135 Apr 16 00:08 kube-controller-manager.yaml
-rwx------. 1 root root 1399 Apr 16 00:08 kube-scheduler.yaml

ETCD :image: gcr.io/google_containers/etcd-amd64:3.1.11
$docker exec  bcf37bcb4e51   kubectl get pods --all-namespaces
# (WORKER)
$docker exec  b519ceb322a5   ls -l   /etc/kubernetes/
-rw-------. 1 root root 1781 Apr 16 00:10 bootstrap-kubelet.conf
-rw-------. 1 root root 1835 Apr 16 00:10 kubelet.conf
drwxr-xr-x. 2 root root   20 Apr 16 01:33 pki


```
