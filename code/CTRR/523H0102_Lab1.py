# Tutorial 1
x = 3
print(type(x)) # Prints "< class 'int '>"
print(x) # Prints "3"
print(x + 1) # Addition ; prints "4"
print(x - 1) # Subtraction ; prints "2"
print(x * 2) # M ultiplication ; prints "6"
print(x ** 2) # Exponentiation ; prints "9"
x += 1
print(x) # Prints "4"
x *= 2
print(x) # Prints "8"
y = 2.5
print(type(y)) # Prints "< class 'float '>"
print(y, y + 1 , y * 2, y ** 2) # Prints "2.5 3.5 5.0 6.25 "

t = True
f = False
print(type(t)) # Prints "< class 'bool'>"
print(t and f) # Logical AND; prints "False "
print(t or f) # Logical OR; prints "True "
print(not t) # Logical NOT ; prints "False "
print(t != f) # Logical XOR ; prints "True "

hello = 'hello' # String literals can use single quotes
world = " world " # or double quotes ; it does not m atter .
print(hello) # Prints "hello "
print(len (hello)) # String length ; prints "5"
hw = hello + ' ' + world # String concatenation
print(hw ) # prints "hello world "
hw12 = '%s %s %d ' % (hello , world , 12) # sprintf style string formatting
print(hw12 ) # prints "hello world 12 "

s = "hello"

print(s.capitalize ()) # Capitalize a string ; prints "Hello "
print(s.upper()) # Convert a string to uppercase ; prints "HELLO "
print(s.rjust(7)) # Right -justify a string , padding with spaces; prints " hello "
print(s.center(7)) # Center a string , padding with spaces ; prints " hello "
print(s.replace ('l', '(ell)')) # Replace all instances of one substring with another ;
print(' world '.strip ()) # Strip leading and trailing w hitespace ; prints "world"

# Tutorial 2.1
xs = [3, 1, 2] # Create a list
print(xs, xs[2]) # Prints "[3, 1 , 2] 2"
print(xs[-1]) # Negative indices count from the end of the list; prints "2"
xs[2] = 'foo ' # Lists can contain elem ents of different types
print(xs) # Prints "[3, 1 , 'foo ']"
xs.append ('bar') # Add a new elem ent to the end of the list
print(xs) # Prints "[3, 1 , 'foo ', 'bar ']"
x = xs.pop () # Rem ove and return the last elem ent of the list
print(x, xs) # Prints "bar [3 , 1, 'foo ']"

nums = list(range(5)) # range is a built -in function that creates a list of integers
print(nums) # Prints "[0, 1, 2, 3, 4]"
print(nums[2:4]) #Get a slice from index 2 to 4 (exclusive ); prints "[2, 3]"
print(nums[2:]) #Get a slice from index 2 to the end ; prints "[2, 3, 4]"
print(nums[:2]) #Get a slice from the start to index 2 (exclusive ); prints "[0, 1]"
print(nums[:]) #Get a slice of the whole list; prints"[0, 1, 2, 3, 4]"
print(nums[:-1]) #Slice indices can be negative ; prints"[0, 1, 2, 3]"
nums[2:4] = [8, 9] # Assign a new sublist to a slice
print(nums) # Prints "[0, 1, 8, 9, 4]"

animals = ['cat', 'dog', 'monkey']
for animal in animals:
    print(animal) # Prints " cat", " dog", " monkey ", each on its own line .

animals = ['cat', 'dog', 'monkey']
for idx , animal in enumerate (animals):
    print('#%d: %s' % (idx + 1, animal))
# Prints "# 1: cat", "# 2: dog ", "# 3: m onkey ", each on its own line

nums = [0, 1 , 2, 3 , 4]
squares = []
for x in nums:
    squares.append (x ** 2)
print(squares) # Prints [0, 1 , 4, 9, 16 ]

nums = [0, 1 , 2, 3 , 4]
squares = [x ** 2 for x in nums]
print(squares) # Prints [0, 1 , 4, 9, 16 ]

nums = [0, 1 , 2, 3 , 4]
even_squares = [x ** 2 for x in nums if x % 2 == 0]
print(even_squares) # Prints "[0, 4 , 16 ]"

