def changeName(name):

    tempName = name.split(' ')
    abbr = tempName[0][0] + "." + tempName[1][0] + "." + tempName[2]
    return abbr

if __name__ == '__main__':
    print(changeName('Robert Brett Roser'))