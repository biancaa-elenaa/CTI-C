#!/usr/bin/bash

#se dau 3 argumente in ln 3 + 5 de ex, trb sa se realizeze operatia celui de al dilea operator

#verificam daca avem numarul corect de argumente

if [ "$#" -ne 3 ];then  #pentru inmultire folosim \* - ptc * inseamna altceva
    echo "Utilizare: $0 <operand1> <operator> <operand2>"
fi

#verificam operatorul
if [[ ! "+-/ *" =~ "$2" ]]; then
    echo "Operator invalid"
fi


#if [ "$2" = "+" ]; then
 #   rez=$(($1 + $3))
#elif [ "$2" = "-" ]; then
#    rez=`expr $1 - $3`
#elif [ "$2" = "*" ]; then
#    rez=$(($1 * $3))
#elif [ "$3" -eq 0 ]; then
#   echo "Eroare! Impartirea la 0 nu se poate!"
#    exit 1
#else
#    rez=$(($1 / $3))
#fi


case $2 in
    "+") rez=$(($1 + $3)) ;;
    "-") rez=$(($1 - $3)) ;;
    "*") rez=$(($1 * $3)) ;;
    "/") 
        if [ "$3" -eq 0 ]; then
            echo "Eroare! Impartirea la 0 nu se poate!"
            exit 1
        fi
        rez=$(($1 / $3));;
esac
        

echo "Rezultatul este: $rez"