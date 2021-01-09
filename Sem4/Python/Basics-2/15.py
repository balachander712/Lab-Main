import random

def passwordGenerator(len):
    chars = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()?'
    password = ''.join(random.sample(chars,len))
    return password


if __name__ == '__main__':
    len = int(input('Enter the length of the password '))
    print(passwordGenerator(len))