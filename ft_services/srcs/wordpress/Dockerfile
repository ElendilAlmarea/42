FROM alpine

RUN apk update && \
	apk add nginx mysql-client

COPY nginx.conf /etc/nginx/nginx.conf
COPY wpconfig-target.sql /wpconfig.sql
COPY entrypoint /entrypoint

ENTRYPOINT sh /entrypoint