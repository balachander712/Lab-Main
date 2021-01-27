def retNormalised(data):
    return [float(i)/sum(data) for i in data]

if __name__ == '__main__':
    data = [4,5,6]
    print(retNormalised(data))