FROM alpine

WORKDIR /usr/share/grafana

RUN apk update && apk add bash curl wget grafana \
--repository http://dl-cdn.alpinelinux.org/alpine/edge/testing/ \
&& rm -rf /var/cache/apk/*

COPY datasources/datasource.yaml /usr/share/grafana/conf/provisioning/datasources/

RUN mkdir /usr/share/grafana/conf/provisioning/dashboards/mine
COPY dashboards/mine/*.json /usr/share/grafana/conf/provisioning/dashboards/mine/
COPY dashboards/sample.yaml /usr/share/grafana/conf/provisioning/dashboards/

#telegraf setup
RUN mkdir /etc/telegraf \
&& wget https://dl.influxdata.com/telegraf/releases/telegraf-1.13.3-static_linux_amd64.tar.gz \
&& tar -C . -xzf telegraf-1.13.3-static_linux_amd64.tar.gz \
&& chmod 775 telegraf/* \
&& cp telegraf/telegraf /usr/bin/ \
&& rm -rf /var/cache/apk/*
COPY telegraf.conf /etc/telegraf/telegraf.conf

COPY start.sh /
EXPOSE 3000

CMD bash /start.sh
