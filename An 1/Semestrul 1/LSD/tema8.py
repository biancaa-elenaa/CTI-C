'''
Arbore binar:
            2
           /\
          1  5
        /     \
       4       7
'''

cheie = "cheie"
stanga = "stanga"
dreapta = "dreapta"

nod4= {cheie: 4,stanga:None, dreapta: None}
nod1 = {cheie: 1, stanga: nod4, dreapta: None}
nod7 = {cheie: 7, stanga: None, dreapta: None}
nod5 = {cheie: 5, stanga: None, dreapta: nod7}
radacina = {cheie: 2, stanga: nod1, dreapta: nod5}

#ex1
def doarunfiu(arbore):
    if arbore is not None:
        if (arbore[stanga] is None and arbore[dreapta] is not None) or (arbore[stanga] is not None and arbore[dreapta] is None):
            return doarunfiu(arbore[stanga]) + [arbore[cheie]] + doarunfiu(arbore[dreapta])
        else:
            return doarunfiu(arbore[stanga]) + doarunfiu(arbore[dreapta])
    else:
        return []

print(doarunfiu(radacina))

#ex2

def noduri(arbore):
    if arbore is not None:
        return 1 + noduri(arbore[stanga])+noduri(arbore[dreapta])
    else:
        return 0

print(noduri(radacina))
print("\n")

#ex4
def tiparire(arbore,nivel=1):
    if arbore is not None:
        print(" "*2*nivel + f"{(arbore[cheie])}")
        tiparire(arbore[stanga], nivel + 1)
        tiparire(arbore[dreapta], nivel +1)

print(tiparire(radacina))
def adaugare_nod(parinte,nod_nou,pozitie):
    if(parinte[pozitie] is None)

