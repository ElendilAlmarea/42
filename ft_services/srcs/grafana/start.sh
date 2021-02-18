#!/bin/bash
telegraf &
sleep 5
/usr/sbin/grafana-server web
