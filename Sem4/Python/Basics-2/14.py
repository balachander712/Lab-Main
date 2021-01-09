def removeDuplicates(lst):
    set1 = set(lst)
    return list(set1)

if __name__ == '__main__':
    lst = [1,2,3,4,5,5,6,7,7,8,9]
    print(removeDuplicates(lst))