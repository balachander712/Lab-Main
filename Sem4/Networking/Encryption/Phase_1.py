#Transposition Cipher - Rail Fence Cryptography
def fence(lst, numrails):
    fence = [[None] * len(lst) for n in range(numrails)]
    rails = range(numrails) 
    for n, x in enumerate(lst):
        fence[rails[n % len(rails)]][n] = x
    print(fence)
    if 0: 
        for rail in fence:
            print(''.join('.' if c is None else str(c) for c in rail))

    return [c for rail in fence for c in rail if c is not None]

def encryption(text, n):
    return ''.join(fence(text, n))


def decryption(text, n):
    rng = range(len(text))
    pos = fence(rng, n)
    return ''.join(text[pos.index(n)] for n in rng)

if __name__ == '__main__':
    inp_str = input('Enter the string to encrypt : ')
    key = int(input('Enter the key : '))
    
    encrypted = encryption(inp_str,key)
    print(f'Encrypted string - {encrypted}')

    decrypted = decryption(encrypted,key)
    print(f'Decrypted string - {decrypted}')
