"""
CA_LAB_TEST_1
SUBMITTED_BY
BALACHANDER G
19PW06

"""

import math

#the input data of internet users to calculate the mean and std_dev
internet_users = {
    '2016': 3424971237,
    '2015': 3185996155,
    '2014': 2956385569,
    '2013': 2728428107,
    '2012': 2728428107,
    '2010': 2023202974,
    '2009': 2023202974,
    '2008': 1575067520,
    '2007': 1373226988,
    '2006': 1162916818,
    '2005': 1030101289,
    '2004': 913327771,
    '2003': 781435983,
    '2002': 665065014,
    '2001': 502292245,
    '2000': 502292245,
}

#function to calculate the mean and standard deviation
def mean_std_dev():
    sum = 0
    average = 0
    std_dev = 0
    numerator = 0
    N = 17
    #calculating the sum 
    for value in internet_users.values():
        sum = sum + value
    
    average = sum/N
    #calculating the nr value for the std_dev
    for value in internet_users.values():
        numerator = numerator + (value - average)**2

    std_dev = math.sqrt(numerator/N)

    return average,std_dev


#driver code to test the function
if __name__ == '__main__':
    mean,std_dev = mean_std_dev()
    print(mean)
    print(std_dev)