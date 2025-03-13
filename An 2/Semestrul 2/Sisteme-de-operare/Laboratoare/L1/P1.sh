#!/bin/bash

#fisier
#citim numele de la tastatura, read ...fisier
#daca exista sortarw
#daca nu exista => eroare
# la sortare folosim $fisier

echo "da-mi numele fisierului"

#read fisier #daca citim cu read executam comenzile pe rand fara |

if [ -f "$1" ]; ##cand citim din linie de comanda chmod +x lab2.sh | ./lab2.sh fisier.txt
then
    sort "$1"
    echo "$1"
else
    echo "fisierul nu exista"
fi

