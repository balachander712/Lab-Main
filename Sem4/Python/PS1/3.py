def base_freq(dna):
    freq = dict()
    for key in dna:
        if key not in freq:
            freq[key] = 1
        else:
            freq[key] += 1

    return sorted(freq.items(),key=lambda item: item[0])



if __name__ == '__main__':
   print(base_freq("AAGTTAGTCA"))