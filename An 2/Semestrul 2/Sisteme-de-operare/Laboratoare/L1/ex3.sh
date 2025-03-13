#!/usr/bin/bash

#in functie de ora curenta sa se zica buna ziua/seara  

username=$(whoami)

#obtinem ora curenta in format 24h

current_hour=$(date +"%H")

if [ "$current_hour" -ge 6 ] && [ "$current_hour" -lt 12 ]; then
    msg="Buna dimineata, "
elif [ "$current_hour" -ge 12 ] && [ "$current_hour" -lt 18 ]; then
    msg="Buna ziua, "
elif [ "$current_hour" -ge 18 ] && [ "$current_hour" -lt 22 ]; then
    msg="Buna seara, "
else 
    msg="Noapte buna, "
fi

echo "$msg $username"
