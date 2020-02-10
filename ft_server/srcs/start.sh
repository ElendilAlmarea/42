#install most package
apt-get update
apt-get -y upgrade
apt-get -y install nginx
apt-get -y install wget
apt-get -y install curl
apt-get -y install php-{fpm,mbstring,cgi,mysql,curl,gd,intl,mbstring,soap,xml,xmlrpc}
apt-get -y install mariadb-server mariadb-client
apt-get -y install mysql-server

#config phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
tar xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
cp /root/config.inc.php phpMyAdmin-4.9.0.1-all-languages/
mv phpMyAdmin-4.9.0.1-all-languages /var/www/html/phpmyadmin

#config nginx
cd
rm -rf /var/www/html/*.html
rm -rf /etc/nginx/sites-available/default
rm -rf /etc/nginx/sites-enabled/default
cp config /etc/nginx/sites-available/config
ln -s /etc/nginx/sites-available/config /etc/nginx/sites-enabled/

#config mysql
service mysql restart
sleep 5
echo "grant all privileges on *.* to root@localhost;" | mysql -u root
echo "update mysql.user set plugin = 'mysql_native_password' where user = 'root';" | mysql -u root
echo "flush privileges;" | mysql -u root

#config wordpress
service mysql restart
sleep 5
echo "create database wordpress;" | mysql -u root
echo "grant all privileges on */* to root@localhost;" | mysql -u root
echo "flush privileges;" | mysql -u root
wget https://wordpress.org/latest.tar.gz -P /tmp
mkdir /var/www/html/site
chmod 755 /var/www/html/site
tar xzf /tmp/latest.tar.gz --strip-components=1 -C /var/www/html/site/
cp /root/wp-config.php /var/www/html/site/wp-config.php
chown -R root:root /var/www/html/site
mysql wordpress < /root/wordpressconf.sql

#make SSL certif
sh mk_ssl_crt.sh

#start server
service mysql restart
/etc/init.d/php7.3-fpm start
service nginx restart