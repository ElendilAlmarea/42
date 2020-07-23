FROM alpine

RUN apk add --update mysql mysql-client && rm -f /var/cache/apk/*

COPY mysql.conf /etc/mysql/mysql.conf
COPY entrypoint /entrypoint

RUN mkdir /app

CMD sh /entrypoint
