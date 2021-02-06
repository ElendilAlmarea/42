FROM alpine

ENV MYSQL_VERSION=10.3.15-r0

RUN apk add --no-cache mysql mysql-client mariadb-server-utils bash && \
	mkdir /scripts && \
	rm -rf /var/cache/apk/*

COPY ./start.sh /scripts/start.sh
COPY mysql.conf /etc/mysql/
RUN chmod +x /scripts/start.sh

#telegraf setup
RUN mkdir /etc/telegraf \
&& wget https://dl.influxdata.com/telegraf/releases/telegraf-1.13.3-static_linux_amd64.tar.gz \
&& tar -C . -xzf telegraf-1.13.3-static_linux_amd64.tar.gz \
&& chmod 775 telegraf/* \
&& cp telegraf/telegraf /usr/bin/ \
&& rm -rf /var/cache/apk/*
COPY telegraf.conf /etc/telegraf/telegraf.conf

#VOLUME ["/var/lib/mysql"]

ENTRYPOINT ["/scripts/start.sh"]