# Tutorial 2.2
d = {'cat': 'cute', 'dog': 'furry'} # Create a new dictionary with some data
print(d['cat']) # Get an entry from a dictionary ; prints "cute"
print('cat' in d) # Check if a dictionary has a given key ; prints "True"
d['fish '] = 'wet' # Set an entry in a dictionary
print(d['fish ']) # Prints "wet "
# print( d[' monkey ']) # Key Error: ' monkey ' not a key of d
print(d.get('monkey ', 'N/A')) # Get an elem ent w ith a default ; prints "N/A"
print(d.get('fish ', 'N/A ')) # Get an elem ent w ith a default ; prints "wet"
del d['fish '] # Rem ove an elem ent from a dictionary
print(d.get('fish ', 'N/A ')) # "fish " is no longer a key ; prints "N/A"

d = {'person ': 2, 'cat': 4, 'spider': 8}
for animal in d:
    legs = d[animal]
print('A %s has %d legs' % (animal, legs))
# Prints "A person has 2 legs", "A cat has 4 legs", "A spider has 8 legs"

d = {'person ': 2, 'cat': 4, 'spider': 8}
for animal, legs in d.items():
    print('A %s has %d legs' % (animal, legs))
# Prints "A person has 2 legs", "A cat has 4 legs", "A sp

nums = [0, 1 , 2, 3 , 4]
even_num_to_square = {x: x ** 2 for x in nums if x % 2 == 0}
print(even_num_to_square ) # Prints "{0: 0, 2: 4 , 4: 16 }"

# Tutorial 2.3
animals = {'cat', 'dog '}
print('cat' in animals) # Check if an elem ent is in a set; prints
" True "
print('fish ' in animals) # prints "False "
animals.add ('fish ') # Add an elem ent to a set
print('fish ' in animals) # Prints "True "
print(len (animals)) # Nu m ber of elem ents in a set; prints "3"
animals.add ('cat') # Adding an elem ent that is already in the set does nothing
print(len (animals)) # Prints "3"
animals.remove('cat') # Rem ove an elem ent from a set
print(len (animals)) # Prints "2"

animals = {'cat', 'dog', 'fish'}
for idx , animal in enumerate (animals):
    print('#%d: %s' % (idx + 1, animal))
# Prints "#1: fish ", "#2: dog", "#3: cat"

from math import sqrt
nums = {int(sqrt(x)) for x in range(30)}
print(nums)# Prints "{0 , 1, 2 , 3, 4, 5}"

# Tutorial 2.4
d = {(x, x + 1): x for x in range(10)} # Create a dictionary with tuple keys
t = (5, 6) # Create a tuple
print(type(t)) # Prints "< class 'tuple'>"
print(d[t]) # Prints "5"
print(d[(1, 2)]) # Prints "1"

# Tutorial 3
def sign (x):
    if x > 0:
        return 'positive'
    elif x < 0:
        return 'negative'
    else:
        return 'zero'
for x in [-1, 0 , 1]:
    print(sign (x))
# Prints " negative ", " zero ", "positive"

def hello(name , loud = False):
    if loud:
        print('HELLO , %s!' % name.upper())
    else:
        print('Hello , %s' % name)
hello('Bob') # Prints "Hello , Bob "
hello('Fred', loud =True) # Prints "HELLO , FRED !"

# Tutorial 4
class Greeter(object):
# Constructor
    def __init__ (self, name):
        self.name = name # Create an instance variable
    # Instance method
    def greet(self, loud =False):
        if loud :
            print('HELLO , % s!' % self.name.upper())
        else:
            print('Hello , % s' % self.name)
g = Greeter('Fred ') # Construct an instance of the Greeter class
g.greet() # Call an instance m ethod ; prints "Hello , Fred "
g.greet(loud =True) # Call an instance m ethod ; prints "HELLO , FRED!"

print("Exercise 1:")
res1a = 15 * 2 + 7 * 8
res1b = 20 - 15 + 15 * 2
res1c = 20 + 30 - 3 * 15 + 5 * 52
res1d = ((4/6) + (2/6)) / ((5/2) + (1/2))
res1e = 14/2 + 7
res1f = (5 * 2) / (5 - 20 * 3**2 + 30)
print("a. ", res1a)
print("b. ", res1b)
print("c. ", res1c)
print("d. ", res1d)
print("e. ", res1e)
print("f. ", res1f,"\n")
print("Exercise 2:")
print("15 * 2 + 7 * 8 = ", res1a)
print("20 - 15 + 15 * 2 = ", res1b)
print("20 + 30 - 3 * 15 + 5 * 52 = ", res1c)
print("((4/6) + (2/6)) / ((5/2) + (1/2)) = ", res1d)
print("14/2 + 7 = ", res1e)
print("(5 * 2) / (5 - 20 * 3**2 + 30) = ", res1f, "\n")

