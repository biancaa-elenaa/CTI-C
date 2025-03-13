let distincte a b c= if a=b && a=c then Printf.printf "Toate argumentele sunt egale"
                      else if a=b && b<>c then Printf.printf "Argumentele 1 si 2 sunt egale"
                      else if a=c && b<>c then Printf.printf "Argumentele 1 si 2 sunt egale"
                      else if b=c && a<>c then Printf.printf "Argumentele 2 si 3 sunt egale"
                      else Printf.printf "Toate argumentele sunt distincte";;
distincte 2 2 2;;