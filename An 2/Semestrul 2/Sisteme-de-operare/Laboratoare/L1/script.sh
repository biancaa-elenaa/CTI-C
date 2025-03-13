var1=Cata
var2=ceau
var3=29
var4=29

echo $var1
echo $var2
echo $var3
echo $var4

if test "var1" \< "var2"
then
	echo "$var1 este primul alfabetic"
else
	echo "$var2 este primul alfabetic"
fi

if test "$var3" -eq "$var4"
then
	echo "$var3 = $var4"
fi

n1=$1;
n2=$2;
echo $n1
echo $n2

if test "$n1" -lt "$n2"
then
	echo "$n1 < $n2"
else
	echo "$n1 > $n2"
fi


for arg in "$@"
do
	if test "$arg" -gt 50
	then
		echo "$arg"
	fi
done

if test -L $fisier
then
	echo "legatura simbolica"
fi

functieMax()
{
	var1=$1;
	var2=$2;
	if test "$var1" \> "$var2"
	then
		echo "$var1 e maximul"
	else
		echo "$var2 e maximul"
	fi
}

functieMax 5 6
