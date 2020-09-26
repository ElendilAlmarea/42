#!/bin/sh

mv /wordpress/* /www && chmod -R 775 /www

# wordpress database creation
sleep 20
MYSQL="mysql -h mysql -u root"

if ! $MYSQL -e 'use wordpress'
then
  $MYSQL -e 'CREATE DATABASE wordpress;'
  $MYSQL wordpress < /wordpressconf.sql
fi

# starting telegraf and php server
telegraf &
php -S 0.0.0.0:5050 -t /www
