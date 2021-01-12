#!/bin/sh


if $OSTYPE != "linux-gnu"*
then
	echo "unsupported OS, pls use linux"
fi

if ! which docker >/dev/null
then
	echo "install docker"
	exit 1
fi
if ! which minikube >/dev/null
then
	echo "install minikube"
	exit 1
fi

if ! minikube status >/dev/null
then
	if ! minikube start --vm-driver=docker --bootstrapper=kubeadm
	then
		echo "Couldn't start minikube"
		exit 1
	fi
	minikube addons enable metrics-server
	kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
    kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
    kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
	kubectl delete deployments --all
	kubectl delete svc --all
fi

ftps_ip='172.17.0.12'
grafana_ip='172.17.0.13'
nginx_ip='172.17.0.14'
phpmyadmin_ip='172.17.0.15'
wordpress_ip='172.17.0.16'

eval $(minikube docker-env);

sed -i.backup "s/metallb_ips/$ftps_ip-$wordpress_ip/g" srcs/metallb.yaml
sed -i.backup "s/grafana_ip/$grafana_ip/g" srcs/nginx/nginx.conf
sed -i.trash "s/nginx_ip/$nginx_ip/g" srcs/nginx/nginx.conf
sed -i.trash "s/phpmyadmin_ip/$phpmyadmin_ip/g" srcs/nginx/nginx.conf
sed -i.trash "s/wordpress_ip/$wordpress_ip/g" srcs/nginx/nginx.conf
sed -i.backup "s/wordpress_ip/$wordpress_ip/g" srcs/wordpress/wordpressconf.sql

docker build -t mysql-image srcs/mysql
docker build -t cleaner-image srcs/cleaner
docker build -t nginx-image srcs/nginx
docker build -t phpmyadmin-image srcs/phpmyadmin
docker build -t wordpress-image srcs/wordpress
docker build -t grafana-image srcs/grafana
docker build -t influxdb-image srcs/influxdb
docker build -t ftps-image --build-arg IP=$ftps_ip srcs/ftps
kubectl apply -k srcs

mv srcs/metallb.yaml.backup srcs/metallb.yaml
mv srcs/nginx/nginx.conf.backup srcs/nginx/nginx.conf
mv srcs/wordpress/wordpressconf.sql.backup srcs/wordpress/wordpressconf.sql
rm -rf srcs/nginx/*.trash*

echo "index : http://$nginx_ip"
echo "ssh connection : ssh www@$nginx_ip password: www"
echo "ftp connection : ftpes://$ftps_ip username: www password: www"

minikube dashboard