print("Exercise 3:")
def sumN(n):
    sum = 0
    temp = 0
    if (n > 0):
        while (temp <= n):
            sum += temp
            temp += 1
    if (n < 0):
        while (temp >= n):
            sum += temp
            temp -= 1
    return sum
print(sumN(2))
print(sumN(-5))

print("Exercise 4:")
def removeSpace():
    str = input("Input your string: ")
    print(str)
    print(str.replace(' ', ''))

def replaceSpace():
    str = input("Input your string: ")
    print(str)
    print(str.replace(' ', '_'))
    
#replaceSpace()
print("Exercise 5:")
def calculator():
    inputString = input("Input your equation: ")
    inputString = inputString.replace(" ", "")
    operation = ['+', '-', '*', '/', '%', '^']
    for op in operation:
        if (op in inputString):
            nums = inputString.split(op)
            nums[0] = int(nums[0])
            nums[1] = int(nums[1])
            if (op == '+'):
                print(nums[0] + nums[1])
            elif (op == '-'):
                print(nums[0] - nums[1])
            elif (op == '*'):
                print(nums[0] * nums[1])
            elif (op == '/'):
                if (nums[0] == 0):
                    print("Can't solve")
                    break
                print(nums[0] / nums[1])
            elif (op == '%'):
                print(nums[0] % nums[1])
            elif (op == '^'):
                print(nums[0] ** nums[1])
            else:
                print("Can't solve")
# calculator()

print("Exercise 6:")
def calculatorButUsingDict():
    inputString = input("Input your equation: ")
    inputString = inputString.replace(" ", "")
    operation = ['+', '-', '*', '/', '%', '^']
    for op in operation:
        if (op in inputString):
            nums = inputString.split(op)
            nums[0] = int(nums[0])
            nums[1] = int(nums[1])
            if ((op == '/') and (nums[0] == 0)):
                print("Can't solve")
                return
            tempDict = {'+':(nums[0] + nums[1]),
                        '-':(nums[0] - nums[1]),
                        '*':(nums[0] * nums[1]),
                        '/':(nums[0] / nums[1]),
                        '%':(nums[0] % nums[1]),
                        '^':(nums[0] ** nums[1])
                        }
            print(tempDict.get(op))
            return
    print("Can't solve")
calculatorButUsingDict()

print("Exercise 7:")

A = [
    [92, 93, 85, 18],
    [18, 53, 11, 61],
    [94, 86, 73, 41]
]

B = [
    [25, 67, 47, 83],
    [25, 4, 94, 39],
    [17, 12, 86, 22]
]

def mSum(A, B):
    if ((len(A) != len(B)) or (len(A[0]) != len(B[0]))):
        print("Matrix dimension error")
        return
    C = A
    for i in range(len(A)):
        for j in range(len(A[0])):
            C[i][j] = A[i][j] + B[i][j]
    print(C)

# mSum(A, B)

print("Exercise 8:")
A = [[1, 2, 3], 
     [4, 5, 6]]

B = [[7, 8], 
     [9, 10], 
     [11, 12]]
def mProd(A, B):
    if (len(A[0]) != len(B)):
        print("Matrix dimension error")
        return
    # Create matrix C
    C = []
    
    m = len(A)
    n = len(A[0])
    q = len(B[0])
    for t in range(m):
        C.append([0] * q)
    print(C)
    # Calculate
    for i in range(m):
        for j in range(q):
            resSum = 0
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]

    print(C)

# mProd(A, B)

print("Exercise 8:")
def ithCombine(p, q):
    print("if " + p + ", then " + q)
def qanqCombine(p, q):
    qArr = q.split()
    s1 = qArr[0]
    # print(s1)
    qArr2 = []
    for i in range(len(qArr)):
        if (i != 0):
            qArr2.append(qArr[i])
    s2 = " ".join(qArr2)
    notQ = s1 + " not " + s2
    print(p + ", and " + notQ)
def npoqCombine(p, q):
    qArr = p.split()
    s1 = qArr[0]
    # print(s1)
    qArr2 = []
    for i in range(len(qArr)):
        if (i != 0):
            qArr2.append(qArr[i])
    s2 = " ".join(qArr2)
    notP = s1 + " not " + s2
    print(notP + ", or " + q)
p = "it sunny"
q = "I go camping"
ithCombine(p, q)
qanqCombine(p, q)
npoqCombine(p, q)