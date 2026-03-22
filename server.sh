#/bin/bash

carpeta=$1

hash=1

while [[ 1=1 ]]; do
  
  newHash=  find $carpeta -type f -print0 | sort -z | xargs -0 shasum -a 256 | shasum -a 256
  if [[ hash !=newHash ]]; then
    
    rm -rf /ds/$carpeta

    cp $carpeta /ds
    cd /ds/$carpeta
    make
  fi
done

