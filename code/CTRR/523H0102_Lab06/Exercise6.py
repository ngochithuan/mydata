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
    
print(Dec2Bin(47))