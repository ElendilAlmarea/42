#!/bin/bash
cp /etc/ssl/openssl.cnf /etc/nginx/openssl.cnf
mkdir -p /etc/ssl/private
mkdir -p /etc/ssl/certs
openssl req \
  -x509 -nodes -sha256 -newkey rsa:2048 \
  -subj "/CN=localhost" \
  -config /etc/nginx/openssl.cnf \
  -keyout /etc/ssl/private/self-signed.key \
  -out /etc/ssl/certs/self-signed.crt;