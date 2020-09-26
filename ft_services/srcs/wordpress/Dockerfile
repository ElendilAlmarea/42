FROM alpine

RUN apk add bash gettext wget curl mysql-client

#php setup
RUN apk add php7 php7-common php7-fpm php7-opcache php7-gd php7-mysqli \
php7-zlib php7-curl php7-mbstring php7-json php7-session php7-phar php7-cli \
php7-zip php7-iconv php7-xml php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql \
php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom

#wordpress setup
RUN wget https://wordpress.org/latest.tar.gz -P /tmp \
&& mkdir -p /wordpress /run/php-fpm7 /www \
&& tar xzf /tmp/latest.tar.gz --strip-components=1 -C /wordpress \
&& sed -i -e 's/9000/5050/g' /etc/php7/php-fpm.d/www.conf \
&& rm -rf /etc/php7/php-fpm.d/www.conf-e /var/cache/apk/*
COPY wp-config.php /wordpress
COPY setup.sh /
RUN chmod -R 775 /wordpress && chmod 775 setup.sh
COPY wordpressconf.sql /


#telegraf setup
RUN mkdir /etc/telegraf \
&& wget https://dl.influxdata.com/telegraf/releases/telegraf-1.13.3-static_linux_amd64.tar.gz \
&& tar -C . -xzf telegraf-1.13.3-static_linux_amd64.tar.gz \
&& chmod 775 telegraf/* \
&& cp telegraf/telegraf /usr/bin/ \
&& rm -rf /var/cache/apk/*
COPY telegraf.conf /etc/telegraf/telegraf.conf

CMD sh /setup.sh
