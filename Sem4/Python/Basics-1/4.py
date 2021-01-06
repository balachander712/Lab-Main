str1 = input('Enter the string ')
index = int(input('Enter the index'))
char = input('Enter the character')


str2 = list(str1)
str2[index] = char
str1 = ''.join(str2)
print(str1)