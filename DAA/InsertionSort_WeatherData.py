
# weather data for 27th August 2020 [Sno, City, Time, Temp, Humidity, Rainfall]    
WeatherData = [[1, "Kolkata", "12:10", 27, 87, 15],
               [2, "Delhi", "02:30", 27, 56, 20],
               [3, "Pune", "13:45", 22, 34, 25],
               [4, "Bangalore", "10:10", 21, 36, 30],
               [5, "Mumbai", "10:05", 23, 30, 35],

               [6, "Kolkata", "14:10", 29, 41, 15],
               [7, "Bangalore", "15:33", 25, 51, 20],
               [8, "Pune", "17:13", 28, 32, 25],
               [9, "Delhi", "11:16", 31, 44, 30],
               [10, "Mumbai", "09:00", 21, 29, 35],

               [11, "Bangalore", "18:10", 28, 81, 15],
               [12, "Kolkata", "23:11", 31, 91, 20],
               [13, "Pune", "18:29", 29, 20, 25],
               [14, "Delhi", "09:09", 32, 21, 30],
               [15, "Mumbai", "12:30", 26, 22, 30],

               [16, "Bangalore", "03:32", 26, 22, 15],
               [17, "Pune", "12:19", 25, 23, 20],
               [18, "Delhi", "11:11", 29, 24, 25],
               [19, "Kolkata", "10:39", 28, 25, 30],
               [20, "Mumbai", "03:00", 19, 32, 40],

               [21, "Bangalore", "21:10", 23, 33, 15],
               [22, "Delhi", "22:10", 26, 66, 20],
               [23, "Kolkata", "08:09", 27, 55, 25],
               [24, "Pune", "01:41", 22, 23, 30],
               [25, "Mumbai", "13:45", 29, 20, 25],

               [26, "Delhi", "12:11", 30, 23, 20],
               [27, "Kolkata", "11:00", 28, 27, 36],
               [28, "Bangalore", "03:10", 19, 20, 21],
               [29, "Pune", "13:30", 31, 55, 44],
               [30, "Mumbai", "19:35", 21, 40, 50],

               [31, "Kolkata", "10:10", 26, 50, 70],
               [32, "Pune", "01:41", 22, 23, 30],
               [33, "Delhi", "12:11", 30, 23, 20],
               [34, "Mumbai", "13:00", 25, 31, 31],
               [35, "Bangalore", "00:20", 19, 20, 21],

               [36, "Delhi", "14:30", 32, 50, 40],
               [37, "Kolkata", "12:10", 32, 40, 60],
               [38, "Pune", "02:00", 21, 30, 45],
               [39, "Mumbai", "00:10", 20, 50, 65],
               [40, "Bangalore", "00:00", 18, 20, 31],

               [41, "Delhi", "23:25", 27, 22, 11],
               [42, "Kolkata", "21:00", 26, 28, 38],
               [43, "Bangalore", "23:10", 20, 28, 21],
               [44, "Mumbai", "23:05", 21, 32, 38],
               [45, "Pune", "12:45", 21, 45, 55],

               [46, "Kolkata", "15:50", 30, 90, 95],
               [47, "Delhi", "23:59", 22, 80, 96],
               [48, "Pune", "17:00", 25, 25, 21],
               [49, "Bangalore", "23:30", 20, 32, 31],
               [50, "Mumbai", "22:00", 21, 50, 55]]

def InsertionSort(arr, x):
    for i in range(1, len(arr)):
        key = arr[i][x]
        j = i-1
        keyPosition = arr[i]
        while (j >= 0) and (arr[j][x] > key):
            arr[j+1] = arr[j]
            j = j-1

        arr[j+1] = keyPosition
#First the raw data is sorted on time
InsertionSort(WeatherData, 2)
print("Sorted data in ascending order with respect to TimeStamp:")
for data in range(0, len(WeatherData)):
    print(WeatherData[data])
    
print("\n")
#The data is sorted on city showing that insertion sort is a stable sort algorithm
InsertionSort(WeatherData, 1)
print("Sorted data in ascending order with respect to City name")
for data in range(0, len(WeatherData)):
    print(WeatherData[data])

#Looking at "40 Bangalore & 35 Bangalore" as an example, they are stable sorted.





