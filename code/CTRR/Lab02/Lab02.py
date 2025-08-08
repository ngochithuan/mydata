# Tutorial 1
# Propositions
p = True # Proposition p is true
q = False # Proposition q is false
# Print the values of p and q
print(f"Proposition p: {p}")
print(f"Proposition q: {q}")

# Tutorial 2.1
# AND operation (Conjunction)
p_and_q = p and q
print(f"p AND q: {p_and_q}")
# OR operation (Disjunction)
p_or_q = p or q
print(f"p OR q: {p_or_q}")
# NOT operation (Negation)
not_p = not p
print(f"NOT p: {not_p}")

# Tutorial 2.2
# Implication: p → q
implication = not p or q # Equivalent to: if p is true, then q must be true
print(f"p → q (Implication): {implication}")

# Tutorial 2.3
# Biconditional: p ↔ q
biconditional = (p and q) or (not p and not q) # Equivalent to: p if and only if q
print(f"p ↔ q (Biconditional): {biconditional}")

# Tutorial 3
# List of all possible truth values for p and q
propositions = [(True, True), (True, False), (False, True), (False, False)]
print("p | q | p AND q | p OR q | p → q")
print("--------------------------------------------")
for p, q in propositions:
 p_and_q = p and q
 p_or_q = p or q
 implication = not p or q
 print(f"{p:<5} | {q:<5} | {p_and_q:<8} | {p_or_q:<8} | {implication}")
 
# Tutorial 4
 # Tautology: p OR NOT p is always true
tautology = p or not p
print(f"Tautology (p OR NOT p): {tautology}")
# Contradiction: p AND NOT p is always false
contradiction = p and not p
print(f"Contradiction (p AND NOT p): {contradiction}") 

# Exercise 1
def implication(p, q):
    if ((type(p) != bool) and (type(q) != bool)):
        print("input not boolean")
        return 
    return (not p or q)

def ex1(p, q, r):
    # print(implication(p, q))
    if ((type(p) != bool) and (type(q) != bool) and (type(r) != bool)):
        print("input not boolean")
        return
    print("p → q:")
    if(implication(p, q) == True):
        print(True)
    else:
        print(False)
    print("NOT p AND q:")
    if ((not p and q) == True):
        print(True) 
    else:
        print(False)
    print("p AND (q AND r):")
    if (p and (q and r) == True):
        print(True)
    else:
        print(False)
    print("p AND (NOT q OR r):")
    if ((p and (not q or r)) == True):
        print(True)
    else:
        print(False)
    
ex1(False, True, True)

def ex2():
    print("Exercise 2:")
    propositions = [(True, True), (True, False), (False, True), (False, False)]
    print("p | q |  NOT p | p AND q | p OR q | p → q | NOT p AND q | NOT p OR q → NOT q | (p OR q) OR (NOT p AND q) → q")
    print("-------------------------------------------------------------------------------------------------------------")
    for p, q in propositions:
        print(f"{p:<1} | {q:<1} | {(not p):<6} | {(p and q):<7} | {(p or q):<6} | {implication(p, q):<5} | {(not p and q):<11} | {(implication((not p or q), (not q))):<18} | {implication(((p or q) or (not p and q)), (q))}")

ex2()

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

def check3_1():
    propositions = [True, False]
    table = []
    for p in propositions:
        expression = (p or not p)
        table.append(expression)
    if (checkTautology(table) == True):
        print("p v ~p: " + "tautology")
    elif (checkContradiction(table) == True):
        print("p v ~p: " + "contradiction")
    else:
        print("p v ~p: " + "NOT tautology/contradiction")
        
def check3_2():
    propositions = [True, False]
    table = []
    for p in propositions:
        expression = (p and not p)
        table.append(expression)
    if (checkTautology(table) == True):
        print("p ^ ~p: " + "tautology")
    elif (checkContradiction(table) == True):
        print("p ^ ~p: " + "contradiction")
    else:
        print("p ^ ~p: " + "NOT tautology/contradiction")

