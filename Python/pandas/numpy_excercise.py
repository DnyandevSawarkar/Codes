'''
Question 1
'''
# Create a 2D array of shape 10x7 to contain random decimal numbers between user defined ranges.


# Solution

# Step 1: Import the libraries required
import numpy as np

# Step 2: Take the user input for the range values
minVal = int(input("Enter the minimum range value: "))
maxVal = int(input("Enter the maximum range value: "))

# Step 3: Get the array
# Solution 1
rand_arr = np.random.randint(low=minVal, high=maxVal, size=(10,7)) + np.random.random((10,7))

# Solution 2
rand_arr = np.random.uniform(minVal,maxVal, size=(10,7))

# Step 4: Print the output
print(rand_arr)

'''
Question 2
'''
# Convert a 1-D array which the user inputs into a 3-D array


# Solution

# Step 1: Import the libraries required
import numpy as np

# Step 2: Take the user for the 1-D array
try:
    arr = []

    while True:
        arr.append(int(input("Enter the element of array: ")))
except:
    arr = np.array(arr)

# Step 3: Convert the array into 3-D array
arr = arr.reshape((3, 3, 3))

# Step 4: Print the output
print(arr)