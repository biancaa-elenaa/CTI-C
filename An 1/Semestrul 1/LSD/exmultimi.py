import functools

def afisare(multime):
    print("{", end="")
    functools.reduce(lambda acc,elem:print(elem,end=","),multime,None)
    print("}")

def mull(lista):
    return functools.reduce(lambda acc,pereche:acc | {pereche[0]},lista,set())
def mull1(lista):
    return functools.reduce(lambda acc,pereche: acc | {pereche[1]},lista,set())
def mul(lista):
    return functools.reduce(lambda acc,pereche: acc | {pereche[0]} | {pereche[1]},lista,set())

def prime(lista):
    if len(lista) > 0:
        a,b = lista[0]
        return {a} | prime(lista[1:])
    else:
        return set()
def my_filter(functie,multime):
    return functools.reduce(lambda acc,elem: acc | {elem} if functie(elem) else acc,multime,set())

def partition(functie,multime):
    mul1=functools.reduce(lambda acc,elem: acc | {elem} if functie(elem) else acc,multime,set())
    mul2=multime - mul1
    return mul1,mul2

def cifre(n):
    if n == 0:
        return set()
    else:
        return {n%10} | cifre(n//10)
def perechi(lista):
    if(len(lista) == 0):
        return set()
    else:
        a,b=lista[0];
        return {a} | perechi(lista[1:])

def perechi1(lista):
    return functools.reduce(lambda acc,x:acc | {x[0]},lista,set())

def listaaa(lista):
    if len(lista) == 0:
        return set()
    else:
        return lista[0] | listaaa(lista[1:])

def mult_cifre(nr):
    if nr <= 9:
        return {nr}
    else:
        return {nr%10} | mult_cifre(nr // 10)

def mul_lista(mul):
    return functools.reduce(lambda acc,el: acc | mult_cifre(el) ,mul,set())

if __name__ == '__main__':
    print(afisare({1,2,3}))
    print(mull([(1,2),(3,4)]))
    print(mull1([(1,2),(3,4)]))
    print(mul([(1, 2), (3, 4)]))
    print(prime([(1, 2), (3, 4), (7, 9)]))
    print(my_filter(lambda x: x % 2 == 0,{1,2,3,4}))
    print(partition(lambda x:x%2 == 0,{1,2,3,4}))
    print(cifre(326))
    print(perechi([(3,4),(5,3)]))
    print(perechi1([(7,4),(5,3)]))
    print(listaaa([{1, 2, 3}, {1, 2, 3, 4}, {3, 5, 6, 7}]))
    print(mult_cifre(1234))
    print(mul_lista({1234, 123, 127}))