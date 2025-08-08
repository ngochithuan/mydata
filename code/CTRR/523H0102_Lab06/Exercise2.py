def primeFact(p):
    thelist = []
    i = 2
    while (p != 1):
        if (p % i == 0):
            thelist.append(i)
            p = p / i
        else:
            i += 1
    return thelist

print(primeFact(60))