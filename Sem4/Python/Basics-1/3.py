sum = 0
string = input("Enter the value of a: ")
a = string
for i in range(4):
    sum += int(string)
    string += a
print(sum)