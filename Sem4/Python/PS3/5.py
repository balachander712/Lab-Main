import math

def sumOfSeries(n):
    return 0.0246 * (math.pow(10, n) - 1 - (9 * n))

if __name__ == '__main__':
    print(sumOfSeries(3))