import cmath

def abs(num,flag):
    if flag:
        return (z.real**2 + z.imag**2)**0.5
    if not flag:
        if num > 0:
            return num
        elif num < 0:
            return -1 * num



if __name__ == '__main__':

    f = int(input('Press 1 for real number 2 for imaginary number '))
    if f == 1:
        num = int(input('Enter the real number '))
        print(abs(num,False))
    elif f == 2:
        x = int(input('Enter the real part '))
        y = int(input('Enter the imaginary part '))
        z = complex(x,y)
        print(abs(z,True))
