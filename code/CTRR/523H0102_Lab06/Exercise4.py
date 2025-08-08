# Euclidean Algorithm


def common(a, b):
    thelist = []
    result = []
    for i in range(1, a + 1):
        if a % i == 0:
            #print(i)
            thelist.append(i)
    for t in range(1, b + 1):
        if b % t == 0 and t in thelist:
            result.append(t)
    return result

def gcb(a, b):    
    return common(a, b)[-1]

def lcm(a, b):
    return common(a, b)
    
print(lcm(4, 6))