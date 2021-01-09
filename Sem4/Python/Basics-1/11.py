import math

def kaprekar(num):
    sq = num * num
    digits = int(math.log10(sq))+1
    n = digits / 2
    if digits % 2 == 1:
        n += 1
    right = sq % (10 ** n)
    left = sq / (10 ** n)

    if right + left == num:
        return True
    else:
        return False

if __name__ == '__main__':
    print(kaprekar(9))