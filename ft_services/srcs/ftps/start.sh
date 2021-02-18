#!/bin/bash
telegraf &
{ echo "www"; echo "www"; } | adduser www
echo "FUCK FT_SERVICES" > /home/www/fuck_ft_services
chown -R www /home/www
chmod -R 700 /home/www 
/usr/sbin/pure-ftpd -Y 2 -p 21000:21000 -P $ENV_IP
