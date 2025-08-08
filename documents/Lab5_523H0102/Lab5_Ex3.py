import itertools as itools
import random

# Create a deck
deck = []
values = [str(i) for i in range(1, 10 + 1)]
values = values + ['J', 'Q', 'K']
suits = ['♠', '♣', '♦', '♥']

for suit in suits:
    for value in values:
        deck.append(value + suit)

deck = set(deck)
# print(deck)
# print(len(deck))

# All 4 cards are the same suit
def simulationSameSuit(k, n):
    count = 0
    drawCard = list(itools.combinations(deck, k))
    for i in range(n):
        Fourcards = random.choice(list(drawCard))
        if (Fourcards[0][1] == Fourcards[1][1] and Fourcards[1][1] == Fourcards[2][1] and Fourcards[2][1] == Fourcards[3][1] and Fourcards[3][1] == Fourcards[0][1]):
            count += 1
    return count/n


# All 4 cards are different suits
def simulationDifferentSuits(k, n):
    count = 0
    drawCard = list(itools.combinations(deck, k))
    for i in range(n):
        Fourcards = random.choice(list(drawCard))
        if (Fourcards[0][1] != Fourcards[1][1] and Fourcards[1][1] != Fourcards[2][1] and Fourcards[2][1] != Fourcards[3][1] and Fourcards[3][1] != Fourcards[0][1]):
            count += 1
    return count/n


# All 4 cards are same color
def simulationSameColor(k, n):
    count = 0
    drawCard = list(itools.combinations(deck, k))
    for i in range(n):
        checkSet = set()
        Fourcards = random.choice(list(drawCard))
        for cards in Fourcards:
            checkSet = checkSet | {cards[1]}
        if((list(checkSet).count('♠') == 0 and list(checkSet).count('♣') == 0) or (list(checkSet).count('♦') == 0 and list(checkSet).count('♥') == 0)):
            count += 1
    return count/n


# All 4 cards are same value
def simulationSameValue(k, n):
    count = 0
    drawCard = list(itools.combinations(deck, k))
    for i in range(n):
        Fourcards = random.choice(list(drawCard))
        if (Fourcards[0][0] == Fourcards[1][0] and Fourcards[1][0] == Fourcards[2][0] and Fourcards[2][0] == Fourcards[3][0] and Fourcards[3][0] == Fourcards[0][0]):
            count += 1
    return count/n


# All 4 cards are numbers
def simulationNumbers(k, n):
    count = 0
    drawCard = list(itools.combinations(deck, k))
    for i in range(n):
        checkSet = set()
        Fourcards = random.choice(list(drawCard))
        for cards in Fourcards:
            checkSet = checkSet | {cards[0]}
        if (list(checkSet).count('J') == 0 and list(checkSet).count('Q') == 0 and list(checkSet).count('K') == 0):
            count += 1
    return count/n


# All 4 cards are faces
def simulationFaces(k, n):
    count = 0
    drawCard = list(itools.combinations(deck, k))
    for i in range(n):
        checkSet = set()
        Fourcards = random.choice(list(drawCard))
        for cards in Fourcards:
            checkSet = checkSet | {cards[0]}
        if (list(checkSet).count('J') != 0 and list(checkSet).count('Q') != 0 and list(checkSet).count('K') != 0):
            count += 1
    return count/n

print(simulationSameSuit(4, 500))
print(simulationDifferentSuits(4, 500))
print(simulationSameColor(4, 500))
print(simulationSameValue(4, 1000))
print(simulationNumbers(4, 500))
print(simulationFaces(4, 500))