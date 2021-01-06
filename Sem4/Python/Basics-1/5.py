def checkPrime(num):
    if num > 1:
        for i in range(2,num):
            if num % i == 0:
                return True

    return False

if __name__ == "__main__":
    for i in range(1,50):
        if checkPrime(i):
            continue
        print(i)