# Exercise 1:
def checkTautology(table):
    for sta in table:
        if (sta == False):
            return False
    return True

def checkContradiction(table):
    for sta in table:
        if (sta == True):
            return False
    return True

p = True
q = False
r = True

prop3 = [
    (True, True, True),
    (True, True, False),
    (True, False, True),
    (True, False, False),
    (False, True, True),
    (False, True, False),
    (False, False, True),
    (False, False, False)]


def ex1():
    print("Exercise 1:")
    table1 = []
    table2 = []
    for p in prop3:
        exp1 = (((not p and q) and (q and r)) and not q)
        exp2 = ((not p or q) or (p and not q))
        table1.append(exp1)
        table2.append(exp2)
    if (checkTautology(table1)):
        print("Expression1 is Tautology")
    elif (checkContradiction(table1)):
        print("Expression1 is Contradiction")
    else:
        print("Expression1 is NOT Tautology, Contraction")
        
    if (checkTautology(table2)):
        print("Expression2 is Tautology")
    elif (checkContradiction(table2)):
        print("Expression2 is Contradiction")
    else:
        print("Expression2 is NOT Tautology, Contraction")
    print()
ex1()

# Exercise 2
def implication(p, q):
    if ((type(p) != bool) and (type(q) != bool)):
        print("input not boolean")
        return 
    return (not p or q)

def biconditional(p, q):
    if ((type(p) != bool) and (type(q) != bool)):
        print("input not boolean")
    return ((p and q) or (not p and not q))

def ex2():
    print("Exercise 2:")
    print("p | q | r | p ^ ~r ↔ q v r | (p → (q → r)) ↔ ((p ^ q) → r)")
    print("----------------------------------------------------------")
    for p, q, r in prop3:
        print(f"{p:<1} | {q:<1} | {r:<1} | {(biconditional(p and not r, q) or r):<14} | {(biconditional((implication(p, (implication(q, r)))), (implication((p and q), r)))):<0}")    
    print()
ex2()

# Exercise 3:
def ex3():
    print("Exercise 3:")
    print("p | q | r | p ^ (~q → r)")
    print("----------------------------------------------------------")
    for p, q, r in prop3:
        print(f"{p:<1} | {q:<1} | {r:<1} | {(p and (implication((not q), r))):<0}")
    print()

ex3()

def ex4_1():
    result1 = []
    result2 = []
    for p, q, r in prop3:
        expression1 = (p and (q or r))
        result1.append(expression1)
        expression2 = (p and q or (p and r))
        result2.append(expression2)
    # print(result1)
    # print(result2)
    checkSet = set()
    for i in range(len(result1)):
        if (result1[i] == result2[i]):
            checkSet = checkSet | {True}
        else:
            checkSet = checkSet | {False}
    if(((len(checkSet) == 1) and (True in checkSet))):
        print("True")
    else:
        print("False")
    

def ex4_2():
    result1 = []
    result2 = []
    for p, q, r in prop3:
        expression1 = (implication(p, (implication(p, r))))
        result1.append(expression1)
        expression2 = (implication((p and q), r))
        result2.append(expression2)
    # print(result1)
    # print(result2)
    checkSet = set()
    for i in range(len(result1)):
        if (result1[i] == result2[i]):
            checkSet = checkSet | {True}
        else:
            checkSet = checkSet | {False}
    if(((len(checkSet) == 1) and (True in checkSet))):
        print("True")
    else:
        print("False")
        
def ex4():
    print("Exercise 4:")
    ex4_1()
    ex4_2()
    print()
    
ex4()

def ex5():
    print("Exercise 5:")
    print("p | q | r | isValid")
    print("-------------------")
    for p, q, r in prop3: 
        permise1 = p or q
        permise2 = implication(p, (not q))
        permise3 = implication(p, r)
        conclusion = r
        
        if (((permise1 and permise2 and permise3) == True) and (conclusion == True)):
            isValid = True
        else:
            isValid = False
        print(f"{p:<1} | {q:<1} | {r:<1} | {isValid:<1}")
    print()

ex5()
