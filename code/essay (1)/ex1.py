from itertools import product

def Infix2Postfix(Infix):
    """
    Converts an infix logical expression to postfix (Reverse Polish Notation).
    
    Args:
        Infix (str): A string containing the infix logical expression.
    
    Returns:
        str: The postfix logical expression.
    """
    precedence = {
        '~': 4,  # NOT has the highest precedence
        '&': 3,  # AND and OR are coequal in precedence
        '|': 3,  
        '>': 1,  # IMPLIES and IFF are coequal in precedence
        '=': 1   
    }
    stack = []  # Stack to hold operators
    Postfix = []  # List to build the postfix expression

    for char in Infix:
        if char.isalpha():  # If the character is an operand (A-Z)
            Postfix.append(char)
        elif char == '(':
            stack.append(char)
        elif char == ')':
            while stack and stack[-1] != '(':
                Postfix.append(stack.pop())
            stack.pop()  # Remove the '(' from the stack
        else:  # The character is an operator
            while stack and stack[-1] != '(' and precedence[stack[-1]] >= precedence[char]:
                # Check for ambiguity when two operators of the same precedence are encountered
                if precedence[stack[-1]] == precedence[char]:
                    raise ValueError(f"Ambiguous expression: operators '{stack[-1]}' and '{char}' have the same precedence without parentheses.")
                Postfix.append(stack.pop())
            stack.append(char)

    # Pop any remaining operators in the stack
    while stack:
        Postfix.append(stack.pop())

    return ''.join(Postfix)

def Postfix2Truthtable(Postfix):
    """
    Generates and prints a truth table from a given postfix logical expression.
    
    Args:
        Postfix (str): A string containing the postfix logical expression.
    
    Returns:
        None: Prints the truth table directly.
    """
    # Extract unique variables from the postfix expression
    variables = sorted(set(filter(str.isalpha, Postfix)))
    num_vars = len(variables)
    
    # Generate all possible truth value combinations
    truth_combinations = list(product([False, True], repeat=num_vars))
    
    # Define logical operations
    def NOT(a): return not a
    def AND(a, b): return a and b
    def OR(a, b): return a or b
    def IMPLIES(a, b): return not a or b
    def IFF(a, b): return a == b
    
    # Map operators to their functions
    operations = {
        '~': lambda stack: stack.append(NOT(stack.pop())),
        '&': lambda stack: stack.append(AND(stack.pop(-2), stack.pop())),
        '|': lambda stack: stack.append(OR(stack.pop(-2), stack.pop())),
        '>': lambda stack: stack.append(IMPLIES(stack.pop(-2), stack.pop())),
        '=': lambda stack: stack.append(IFF(stack.pop(-2), stack.pop()))
    }
    print("-" * 30)
    print(" | ".join(variables) + " | Result")
    print("-" * 30)
    
    # Build and print the truth table
    for combination in truth_combinations:
        # Map variables to their truth values
        var_map = dict(zip(variables, combination))
        
        # Evaluate the postfix expression
        stack = []
        for char in Postfix:
            if char.isalpha(): 
                stack.append(var_map[char])
            elif char in operations:  
                operations[char](stack)
        
        # Print the row
        row = " | ".join(f"{int(var_map[var]):<5}" for var in variables) + f" | {int(stack[0]):<5}"
        print(row)
    
    # Print footer
    print("-" * 30)


test_cases = [
    "R|(P&Q)",
    "~P|(Q&R)>R",
    "P|(R&Q)",
    "(P>Q)&(Q>R)",
    "(P|~Q)>~P=(P|(~Q))>~P"
]

for i, infix in enumerate(test_cases, 1):
    try:
        postfix = Infix2Postfix(infix)
        print(f"Test Case {i}:")
        print(f"Infix: {infix}")
        print(f"Postfix: {postfix}")
        Postfix2Truthtable(postfix)
    except ValueError as e:
        print(f"Test Case {i}:")
        print(f"Infix: {infix}")
        print(f"Error: {e}")
    print("\n")