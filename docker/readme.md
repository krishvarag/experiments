
[Setup_Private_Docker_registry] (https://www.digitalocean.com/community/tutorials/how-to-set-up-a-private-docker-registry-on-ubuntu-14-04)

[Linux_Config: how-to-run-your-own-local-private-docker-registry ] (https://linuxconfig.org/how-to-run-your-own-local-private-docker-registry)
```
docker run -d -p 5000:5000 registry
docker tag  faaadb4aaf9b localhost:5000/node:6.9.2
docker push localhost:5000/node:6.9.2
curl http://localhost:5000/v2/_catalog
curl http://localhost:5000/v2/node/tags/list
curl -X DELETE localhost:5000/v1/repositories/node/tags/6.9.2

docker tag eb0012d55845 localhost:5000/hello-node:v1
docker push localhost:5000/hello-node:v1


```
## Commands
```
# delete not running containers
docker ps -a | grep Exit | awk '{print  $1 }' | xargs docker rm

```
