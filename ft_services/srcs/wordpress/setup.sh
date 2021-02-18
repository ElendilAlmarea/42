#!/bin/sh

mv /wordpress/* /www && chmod -R 775 /www

# wordpress database creation
sleep 20
MYSQL="mysql -h 172.17.0.2 -u root"

if ! $MYSQL -e 'use wordpress'
then
  $MYSQL -e 'CREATE DATABASE wordpress;'
  $MYSQL wordpress < /wpconfig.sql
fi

# starting telegraf and php server
#telegraf &
php -S 0.0.0.0:5050 -t /www
