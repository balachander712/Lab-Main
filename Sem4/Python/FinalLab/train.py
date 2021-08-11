'''
Balachander G
MSc SS Final Semester Lax Examination
'''

import pandas as pd 

#creating pandas dataframe
df = pd.read_excel('Train.xlsx')
#print(df)


#Qn 1
print('Printing the customers whose warehouse block is F')
warehouse = df[(df.Warehouse_block=='F')]
print(warehouse)

#Qn2
print(f"\nThe number of customers whose Customer-rating is the highest (Best) are {df[df.Customer_rating==5].shape[0]}.")

#Qn 3
male_customers = df["Gender"].value_counts().to_dict()["M"]
total_customers = df["Gender"].value_counts().to_dict()["M"] + df["Gender"].value_counts().to_dict()["F"]
print(f'The percentage of male customers is {(male_customers/total_customers)*100}')
print(f'The percentage of female customers is {100-((male_customers/total_customers)*100)}')


#Qn 4
reached_on_time_dict = df["Reached.on.Time_Y.N"].value_counts().to_dict()
if 0 not in reached_on_time_dict:
    reached_on_time = 0
else:
    reached_on_time = reached_on_time_dict[0]

print(f'Ratio of customers whose product has reached on time is {reached_on_time/df["Reached.on.Time_Y.N"].shape[0]}.\n')


#Qn 5
print('The cost of the product is ')
print(df['Cost_of_the_Product'])
print('The discounted price is')
df['discount_cost'] = df['Cost_of_the_Product'] - df['Discount_offered']
print(df[["Cost_of_the_Product", "discount_cost"]])
