def thirdList(lst):

    oddList = lst[1::2]
    evenList = lst[0::2]
    return oddList,evenList

if __name__ == '__main__':
    print(thirdList([1,2,3,4,5]))