def check3_3():
    propositions = [(True, True), (True, False), (False, True), (False, False)]
    table = []
    for p, q in propositions:
        expression = ((p and q) or (not p or (p and not q)))
        table.append(expression)
    Str = "(p ^ q) v (~p v (p ^ ~q))"
    if (checkTautology(table) == True):
        print(Str + " tautology")
    elif (checkContradiction(table) == True):
        print(Str + " contradiction")
    else:
        print(Str + " NOT tautology/contradiction")    

def check3_4():
    propositions = [(True, True), (True, False), (False, True), (False, False)]
    table = []
    for p, q in propositions:
        expression = ((p and not q) and (not p or q))
        table.append(expression)
    Str = "(p ^ ~q) ^ (~p v q) "
    if (checkTautology(table) == True):
        print(Str + " tautology")
    elif (checkContradiction(table) == True):
        print(Str + " contradiction")
    else:
        print(Str + " NOT tautology/contradiction") 

def ex3():
    print("Exercise 3+4:")
    check3_1()
    check3_2()
    check3_3()
    check3_4()
ex3()

def biconditional(p, q):
    return ((p and q) or (not p and not q))

def ex5():
    print("Exercise 5:")
    propositions = [
    (True, True, True),
    (True, True, False),
    (True, False, True),
    (True, False, False),
    (False, True, True),
    (False, True, False),
    (False, False, True),
    (False, False, False)]
    print("p | q | r | p ↔ q | (p → r) ↔ (q → r)")
    print("-------------------------------------")
    for p, q, r in propositions:
        print(f"{p:<1} | {q:<1} | {r:<1} | {biconditional(p, q):<5} | {biconditional((implication(p, r)), (implication(q, r))):<1}")
ex5()

def ex6():
    print("Exercise 6:")
    propositions = [
    (True, True, True),
    (True, True, False),
    (True, False, True),
    (True, False, False),
    (False, True, True),
    (False, True, False),
    (False, False, True),
    (False, False, False)]
    print("p | q | r | p ^ (q ^ r) | p ^ (~q v r) | p → (q ^ r)")
    print("----------------------------------------------------")
    for p, q, r in propositions:
        print(f"{p:<1} | {q:<1} | {r:<1} | {p and (q and r):<11} | {p and (not q or r):<12} | {implication(p, (q and r)):<5}")
ex6()

def ex7_1():
    propositions = [(True, True), (True, False), (False, True), (False, False)]
    result1 = []
    result2 = []
    for p, q in propositions:
        expression1 = implication(p, q)
        result1.append(expression1)
        expression2 = (not p or q)
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

def ex7_2():
    propositions = [
    (True, True, True),
    (True, True, False),
    (True, False, True),
    (True, False, False),
    (False, True, True),
    (False, True, False),
    (False, False, True),
    (False, False, False)]
    result1 = []
    result2 = []
    for p, q, r in propositions:
        expression1 = implication(p, (q or r))
        result1.append(expression1)
        expression2 = implication((p and (not q)), r)
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
        

def ex7():
    print("Exercise 7:")
    ex7_1()
    ex7_2()
ex7()

def ex8():
    print("Exercise 8:")
    propositions = [
    (True, True, True),
    (True, True, False),
    (True, False, True),
    (True, False, False),
    (False, True, True),
    (False, True, False),
    (False, False, True),
    (False, False, False)]
    print("p | q | r | isValid")
    print("-------------------")
    for p, q, r in propositions: 
        permise1 = implication(p, q)
        permise2 = implication(q, r)
        permise3 = p
        conclusion = r
        
        if (((permise1 and permise2 and permise3) == True) and (conclusion == True)):
            isValid = True
        else:
            isValid = False
        print(f"{p:<1} | {q:<1} | {r:<1} | {isValid:<1}")
        
ex8()
