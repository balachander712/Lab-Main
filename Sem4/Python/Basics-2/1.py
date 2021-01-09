sequence = input('Enter the word ').split(' ')

words = []

for i in sequence:
    if i not in words:
        words.append(i)
    else:
        continue

words.sort()
sequence = (' ').join(words)
print(sequence)