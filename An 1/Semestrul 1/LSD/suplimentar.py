
def inmultire(lista):
    return functools.reduce(lambda x,y: x*y,lista,1)
def putere(lista):
    return list(map(lambda x: pow(x,3),lista))

import functools
def lista(lista):
    return list(filter(lambda x: x%2!=0, lista))
def inmultire(lista):
    return functools.reduce(lambda x,y: x*y,lista)

def ultima_cifra(x):
    return x%10

def sirr(lista):
    if len(lista) > 0:
        head=lista[0]
        tail=lista[1:]
        if len(head)<3:
            print(head)
        sirr(tail)
    else:
        return 0

def nrp(lista):
    if len(lista) > 0:
        head=lista[0];
        tail=lista[1:];
        if(head%2==0):
            print(head)
        nrp(tail)
def f(lista):
    return list(filter(lambda x:x%2==0,lista))
def rr(lista):
    return list(map(lambda x: x*2,lista))
def aux(n,i):
    if i<= n / 2:
        if n% i == 0:
            return False
        else:
            return aux(n, i+1)
    else:
        return True
def prim(n):
    if n==1:
        return False
    else:
        return aux(n,2)
def afisaren(lista,n):
    if n<0:
        return []
    else:
        return afisaren(lista,n-1)+[lista[n-1]]
if __name__ == '__main__':
    lista1=lista([2,5,8,9,3])
    print(lista1)
    print(putere([2,3,1]))
    print(inmultire([2,1,4]))
    lista1=putere([2,2,2])
    print(lista1)
    print(inmultire([2,3,2]))
    lista2=[256,589,57,44]
    lista2.sort(key=ultima_cifra)
    print(lista2)
    print(sirr(['aa','bbb','cc']))
    nrp([22,15,33,2])
    nrpare=list(filter(lambda x: x%2==0,[2,8,4,5,15,9]))
    rez=list(map(lambda x: x // 2, nrpare))
    print(rez)
    print(rr(f([2,4,8,5])))
    patrate=list(map(lambda x: x*x,[1,2,3]))
    print(functools.reduce(lambda x,y: x+y, patrate,0))
    print(functools.reduce(lambda x,y: x+y, nrpare,0))
    nrprime=list(filter(prim[7,5,6]))
    print(functools.reduce(lambda x,y: x+y, nrprime))