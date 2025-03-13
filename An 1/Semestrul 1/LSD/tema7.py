import functools
#ex4
fu
def exists(conditie,dict):
    return functools.reduce(lambda acc, pereche: acc | conditie(pereche), dict.items(), False)

def for_all(conditie,dict):
    return functools.reduce(lambda acc, pereche: acc & conditie(pereche), dict.items(), True)

#ex5
def f(pereche):
    cheie,valoare = pereche
    return cheie,valoare+1

def adauga_pereche(pereche,dictionar):
    cheie, valoare = pereche
    dictionar[cheie]= valoare
    return dictionar

def my_map(conditie,dict):
    return functools.reduce(lambda dict_nou, pereche: adauga_pereche(conditie(pereche), dict_nou), dict.items(),{})

#ex6
def g(dictionar,lista):
    return functools.reduce(lambda acc,pereche: acc | {pereche[1]} if pereche[0] in lista else acc, dictionar.items(),set())

print(exists(functie,{'a': 3, 'b': 5, 'c': 1}))
print(for_all(functie,{'a': 5, 'b': 7, 'c': 1}))
print((my_map(f,{'a': 5, 'b': 7, 'c': 6})))
print(g({'aa': 5, 'bb': 7, 'ca': 6}, ['aa', 'bb', 'c']))