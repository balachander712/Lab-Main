"""
CA_LAB_TEST_1
SUBMITTED_BY
BALACHANDER G
19PW06

"""

#function to get the percentage of year wise internet users
def get_year_wise_users(input_data):
    year_list = []
    #getting they years from the input data and storing in a seperate list
    for i in range(len(input_data)):
        if input_data[i][0] not in year_list:
            year_list.append(input_data[i][0])
    world_population = 0
    #calculating the sum of internet users
    for year in year_list:
        sum_of_internet_users = 0
        for i in range(len(input_data)):
            if year == input_data[i][0]:
                sum_of_internet_users += int(input_data[i][1])
                world_population = int(input_data[i][2])
        #calculating the percentage and printing the percentage of internet and non internet users
        year_percentage = (sum_of_internet_users/world_population)*100
        print(f"The Percentage of internet users in the year {year} is {year_percentage}.")
        print(f"The Percentage of non internet users in the year {year} is {100-year_percentage}.")

#function to get the percentage of reggion wise internet users
def get_region_wise_users(input_data):
    region_list = []
    for i in range(len(input_data)):
        if input_data[i][3] not in region_list:
            region_list.append(input_data[i][3])
    world_population = 0
    for region in region_list:
        sum_of_internet_users = 0
        for i in range(len(input_data)):
            if region == input_data[i][3]:
                sum_of_internet_users += int(input_data[i][1])
                world_population += int(input_data[i][2])
        #calculating the percentage and printing the percentage of internet and non internet users
        region_percentage = (sum_of_internet_users/world_population)*100
        print(f"The Percentage of internet users in the region {region} is {region_percentage}.")
        print(f"The Percentage of non internet users in the region {region} is {100-region_percentage}.")


#driver code to test the above function
if __name__  == "__main__":
    input_list = []
    entry_count = int(input("Enter the number of inputs: "))
    count = 0
    while count < entry_count:
        input_data = input("Enter the data in the following form YEAR INTERNET_USERS WORLD_POPULATION REGION: ").split()
        input_list.append(input_data)
        count += 1
    get_year_wise_users(input_list)
    get_region_wise_users(input_list)

