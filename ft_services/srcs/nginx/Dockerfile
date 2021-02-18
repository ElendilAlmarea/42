FROM alpine

RUN apk update \
&& apk add bash sed

# nginx setup
RUN apk add nginx \
&& adduser -D -g 'www' www \
&& mkdir /www \
&& chown -R www:www /var/lib/nginx \
&& mkdir /run/nginx
COPY nginx.conf /etc/nginx/nginx.conf

# ssl setup
RUN apk add openssl \
&& touch /etc/nginx/openssl.cnf \
&& cp /etc/ssl/openssl.cnf /etc/nginx/openssl.cnf \
&& mkdir -p /etc/ssl/private \
&& mkdir -p /etc/ssl/certs \
&& rm -rf /var/cache/apk/* \
&& openssl req \
  -x509 -nodes -days 3650 -newkey rsa:2048 \
  -subj "/CN=192.168.99.111" \
  -config /etc/nginx/openssl.cnf \
  -keyout /etc/ssl/private/self-signed.key \
  -out /etc/ssl/certs/self-signed.crt

#ssh setup
RUN apk add openssh \
&& echo "www:www" | chpasswd \
&& echo "I may have changed this message by editing /etc/motd" > /etc/motd \
&& ssh-keygen -A

#telegraf setup
# RUN mkdir /etc/telegraf \
# && wget https://dl.influxdata.com/telegraf/releases/telegraf-1.13.3-static_linux_amd64.tar.gz \
# && tar -C . -xzf telegraf-1.13.3-static_linux_amd64.tar.gz \
# && chmod 775 telegraf/* \
# && cp telegraf/telegraf /usr/bin/ \
# && rm -rf /var/cache/apk/*
# COPY telegraf.conf /etc/telegraf/telegraf.conf

COPY start.sh /
COPY livenessProbe.sh /

CMD bash /start.sh
