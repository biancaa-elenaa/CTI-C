import functools


def pare(lista):
    if len(lista) > 0:
        head = lista[0]
        tail = lista[1:]
        if(head % 2 ==0):
            print(head)
        pare(tail)

def caractere(lista):
    if len(lista) > 0:
        head = lista[0]
        tail = lista[1:]
        if len(head) > 2:
            print(head)
        caractere(tail)

def produs(lista):
    return functools.reduce(lambda x,acc: x*acc,lista,1)

def puteri(lista):
    lista1=list(map(lambda x: pow(x,3) ,lista))
    return lista1
def aux(n,i):
    if i<=n/2:
        if n%i == 0:
            return False
        else:
            return aux(n,i+1)
def prim(x):
    if x == 1:
        return False
    else:
        return aux(x,2)

#1b
def f(numar,conditie):
    if numar<=9:
        if(conditie(numar) == True):
            return [numar]
        else:
            return []
    else:
        if(conditie(numar%10) == True):
            return f(numar // 10,conditie) + [numar%10]
        else:
            return f(numar // 10,conditie)
def counif(functie,lista):
    return functools.reduce(lambda acc,elem: acc+1 if functie(elem) is True else acc,lista,0)

def partition(functie,lista):
    lista1= list(filter(lambda x: functie(x),lista))
    lista2 = list(filter(lambda x: not functie(x),lista))
    return lista1,lista2

def numar(lista):
    if len(lista):
        head=lista[-1]
        tail=lista[:-1]
        return head + numar(tail) * 10
    else:
        return 0

def elimina_duplicate(lista):
    if len(lista)>1:
        if(lista[0] == lista [1]):
            return elimina_duplicate(lista[1:])
        else:
            return [lista[0]] + elimina_duplicate(lista[1:])
    else:
        return []

if __name__ == '__main__':
    print(pare([1,2,3,4,5,6,7]))
    print(caractere(["abc","123","aa","ccc","cc"]))
    print('\n')
    print(produs([1,2,3]))
    print(puteri([2,3,1]))
    lista1=list(filter(prim,[2,3,4,5]))
    print(lista1)
    print(f(23456,lambda x: x%2==0))
    print(counif(lambda x: x%2==0,[1,2,3,4,5,6]))
    print(partition(lambda x:x > 5,[4,6,7,5,8,9]))
    print(numar([1,2,3]))
    print(elimina_duplicate([1,2,2,2,3,4,4]))
