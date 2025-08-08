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

# a/
drawCards = list(itools.combinations(deck, 5))
count = 0
total = len(drawCards)