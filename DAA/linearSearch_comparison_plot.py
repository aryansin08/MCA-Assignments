#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import random
import seaborn as sns
import matplotlib.pyplot as plt

def linSearch(arr, key):
    '''
       Objective: To find the number of comparisons for n+1 different keys for an array of size n.
       Input: arr - A randomly generated array of unique numbers.
              item - The key to be searched.
       Return Value: Number of comparisons or simply the position of the element
    '''
    for i in range(len(arr)):
        if(arr[i] == key):
            return i+1
    return len(arr)+1


currCom = []
minCom = []
maxCom = []
avgCom = []
arrSearch = np.array([])
tempArr = []
arrKey = []

sizeArray = np.array(range(10, 101, 5))
for i in sizeArray:
    
#     creating a random array of size n with unique values
    arrSearch = random.sample(range(i),i)
    
#     creating an array for n+1 keys
    arrKey = random.sample(range(i+1), i+1)
    
#     storing the number of comparisons required for each key in every iteration
    for j in arrKey:
        x = linSearch(arrSearch, j)
        currCom.append(x)
        tempArr = np.array(currCom)
        
#     storing values of the minimum, maximum and average number of comparisons for each array size
    minCom.append(np.amin(tempArr))
    maxCom.append(np.amax(tempArr))
    avgCom.append(np.average(tempArr))

ax =sns.lineplot(sizeArray,avgCom)
sns.lineplot(sizeArray,minCom)
sns.lineplot(sizeArray,maxCom)
ax.set_xlabel("Array Size")
ax.set_ylabel("No of Comparisons")
ax.legend(['Average Case','Best Case','Worst Case'])
ax.set_title("Array Size v/s Key-Comparisons")
ax.figure.set_size_inches(10,6)
sns.despine() 
plt.show()
        


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




