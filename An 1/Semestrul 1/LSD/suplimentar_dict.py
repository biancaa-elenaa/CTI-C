import functools

def adauga_in_dictionar(pereche,dict):
     cheie,valoare = pereche
     dict[cheie]=valoare
     return dict

def ffilter(dictionar, conditie):
     return functools.reduce(lambda dict_nou,pereche:adauga_in_dictionar(pereche,dict_nou) if conditie(pereche[1]) else dict_nou,dictionar.items(),{})

print(ffilter({'a': 5, 'b': 7, 'c': 1}, lambda x: x >= 5))

def functie(pereche):
     cheie,valoare=pereche
     if valoare >= 5:
          return True
     else:
          return False
def exists(conditie,dictionar):
     return functools.reduce(lambda acc,pereche:acc | conditie(pereche),dictionar.items(),False)

def for_all(conditie,dictionar):
     return functools.reduce(lambda acc,pereche: acc & conditie(pereche),dictionar.items(),True)

print(exists(functie,{'a': 5, 'b': 7, 'c': 1}))
print(for_all(functie,{'a': 5, 'b': 7, 'c': 3}))

def f(pereche):
     cheie ,valoare= pereche
     return cheie,valoare +1
def adauga_pereche(pereche,dict):
     cheie,valoare = pereche
     dict[cheie] = valoare
     return dict

def my_mapp(dictionar,functie):
     return functools.reduce(lambda dict_nou,pereche: adauga_pereche(functie(pereche),dict_nou),dictionar.items(),{})

print(my_mapp({'a': 5, 'b': 7, 'c': 6},f))

def multime(dictionar,lista):
     return functools.reduce(lambda m,elem:m | {elem[1]} if elem[0] in lista else m,dictionar.items(),set())
print(multime({'aa': 5, 'bb': 7, 'ca': 6},['aa', 'bb', 'c']))

dictionar1={
    'a': 5,
    'b': 7,
    'c': 2,
}
def parametru(pereche):
     cheie,valoare = pereche
     return valoare * 2

def maxx(functie,dictionar):
     return functools.reduce(lambda acc,pereche:max(acc,functie(pereche)),dictionar.items(),0)

print(maxx(parametru,dictionar1))

def a_d(pereche,dictionar):
     cheie,valoare = pereche
     if cheie in dictionar.keys():
          dictionar[cheie] = dictionar[cheie]+valoare
     else:
          dictionar[cheie]=valoare
     return dictionar
def transformare(lista):
     return functools.reduce(lambda dict_nou,pereche:a_d(pereche,dict_nou),lista,{})
print(transformare([('a', 7), ('b', 5), ('c', 2), ('a', 3), ('b', 3)]))

def string_to_pairs(sirul):
     return functools.reduce(lambda acc, character: acc + [(character, 1)], list(sirul), [])
print(string_to_pairs("aaa"))


def ultimele_cifre(mul):
     return functools.reduce(lambda lst,elem: lst + [elem%10],mul,[])

print(ultimele_cifre({1234,11,22,33}))

def dublare(dictionar):
     dictionar = dict(zip(dictionar.keys(),map(lambda x: x*2, dictionar.values())))
     return dictionar
print(dublare({'a': 3, 'b': 5, 'c': 8}))

def concatenare(dictionar):
     return functools.reduce(lambda sir,elem:sir + elem[0]*elem[1],dictionar.items(),'')

print(concatenare({'a': 3, 'b': 2, 'c': 4}))

def concatenare_cond(dictionar):
     return functools.reduce(lambda sir,elem:sir+elem[0]*elem[1] if elem[1] >= 2 else sir,dictionar.items(),'')
print(concatenare_cond({'a': 1, 'b': 2, 'c': 4}))
'''
Sa se verifice daca exista numere negative in dictionar,daca da se afiseaza True altfel False
'''
def negative(dictionar):
     return functools.reduce(lambda acc,elem:acc or elem[1]<0 ,dictionar.items(),False)

print(negative({'a': -3, 'b': 2, 'c': 4}))

def toate_pozitive(dictionar):
     return functools.reduce(lambda acc,elem:acc and elem[1]>0,dictionar.items(),True)
print(toate_pozitive({'a': -3, 'b': 2, 'c': 4}))


def intersectie_multimi(mul1,mul2):
     intersectie = mul2 & mul1
     return functools.reduce(lambda suma,elem: suma + elem, intersectie,0)

print(intersectie_multimi({1,2,3,4},{2,4}))


