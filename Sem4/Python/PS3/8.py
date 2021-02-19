def cipher(text,shift):
    result = ""

    for i in range(len(text)):
        char = text[i]

        if ord(char) == 32:
            result += " "
        else:
            result += chr((ord(char) + shift - 97) % 26 + 97)

    return result


if __name__ == '__main__':
    string = input('Enter the string ')
    print(cipher(string,4))