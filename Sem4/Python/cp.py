if __name__ == '__main__':
    n,l = input().split()
    n = int(n)
    l = int(l)
    locations = list(map(int, input().split()))
    locations.sort()
    rad = max(locations[0],(l - locations[-1]))
    for i in range(n-1):
        dist = (locations[i+1] - locations[i])/2
        rad = max(rad,dist)

    print(f'{rad:.10f}')