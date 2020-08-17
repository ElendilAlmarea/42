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

#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
#kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

MINIKUBE_IP=$(minikube ip)

#cp srcs/wordpress/wpconfig.sql srcs/wordpress/wpconfig-target.sql
#sed -i '' "s/##MINIKUBE_IP##/$MINIKUBE_IP/g" srcs/wordpress/wpconfig-target.sql
#cp srcs/ftps/entrypoint srcs/ftps/entrypoint-target
#sed -i '' "s/##MINIKUBE_IP##/$MINIKUBE_IP/g" srcs/ftps/entrypoint-target
#cp srcs/metallb.yaml srcs/metallb-target.yaml
#sed -i '' "s/##MINIKUBE_IP##/$MINIKUBE_IP/g" srcs/metallb.yaml

eval $(minikube docker-env)
docker build -t nginx_alpine srcs/nginx
#docker build -t mysql_alpine srcs/mysql
#docker build -t wordpress_alpine srcs/wordpress
#docker build -t ftps_alpine srcs/ftps

if [ "$1" = "delete" ]
then
	kubectl delete -k srcs
else
	kubectl apply -k srcs
fi

#minikube dashboard
