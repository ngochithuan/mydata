def Dec2Bin(num):
    bin1 = [1]
    bin2 = []
    for i in range (1, num+1):
        if (2**i <= num):
            bin1.append(2**i)
            
    for i in reversed(bin1):
        if (num - i >= 0):
            bin2.append(1)
            num = num - i
        else:
            bin2.append(0)
    return "".join(str(item) for item in bin2)

def fracBin(fnum):
    result = "0."
    sfnum = str(fnum)
    num = sfnum.split('.')
    n = num[0]
    f = num[1]
    while (int(f) != 0):
        fnum = fnum * 2
        sfnum = str(fnum)
        num = sfnum.split('.')
        # print(num)
        n = num[0]
        f = num[1]
        result += n
        fnum = float("0."+f)
        
    return float(result)
    

def dFrac(N):
    result = ""
    strN = str(N)
    num = strN.split('.')
    num1 = int(num[0])
    num2 = float("0." + num[1])
    
    num1 = Dec2Bin(num1)
    num2 = fracBin(num2)
    return result + str(float(num1) + num2)


print(dFrac(5.25))