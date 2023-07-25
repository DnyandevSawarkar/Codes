# Question:
# Write a Python function that takes two numpy arrays of same size and
# returns a new numpy array with the elements that are present in both 
# arrays, but only once. If an element appears more than once in either 
# array, it should not be included in the output array.

# arr1 = [1, 3, 5, 7, 9]
# arr2 = [2, 3, 4, 7, 8]

# Output: [3, 7]

#Solution:

import numpy as np

def unique_elements(arr1, arr2):
    # Find unique elements in both arrays
    unique_arr1 = np.unique(arr1)
    unique_arr2 = np.unique(arr2)

    # Find common elements between the two arrays
    common_elements = np.intersect1d(unique_arr1, unique_arr2)

    # Create a new array with the common elements that occur only once
    unique_elements_arr = np.array([])

    for element in common_elements:
        if np.count_nonzero(unique_arr1 == element) == 1 and np.count_nonzero(unique_arr2 == element) == 1:
            unique_elements_arr = np.append(unique_elements_arr, element)

    return np.intc(unique_elements_arr)

arr1 = np.array([1, 3, 5, 7, 9])
arr2 = np.array([2, 3, 4, 7, 8])
unique_arr = unique_elements(arr1, arr2)
print(unique_arr)