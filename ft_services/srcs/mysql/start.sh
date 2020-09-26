#!/bin/sh

telegraf &

# parameters
MYSQL_ROOT_PWD=${MYSQL_ROOT_PWD:-""}

if [ ! -d "/run/mysqld" ]; then
	mkdir -p /run/mysqld
	chown -R root:root /run/mysqld
fi

	chown -R root:root /var/lib/mysql
  chmod -R 775 /var/lib/mysql

# init database
mysql_install_db --user=root --ldata=/var/lib/mysql > /dev/null

# create temp file
tfile=`mktemp`

	# save sql
cat << EOF > $tfile
CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '';
grant all privileges on *.* to 'root'@'%' identified by '' with grant option;
flush privileges;
EOF

# bootstrap
echo "[i] run tempfile: $tfile"
/usr/bin/mysqld --user=root --bootstrap --verbose=0 --skip-networking=0 --skip-grant-tables=0 < $tfile
rm -f $tfile

echo "[i] Sleeping 5 sec"
sleep 4
exec /usr/bin/mysqld --user=root --console --skip-networking=0 --skip-grant-tables=0
