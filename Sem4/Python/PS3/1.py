def removeConsonants(str):
    result = ""
    vowels = 'aeiouAEIOU'
    for i in str:
        if i not in vowels:
            result += i

    return result

if __name__ == '__main__':
    string = 'ahhjdfhueuwwi'
    print(removeConsonants(string))