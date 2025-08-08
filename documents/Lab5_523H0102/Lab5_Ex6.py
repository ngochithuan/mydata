

E = {0, 1, 2, 3, 4, 5}

# a/
listInSetE = []
for number in range(100, 1000, 1):
    strNum = str(number)
    if ((int(strNum[0]) in E) and (int(strNum[1]) in E) and (int(strNum[2]) in E)):
        listInSetE.append(number)
        
print(listInSetE)

# b/
def checkDiff(num):
    strNum = str(num)
    checkSet = set()
    for i in range(len(strNum)):
        checkSet = checkSet | {int(strNum[i])}  
    if (len(checkSet) != len(strNum)):
        return False
    return True

tempList = []
for number in range(1000, 10000, 1):
    strNum = str(number)
    if ((int(strNum[0]) in E) and (int(strNum[1]) in E) and (int(strNum[2]) in E) and checkDiff(number)):
        tempList.append(number)
        

