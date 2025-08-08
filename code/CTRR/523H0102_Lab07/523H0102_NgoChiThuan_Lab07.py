def GCD(a,b):
    if a==0:
        return b
    return GCD(b%a,a)

print(GCD(22,11))

def gcdExtended(a, b):
    if a == 0: 
        return b, 0, 1
    gcd, x1, y1 = gcdExtended(b % a, a)
    x = y1 - (b // a) * x1
    y = x1    
    return gcd, x, y

def findGCD(a, b):
    return gcdExtended(a, b)

print(findGCD(2,13))

def modInverse(a, n):
    gcd, x, _ = gcdExtended(a, n)
    if gcd != 1: 
        return None
    return x % n  

print(modInverse(7, 22))  

def findModInverses(numbers, n):
    return {num: modInverse(num, n) for num in numbers}


numbers = [2, 5, 6, 8]
n = 3
print(findModInverses(numbers, n))

def coprimesAndInverses(n):
    coprimes = [a for a in range(1, n) if gcdExtended(a, n)[0] == 1]
    inverses = {a: modInverse(a, n) for a in coprimes}
    return inverses

n = 11
print(coprimesAndInverses(n))

def multiplicativeCipherDecrypt(ciphertext, a, n):
    a_inv = modInverse(a, n)
    if a_inv is None:
        return None  
    
    decrypted_text = "".join(
        chr(((a_inv * (ord(char) - ord('A'))) % n) + ord('A')) if char.isalpha() else char
        for char in ciphertext
    )
    return decrypted_text

def bruteForceMultiplicativeCipher(ciphertext, n):
    candidates = {}
    for a in range(1, n):
        if gcdExtended(a, n)[0] == 1: 
            decrypted = multiplicativeCipherDecrypt(ciphertext, a, n)
            if decrypted:
                candidates[a] = decrypted
    return candidates

ciphertext = "WTAAD"
n = 12
print(bruteForceMultiplicativeCipher(ciphertext, n))


def affineDecryptionKey(a, b, n):
    a_inverse = modInverse(a, n)
    if a_inverse is None:
        return None 
    b_inverse = (-b * a_inverse) % n
    return a_inverse, b_inverse

a, b, n = 5, 8, 26
print(affineDecryptionKey(a, b, n))

def affineEncrypt(text, a, b, n):
    encrypted_text = "".join(
        chr(((a * (ord(char) - ord('A')) + b) % n) + ord('A')) if char.isalpha() else char
        for char in text.upper()
    )
    return encrypted_text

def affineDecrypt(cipher_text, a, b, n):
    a_inverse = modInverse(a, n)
    decrypted_text = "".join(
        chr(((a_inverse * (ord(char) - ord('A') - b)) % n) + ord('A')) if char.isalpha() else char
        for char in cipher_text.upper()
    )
    return decrypted_text

a, b, n = 5, 8, 26
plaintext = "FRITTO"
ciphertext = affineEncrypt(plaintext, a, b, n)
decrypted_text = affineDecrypt(ciphertext, a, b, n)

print(f"Ciphertext: {ciphertext}")
print(f"Decrypted: {decrypted_text}")

def computeRSA_privateExponent(p, q, b):
    phi_n = (p - 1) * (q - 1)  
    a = modInverse(b, phi_n)  
    return a

p, q, b = 61, 12, 2
private_exponent = computeRSA_privateExponent(p, q, b)
print(f"Private exponent: {private_exponent}")



