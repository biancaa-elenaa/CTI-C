import functools

#ex4
def partition(functie,multime):
      mul1 = functools.reduce(lambda mul1, elem: mul1 | {elem} if functie(elem) is True else mul1, multime, set())
      mul2 = functools.reduce(lambda mul2, elem: mul2 | {elem} if functie(elem) is False else mul2, multime, set())
      return mul1,mul2

#ex5
def reuniune(lista):
    if len(lista) > 0:
        head = lista [0]
        return head | reuniune((lista[1:]))
    else:
        return set()
def intersectie(lista):
    if len(lista) > 1:
        head = lista[0]
        return head & intersectie(lista[1:])
    else:
        return lista[0]

#ex6
def cifre(n):
    if n>0:
        return {n%10} | cifre(n // 10)
    else:
        return set()
def rreuniune(multime):
    return functools.reduce(lambda mul,m: mul | cifre(m), multime, set())
def iintersectie(multime):
    return functools.reduce(lambda mul,m: mul & cifre(m), multime, cifre(list(multime)[0]))

def min_set(multime):
    return functools.reduce(lambda minn,elem: elem if elem < minn else minn, multime, list(multime)[0])

def ultima_cifra(multime):
    return functools.reduce(lambda mul,elem: mul | {elem%10}, multime, set())

def multime_divizori(nr, i=2):
    if i > nr/2:
        return set()
    if(nr % i == 0):
            multime = multime_divizori(nr,i+1)
            return multime | {i, nr // i}
    else:
        return multime_divizori(nr, i+1)

def filterr(functie,multime):
    return set(filter(functie,multime))

if __name__ == '__main__':
    print(partition(lambda x: x % 2 == 0, {1,2,3,4,5,6}))
    print(reuniune([{1, 2, 3}, {1, 2, 3, 4}, {3, 5, 6, 7}]))
    print(intersectie([{1, 2, 3}, {1, 2, 3, 4}, {3, 5, 6, 7}]))
    print(cifre(2589))
    print(rreuniune({1234, 123, 127}))
    print(iintersectie({1234, 123, 127}))
    print(min_set({45,55,1,66}))
    print(ultima_cifra({45,48,6,99,66}))
    print(multime_divizori(24))
    print(filterr(lambda x: x%2==0,{1,2,3,4,5,6,7}))