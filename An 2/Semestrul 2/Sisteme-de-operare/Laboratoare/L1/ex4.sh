#!/usr/bin/bash

# se citesc <director> <caracter>(r,w,x)

if [ "$#" -ne 2 ]; then
    echo "Ulilizare: $0 <director> <caracter>"
    exit 1
fi

director=$1
caracter=$2

if [ ! -d "$director" ]; then
    echo "Directorul NU EXISTA"
    exit 1
fi

case "$caracter" in
    r) chmod_mode="u+r" ;;
    w) chmod_mode="u+w" ;;
    x) chmod_mode="u+x" ;;
    *) echo "Eroare"; exit 1 ;;
esac

find "$director" -type f -name "*.txt" -exec chmod $chmod_mode {} +

echo "Permisiunea '$mode' a fost setata pentru toate fisierele .txt din $director"
