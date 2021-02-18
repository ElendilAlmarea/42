FROM alpine
RUN apk update && apk upgrade

# php server set up
RUN apk add bash sed php7 php7-fpm mysql mysql-client php7-mysqli \
php7-mcrypt php7-soap php7-openssl php7-gmp php7-pdo_odbc \
php7-json php7-dom php7-pdo php7-zip php7-sqlite3 php7-apcu \
php7-pdo_pgsql php7-bcmath php7-gd php7-odbc php7-pdo_mysql \
php7-pdo_sqlite php7-gettext php7-xmlreader php7-xmlrpc php7-bz2 \
php7-iconv php7-pdo_dblib php7-curl php7-ctype php7-session php7-mbstring
RUN sed -i -e 's/9000/5000/g' /etc/php7/php-fpm.d/www.conf \
&& rm -rf /etc/php7/php-fpm.d/www.conf-e /var/cache/apk/*

# phpmyadmin set up
RUN mkdir /run/php-fpm7 /www /usr/share/webapps\
&& cd /usr/share/webapps \
&& wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.2-all-languages.tar.gz \
&& tar zxvf phpMyAdmin-5.0.2-all-languages.tar.gz \
&& mv phpMyAdmin-5.0.2-all-languages phpmyadmin \
&& rm -rf /var/cache/apk/*
COPY config.inc.php /usr/share/webapps/phpmyadmin/

#telegraf setup
# RUN mkdir /etc/telegraf \
# && wget https://dl.influxdata.com/telegraf/releases/telegraf-1.13.3-static_linux_amd64.tar.gz \
# && tar -C . -xzf telegraf-1.13.3-static_linux_amd64.tar.gz \
# && chmod 775 telegraf/* \
# && cp telegraf/telegraf /usr/bin/ \
# && rm -rf /var/cache/apk/*
# COPY telegraf.conf /etc/telegraf/telegraf.conf

COPY start.sh /

CMD bash /start.sh
