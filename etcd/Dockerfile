FROM        microbox/scratch

ADD         etcd        /bin/etcd
ADD         etcdctl     /bin/etcdctl

VOLUME ["/data"]

EXPOSE 2379 4001

ENTRYPOINT ["/bin/etcd"]

CMD ["-data-dir=/data", "-listen-client-urls=http://0.0.0.0:2379,http://0.0.0.0:4001", "-advertise-client-urls=http://127.0.0.1:2379,http://127.0.0.1:4001"]
