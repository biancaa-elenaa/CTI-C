#1
def progresie_aritmetica(n):
    if n == 0:
        return 2
    else:
        return 2*progresie_aritmetica(n-1)-3

#2
def Fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return Fibonacci(n-1)+Fibonacci(n-2)

#3
def suma(n):
    if(n == 0):
        return 0
    else:
        return n + suma(n-1)

#4a
def prod_cifre(n):
    if(n == 0):
        return 1
    else:
        return n%10 * prod_cifre(n // 10)

#10 a)
def aparitii(n,cif):
    if(n == 0):
        return False
    elif(n % 10 == cif):
        return True
    else:
        return aparitii(n // 10, cif)
#10 b)
def nr_aparitii(n, cf):
    if(n<10 and n!=cf):
        return 0
    elif(n%10 == cf):
        return 1+nr_aparitii(n//10,cf)
    else:
        return nr_aparitii(n//10,cf)
#7
def cmmdc(a,b):
    if b == 0:
        return a
    else:
        return cmmdc(b,a%b)

if __name__ == '__main__':
    print(progresie_aritmetica(3))
    print(Fibonacci(4))
    print(f"Suma primelor {5} numere este {suma(5)}")
    print((f"Produsul cifrelor lui {342} este {prod_cifre(342)}"))
    print(f"Cel mai mare divizor comun al numerelor {12} si {18} este {cmmdc(12,18)}")
    print(aparitii(7348,9))
    print(nr_aparitii(122258,2))
