#!/usr/bin/bash

# 3 numere ca argumente in lc si afiseaza pe cel mai mare
#verificam ca avem un numar bun de argumente

if [ "$#" -ne 3 ]; then
    echo "Utilizare: $0 <nr1> <nr2> <nr3>"
    exit 1
fi

#cu if-uri

#if [ $1 -gt $2 ] && [ $1 -gt $3 ]; then
#    echo "$1"
#else if [ $2 -gt $1 ] && [ $2 -gt $3 ]; then
#    echo "$2"
#    else
#        echo "$3"
#    fi
#fi


#cu for

max=$1
for n in "$@"; do
    if [ "$n" -gt "$max" ]; then
        max=$n;
    fi
done

echo "$max"
