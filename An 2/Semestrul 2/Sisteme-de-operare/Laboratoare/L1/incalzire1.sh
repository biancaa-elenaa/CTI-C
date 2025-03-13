#!/bin/bash

#fisier
#citim numele de la tastatura, read ...fisier
#daca exista sortarw
#daca nu exista => eroare
# la sortare folosim $fisier

#read fisier #daca citim cu read executam comenzile pe rand fara |

if [ "$1" -gt "$2" ] && [ "$1" -gt "$3" ]; then ##cand citim din linie de comanda chmod +x lab2.sh | ./lab2.sh fisier.txt
    echo "$1"
else if [ "$2" -gt "$1" ] && [ "$2" -gt "$3" ]; then
        echo "$2"
    else
        echo "$3"
    fi
fi

