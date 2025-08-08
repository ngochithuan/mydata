from sympy import isprime

def printPrime(N):
    n = 1
    while (n <= N):
        if (isprime(n)):
            print(n, end=" ")
        n += 1    
        
printPrime(170)