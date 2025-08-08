def thieves(x):
    if x < 0:
        return 0
    return x + 1

def days_to_deplete():
    total_thieves = 40
    day = 0
    while total_thieves > 0:
        total_thieves -= thieves(day)
        day += 1
    return day - 1

print("Day:", days_to_deplete())

def richest(X, n=None):
    if n is None:
        n = len(X) - 1
    if n == 0:
        return X[0]
    previous = richest(X, n - 1)
    return max(X[n], previous)

X = [10, 5, 20, 15]
print("Richest person has:", richest(X))

def waytochoose(n, k, memo=None):
    if memo is None:
        memo = {}
    if k == 0 or k == n:
        return 1
    if (n, k) in memo:
        return memo[(n, k)]
    result = waytochoose(n - 1, k, memo) + waytochoose(n - 1, k - 1, memo)
    memo[(n, k)] = result
    return result

def find_k():
    n = 50
    target = 1000
    min_diff = float('inf')
    best_k = 0
    for k in range(n + 1):
        ways = waytochoose(n, k)
        diff = abs(ways - target)
        if diff < min_diff:
            min_diff = diff
            best_k = k
    return best_k

print("Best k for combinations:", find_k())

def waytochooseP(n, k):
    if k == 0:
        return 1
    result = 1
    for i in range(n, n - k, -1):
        result *= i
    return result

def find_k_permutations():
    n = 50
    target = 10000
    min_diff = float('inf')
    best_k = 0
    for k in range(n + 1):
        ways = waytochooseP(n, k)
        diff = abs(ways - target)
        if diff < min_diff:
            min_diff = diff
            best_k = k
    return best_k

print("Best k for permutations:", find_k_permutations())

def story_chars(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return 2 ** (n - 1) + story_chars(n - 1)

def total_chars():
    return story_chars(547)

print("Total characters:", total_chars())

def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

print("Fibonacci number:", fibonacci(10))

def towerOfHanoi(n, A, B, C):
    if n > 0:
        towerOfHanoi(n - 1, A, C, B)
        C[1].append(A[1].pop())
        print(f"Move disk from {A[0]} to {C[0]}")
        towerOfHanoi(n - 1, B, A, C)

A = ['A', [3, 2, 1]]
B = ['B', []]
C = ['C', []]
print("Tower of Hanoi steps:")
towerOfHanoi(3, A, B, C)