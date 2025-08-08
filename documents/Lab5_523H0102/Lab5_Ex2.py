import itertools as itool

urn = {}

blue = {'b' + str(i) for i in range(1, 2+1)}
red = {'r' + str(i) for i in range(1, 3+1)}
white = {'w' + str(i) for i in range(1, 5+1)}

urn = blue | red | white

#print(urn)

# All 3 balls are same color
count = 0
pick3Balls = list(itool.combinations(urn, 3))
for item in pick3Balls:
    if (item[0][0] == item[1][0] == item[2][0]):
        count += 1
print(count/len(pick3Balls))

# All 3 balls are different colors
count = 0
pick3Balls = list(itool.combinations(urn, 3))
for item in pick3Balls:
    if (item[0][0] != item[1][0] and item[1][0] != item[2][0] and item[0][0] != item[2][0]):
        count += 1
print(count/len(pick3Balls))

# Only 2 balls are same color
count = 0
pick3Balls = list(itool.combinations(urn, 3))
for item in pick3Balls:
    checkSet = set()
    for i in range(0, 3):
        checkSet = checkSet | {item[i][0]}
    if (len(checkSet) == 2):
        count += 1
print(count/len(pick3Balls))

# There are 2 red balls and 1 white ball
count = 0
pick3Balls = list(itool.combinations(urn, 3))
for item in pick3Balls:
    checkSet = []
    for i in range(0, 3):
        checkSet.append(item[i][0])
    if (checkSet.count('r') == 2 and checkSet.count('w') == 1):
        count += 1
print(count/len(pick3Balls))

# List all cases that all 3 balls are white
print('All cases that all 3 balls are white:')
pick3Balls = list(itool.combinations(urn, 3))
for item in pick3Balls:
    for i in range(3):
        if item[i][0] == 'w':
            print(item)
