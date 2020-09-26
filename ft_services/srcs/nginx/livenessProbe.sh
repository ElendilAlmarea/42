#!/bin/bash
pidof telegraf
if [[ $? != 0 ]]
then
  exit 1
else
  pidof sshd
  if [[ $? != 0 ]]
  then
    exit 1
  fi
fi
