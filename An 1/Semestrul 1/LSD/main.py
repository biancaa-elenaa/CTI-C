
def oglindit(numar,og):
    if(numar == 0):
        return og
    u=numar%10
    og=og*10+u
    return oglindit(numar // 10,og)


print(oglindit(145,0))


def palindrom(n):
    if(n == oglindit(n,0)):
        return True
    else:
        return False

print(palindrom(122))