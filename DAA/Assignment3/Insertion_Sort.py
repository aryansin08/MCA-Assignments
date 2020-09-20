#!/usr/bin/env python
# coding: utf-8

# In[29]:


import pandas as pd

# reading unsorted meteorological data csv file
weather_data_unsorted = pd.read_csv('WeatherData.csv')
 
# creating an index table from the original table 
index_table_unsorted = weather_data_unsorted[['Index','City']].to_dict(orient='records')
pd.DataFrame(index_table_unsorted).set_index('Index').to_csv('index_table_unsorted.csv')


def insertion_sort(index_table):
    
    '''
    Function to sort input data using Insertion Sort

    Input: Weather Data(index, city_name) sorted on time

    Output: Weather Data(index, city_name) sorted on city _name
    '''
    
    index_table = index_table.copy()
    for index in range(1,len(index_table)):
        
        key = index_table[index]
        j=index-1
        
        while(j>=0 and index_table[j]['City']>key['City']):
            index_table[j+1] = index_table[j]
            j-=1
        index_table[j+1] = key
        
    return index_table

# sorting index_table on city name
index_table_sorted = insertion_sort(index_table_unsorted)
pd.DataFrame(index_table_sorted).set_index('Index').to_csv('index_table_sorted.csv')
# Using indices of sorted index table to arrange the original weather data in sorted order    
sorted_indices = list(pd.DataFrame(index_table_sorted)['Index'])
# weather_data_sorted = weather_data_unsorted.set_index('Index').iloc[sorted_indices]

# weather_data_sorted.to_csv('WeatherData_Sorted.csv')


# In[ ]:





# In[ ]:




