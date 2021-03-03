sample_list = ['hey','there','how','are','you','rtgf']
vowels = 'aeiou'

for word in sample_list:
    flag = 0
    for letter in word:
        if letter in vowels:
            flag = 1

    if flag == 0:
        sample_list.remove(word)

print(sample_list)