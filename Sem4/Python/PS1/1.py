def mostFrequent(string):
    freq = dict()
    for key in string:
        if key not in freq:
            freq[key] = 1
        else:
            freq[key] += 1

    return sorted(freq.items(),key=lambda item: item[1],reverse=True)

if __name__ == '__main__':
    print(mostFrequent('aaabbbcccdddeefffgggggg'))