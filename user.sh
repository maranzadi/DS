#!/bin/bash

partekatu=$1
horain=$(pwd)
ip=$2

while true; do

  rm -rf $partekatu
  cp -r $horain

  wget $2

  sleep 5
done
