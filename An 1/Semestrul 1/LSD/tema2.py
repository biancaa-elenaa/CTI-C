import operator
 # ex1
def egale(x,y,m,n):
    if(x == y):
        print(f"Argumentele {m} si {n} sunt egale")

def dif(a,b,c):
    if(a==b==c):
        print(f"Toate argumentele sunt egale")
    elif(a!=b and a!=c and c!=b):
            print(f"Toate argumentele sunt distincte")
    else:
        egale(a,b,1,2)
        egale(a,c,1,3)
        egale(b,c,2,3,)

# ex3
def f(x):
    return x*2
def g(x):
    return x+10
def suma(f,g):     #ex3a
    return lambda x: f(x)+g(x)
def op_functii(op,q,w):   #ex3b
    return op(q,w)
if __name__ == '__main__':
    dif(1,1,3)
    fg=suma(f,g)
    print(fg(1))
    print(op_functii(operator.add,f(1),g(0)))
    print((lambda x: x + 15)(3))  # ex 4