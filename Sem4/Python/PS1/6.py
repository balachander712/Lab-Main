import itertools

def checkMetathesisPair(word1,word2):
    charList1 = []
    charList2 = []
    for x in range(len(word1)):
        if word1[x] != word2[x]:
            charList1.append(word1[x])
            charList2.append(word2[x])
        if len(charList2) == len(charList1) and len(charList1) == 2 and set(charList1) == set(charList2):
            return True

    return False

def findMetathesisPair(inputList):
    result = []
    pairs = list(itertools.combinations(inputList,2))
    for x,y in pairs:
        if len(x) == len(y):
            if checkMetathesisPair(x,y):
                result.append((x,y))
    return result


if __name__ == '__main__':
    inputList = [
        "converse","conserve",
        "something","something else",
        "abc","acb"
    ]

    # length = int(input('Enter the number of words '))
    # print('Enter the words ')
    # for i in range(length):
    #     word = input(f'{i + 1} : ')
    #     inputList.append(word)
    result = findMetathesisPair(inputList)
    print(result)