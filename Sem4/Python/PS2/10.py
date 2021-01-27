def countDigits(digit):
    count = 1
    while True:
        num = digit/10
        if num < 1:
            break

        count = count + 1
        digit = digit/10

    return count

if __name__ == '__main__':
    print(countDigits(int(123)))

