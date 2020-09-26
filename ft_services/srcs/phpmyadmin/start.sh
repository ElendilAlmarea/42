#!/bin/bash
sleep 10
mv /usr/share/webapps/phpmyadmin/* /www/
chmod -R 775 /www
telegraf &
php -S 0.0.0.0:5000 -t /www
