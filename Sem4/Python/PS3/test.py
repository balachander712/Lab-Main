vowel = ['a','e','i','o','u'] 
my_list = ['hbyl','hawk','ibzj','hcxk','gawk']
vowset = set(vowel)
[word for word in my_list if not vowset.intersection(word)]
print(my_list)