import random
def roll2DiceAreTheSame(n):
    count = 0
    for i in range(n):
        dice1 = random.randint(1, 6)
        dice2 = random.randint(1, 6)
        if (dice1 == dice2):
            count += 1
    return count/n

def roll2DiceAreNotTheSame(n):
    count = 0
    for i in range(n):
        dice1 = random.randint(1, 6)
        dice2 = random.randint(1, 6)
        if (dice1 != dice2):
            count += 1
    return count/n

def roll2DiceAreEven(n):
    count = 0
    for i in range(n):
        dice1 = random.randint(1, 6)
        dice2 = random.randint(1, 6)
        if (dice1 % 2 == 0 and dice2 % 2 == 0):
            count += 1    
    return count/n

def roll2DiceAreOdd(n):
    count = 0
    for i in range(n):
        dice1 = random.randint(1, 6)
        dice2 = random.randint(1, 6)
        if (dice1 % 2 != 0 and dice2 % 2 != 0):
            count += 1
    return count/n


def roll2DiceAreOneEvenAndOneOdd(n):
    count = 0
    for i in range(n):
        dice1 = random.randint(1, 6)
        dice2 = random.randint(1, 6)
        if (dice1 % 2 == 0 and dice2 % 2 != 0 or dice1 % 2 != 0 and dice2 % 2 == 0):
            count += 1    
    return count/n

def roll2DiceAreBothEqual6(n):
    count = 0
    for i in range(n):
        dice1 = random.randint(1, 6)
        dice2 = random.randint(1, 6)
        if (dice1 == dice2 and dice1 == 6):
            count += 1
    return count/n

def roll2DiceTotalEqual10(n):
    count = 0
    for i in range(n):
        dice1 = random.randint(1, 6)
        dice2 = random.randint(1, 6)
        if (dice1 + dice2 == 10):
            count += 1
    return count/n


print(roll2DiceAreTheSame(10000))
print(roll2DiceAreNotTheSame(10000))
print(roll2DiceAreEven(10000))
print(roll2DiceAreOdd(10000))
print(roll2DiceAreOneEvenAndOneOdd(10000))
print(roll2DiceAreBothEqual6(10000))
print(roll2DiceTotalEqual10(10000))