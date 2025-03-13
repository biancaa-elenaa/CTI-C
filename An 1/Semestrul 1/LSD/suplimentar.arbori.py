'''
Arbore binar:
            2
           /\
          1  5
             /\
            4  7
'''

# ca sa nu mai scriem numele in ghilimele de fiecare data

cheie = "cheie"
stanga = "stanga"
dreapta = "dreapta"

nod1 = {cheie: 1, stanga: None, dreapta: None}  # frunza
nod7 = {cheie: 7, stanga: None, dreapta: None}  # frunza
nod4 = {cheie: 4, stanga: None, dreapta: None}  # frunza
nod5 = {cheie: 5, stanga: nod4, dreapta: nod7}
radacina = {cheie: 2, stanga: nod1, dreapta: nod5}

def frunze(arbore):
    if arbore is not None:
        if(arbore[stanga] is None and arbore[dreapta] is None):
            return [arbore[cheie]] + frunze(arbore[stanga]) + frunze(arbore[dreapta])
        else:
            return frunze(arbore[stanga]) + frunze(arbore[dreapta])
    else:
        return []

print(frunze(radacina))

def cond(functie,arbore):
    if arbore is not None:
        if not functie(arbore[cheie]):
            return False
        return cond(functie,arbore[stanga]) and cond(functie,arbore[dreapta])
    else:
        return True

print(cond(lambda x:x%2==0,radacina))





