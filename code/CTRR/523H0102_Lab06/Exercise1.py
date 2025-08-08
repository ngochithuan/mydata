from sympy import isprime

def nextPrime(num):
    i = num
    while (True):
        if((i != num) and isprime(i)):
            return i
        i += 1 

print(nextPrime(97))