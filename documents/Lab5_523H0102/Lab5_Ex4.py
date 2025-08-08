import itertools as itools

# a/
URN = {'W1', 'W2', 'B1', 'B2', 'B3', 'R1', 'R2', 'R3'}

# b/
U3 = set(itools.combinations(URN, 3))
# print(U3)

# c/
white1blue1red1 = []
for balls in U3:
    checkSet = set(balls[i][0] for i in range(3))
    if (len(checkSet) == 3):
        white1blue1red1.append(balls)
#print(white1blue1red1)

# d/
count = 0
total = len(U3)
for balls in U3:
    checkSet = set(balls[i][0] for i in range(3))
    if (len(checkSet) == 3):
        count += 1
P = count/total

print(P)