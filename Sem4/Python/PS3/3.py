def chunks(lst):
    for i in range(0,len(lst),3):
        yield lst[i:i+3]


if __name__ == '__main__':
    lst = [1,2,3,4,5,6,7,8,9]
    chunks_results = chunks(lst)
    for chunk in chunks_results:
        chunk_list = list(chunk)
        print(chunk_list[::-1])