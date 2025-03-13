import math

def ultima_cifra(n):    #ex1
    return n%10

def compus_chimic(c,h,o):  #ex2
    return c*12+h+o*16
def ec_grd2(a,b,c): #ex3
    if (b*b - 4*a*c > 0):
        print(f"Solutiile ecuatiei sunt x1 = {(-b+math.sqrt(b*b-4*a*c))/2} , x2={(-b-math.sqrt(b*b-4*a*c))/2}")
    elif (b*b - 4*a*c == 0):
        print(f"Solutiile ecuatiei sunt x1 = x2 = {-b/(2*a)}")
    else:
        print(f"Ecuatia nu are solutii")
def an_bisect(an): #4
    if( an % 4 == 0 and an % 100 != 0):
        return True
    if( an % 400 == 0):
        return True
    return False
def f(x):     #5
    if (x < -3):
        return 2*x+1
    elif (x == 3):
        return 0
    else:
        return 3 * x * x + 6 * x - 5

def interval(a,b,c): #6
    return a <= c <= b

def sort(a,b,c): #7
    M = max(a,b,c)
    m = min(a,b,c)
    return M, a+b+c-M-m, m

def cerc(r): #9
    print(f"Lungimea discului = {2 * math.pi * r}")
    print(f"Aria discului = {math.pi * r * r} ")
if __name__ == '__main__':

    print(f"Ultima cifra este {ultima_cifra(34784)}")
    print(f"masa moleculara este {compus_chimic(1,1,1)}")
    a=1
    b=1
    c=-2
    ec_grd2(a,b,c)
    print(f" {an_bisect(2016)} ")
    print(f" {f(2)}")
    print(f" {interval(2,7,10)}")
    print(f"{sort(12,5,22)}")
    cerc(3)


