import time
import matplotlib.pyplot as plt
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
from Crypto.Random import get_random_bytes

def generate_keys():
    """
    Generate RSA public and private keys.
    """
    key = RSA.generate(2048)
    private_key = key.export_key()
    public_key = key.publickey().export_key()
    return private_key, public_key

def encrypt_message(public_key, message):
    """
    Encrypt a message using the RSA public key.
    Supports splitting the message into smaller chunks if necessary.
    """
    rsa_key = RSA.import_key(public_key)
    cipher = PKCS1_OAEP.new(rsa_key)
    chunk_size = rsa_key.size_in_bytes() - 42  # Maximum chunk size for PKCS1_OAEP
    ciphertext = b""

    for i in range(0, len(message), chunk_size):
        chunk = message[i:i + chunk_size]
        ciphertext += cipher.encrypt(chunk)

    return ciphertext

def decrypt_message(private_key, ciphertext):
    """
    Decrypt a ciphertext using the RSA private key.
    Supports combining decrypted chunks into the original message.
    """
    rsa_key = RSA.import_key(private_key)
    cipher = PKCS1_OAEP.new(rsa_key)
    chunk_size = rsa_key.size_in_bytes()
    plaintext = b""

    for i in range(0, len(ciphertext), chunk_size):
        chunk = ciphertext[i:i + chunk_size]
        plaintext += cipher.decrypt(chunk)

    return plaintext

def measure_performance():
    """
    Measure encryption and decryption time for different plaintext message lengths.
    """
    private_key, public_key = generate_keys()
    message_lengths = list(range(0,5121, 256))  # Các giá trị từ 1 đến 100  
    encryption_times = []
    decryption_times = []
    print(f"{'Length':>7} |   {'Encryption time':>15}|{'Decryption time':>15}")
    print("---------------------------------------------")
    for length in message_lengths:
        message = get_random_bytes(length)  # Generate random plaintext of given length
        
       
        # Measure encryption time
        start_time = time.time()
        ciphertext = encrypt_message(public_key, message)
        encryption_times.append(time.time() - start_time)

        # Measure decryption time
        start_time = time.time()
        decrypt_message(private_key, ciphertext)
        decryption_times.append(time.time() - start_time)
        print(f"{length:>7} |   {encryption_times[-1]:>15.6f}|{decryption_times[-1]:>15.6f}")        

    # Plot the results
    plt.figure(figsize=(10, 6))
    plt.plot(message_lengths, encryption_times, label="Encryption Time", marker='o')
    plt.plot(message_lengths, decryption_times, label="Decryption Time", marker='o')
    plt.xlabel("Plaintext Message Length (bytes)")
    plt.ylabel("Time (seconds)")
    plt.title("RSA Encryption and Decryption Time vs Message Length")
    plt.legend()
    plt.grid()
    plt.show()

# Generate RSA keys
private_key, public_key = generate_keys()

# Test encryption and decryption
message = b"Hello, RSA!"
print("Original Message:", message)
print("---------------------------------------------")
# Encrypt the message
ciphertext = encrypt_message(public_key, message)
print("Encrypted Message:", ciphertext)
print("---------------------------------------------")

# Decrypt the message
decrypted_message = decrypt_message(private_key, ciphertext)
print("Decrypted Message:", decrypted_message)
print("---------------------------------------------")

# Verify the results
assert message == decrypted_message, "Decryption failed!"

# Measure performance
measure_performance()