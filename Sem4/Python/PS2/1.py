if __name__ == '__main__':
    for i in range(0,100):
        if i % 3 == 0:
            print(i, " Fizz")
        elif i % 5 == 0:
            print(i, ' Buzz')

        if i % 3 == 0 and i % 5 == 0:
            print(i, ' FizzBuzz')