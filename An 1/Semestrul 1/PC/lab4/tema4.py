#1b
def cifre_lista(nr, conditie):
    if(nr < 10):
       if(conditie(nr) == 0):
           return [nr]
       else:
           return []
    else:
        if(conditie(nr) == 0):
            return cifre_lista(nr // 10, conditie) + [nr%10]
        else:
            return cifre_lista(nr // 10, conditie)

#1c-recursiv
def lista_cifre(lista,conditie):
    if( len(lista) > 0):
        rhead = lista[-1]
        rtail = lista[:-1]
        if(conditie(rhead) == 0):
            return rhead + lista_cifre(rtail,conditie)*10
        else:
            return lista_cifre(rtail,conditie)
    else:
        return 0
#1c-nerecursiv

import functools
def selectarea_cifrelor(lista):
    return list(filter(lambda x: x%2 == 0, lista))
def construire_nr(lista):
    return functools.reduce(lambda x,y: x*10+y,selectarea_cifrelor(lista))

#2
def fromto(a,b):
    if(a == b):
        return [a]
    else:
         return [a]+fromto(a+1,b)
def divizibil(a,b,d):
    if(a == b):
        if(a % d == 0):
            return [a]
        else:
            return []
    else:
        if(a % d == 0):
            return [a]+divizibil(a+1,b,d)
        else:
            return divizibil(a+1,b,d)

#5a
#def filterr(fnc, lista):
#    return functools.reduce()

#5b
def exists(lista,conditie):
    if(len(lista)) == 0:
        return False
    if(conditie(lista[0]) == 0):
            return True
    else:
            return exists(lista[1:],conditie)

#6a
def countif(functie,lista):
    return functools.reduce(lambda k,x: k + 1 if functie(x) else k,lista,0)
#6b
def sumif(functie,lista):
    return functools.reduce(lambda s,a: s + a if functie(a) else s,lista,0)
if __name__ == '__main__':
    print(cifre_lista(4567, lambda nr: nr % 2))
    print(construire_nr([2,5,8,6]))
    print(fromto(2,5))
    print(divizibil(2,10,2))
    print(exists([2,17,5], lambda x: x % 3 ))
    print(countif(lambda x: x % 2 != 0,[2,17,55,1]))
    print(sumif(lambda x: x % 2 == 0,[2,5,8,4]))