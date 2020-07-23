#!/bin/sh

if ! which docker >/dev/null
then
	brew install docker
fi
if ! which minikube >/dev/null
then
	brew install minikube
fi
if ! minikube status >/dev/null
then
	minikube start --vm-driver=virtualbox --cpus=2 --disk-size=40000mb \
		--memory=3000mb --bootstrapper=kubeadm
	minikube addons enable metrics-server
	minikube addons enable dashboard
fi

MINIKUBE_IP=$(minikube ip)

cp srcs/wordpress/wpconfig.sql srcs/wordpress/wpconfig_tmp.sql
sed -i '' "s/MINIKUBE_IP/$MINIKUBE_IP/g" srcs/wordpress/wpconfig_tmp.sql

eval $(minikube docker-env)
docker build -t nginx_alpine srcs/nginx
docker build -t mysql_alpine srcs/mysql
docker build -t wordpress_alpine srcs/wordpress

if [ "$1" = "delete" ]
then
	kubectl delete -k srcs
else
	kubectl apply -k srcs
fi

#minikube dashboard
