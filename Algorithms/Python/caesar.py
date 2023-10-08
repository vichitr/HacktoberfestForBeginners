def caesar_cipher(text, shift):
    result = ""
    
    for char in text:
        if char.isalpha():
            if char.isupper():
                start = ord('A')
            else:
                start = ord('a')
            
            shifted_char = chr((ord(char) - start + shift) % 26 + start)
            
            result += shifted_char
        else:
            result += char
    
    return result

plaintext = input("Enter the text: ")
shift = int(input("Enter the shift value (an integer): "))

cipher_text = caesar_cipher(plaintext, shift)

print("Original Text:", plaintext)
print("Caesar Cipher:", cipher_text)
