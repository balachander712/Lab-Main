def encode(msg):

    encodesMsg = ""
    i = 0
    while i < len(msg):
        count = 1
        while i + 1 < len(msg) and msg[i] == msg[i+1]:
            count = count + 1
            i = i + 1

        encodesMsg += str(count) + msg[i]
        i = i + 1

    return encodesMsg

encodedMessage = encode('WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW')
print(encodedMessage)