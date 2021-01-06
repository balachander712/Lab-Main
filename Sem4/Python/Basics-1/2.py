website = ["www.zframez.com", "www.wikipedia.org", "www.asp.net", "www.abcd.in"]

# total = int(input('Enter the number of websites '))
#
# for i in range(0,total):
#     str = input('Enter the website ')
#
#     website.append(str)

for web in website:
    str = web.split('.')
    print(str[2])