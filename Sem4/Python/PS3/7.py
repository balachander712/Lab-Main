import random


def countFrequency():
    randomNumbers = []
    for x in range(0,100):
        num = random.randint(1,50)
        randomNumbers.append(x)

    index = 0
    frequency = dict()

    for i in randomNumbers:
        freq = 0
        if randomNumbers[i] == randomNumbers[index]:
            freq = freq + 1
        frequency[randomNumbers[i]] = freq
        index = index + 1

    return frequency

if __name__ == '__main__':
    print(countFrequency())