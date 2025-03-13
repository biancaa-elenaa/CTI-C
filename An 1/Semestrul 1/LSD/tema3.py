#ex4
#b)
def nr_cifre(n):
    if(n<10):
        return 1
    else:
        return 1+nr_cifre(n//10)


#c)
def cifra_maxima(n):
    if(n<10):
        return n
    M=cifra_maxima(n // 10)
    if( n%10 > M):
        return n % 10
    else:
        return M

#d)
def nr_cifre_pare(n):
    if(n<10):
        if(n%2==0):
            return 1
        else:
            return 0
    else:
        if(n%2==0):
            return 1+nr_cifre_pare( n // 10)
        else:
            return nr_cifre_pare( n // 10)

#5
def putere(a,n):
    if(n == 1):
        return a
    else:
        return a*putere(a,n-1)

#9
def interval(min_value,max_value):
    if(min_value == max_value):
        print(min_value)
    else:
        print(max_value)
        interval(min_value, max_value - 1)

if __name__ == '__main__':
    print(f"Numarul {125} are {nr_cifre(125)} cifre")
    print(f"Cifra maxima a numarului {4375} este {cifra_maxima(4375)}")
    print(f"Numarul {57824} are {nr_cifre_pare(57824)} cifre pare")
    print(putere(2,2))
    interval(3,7)