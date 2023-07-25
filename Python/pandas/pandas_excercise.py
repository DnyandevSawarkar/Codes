'''
Question 1
'''
# Find the positions of numbers that are multiples of n given as an input from the user from series which is randomly generated


# Solution

# Step 1: Import the required libraries
import numpy as np
import pandas as pd

# Step 2: Take the user input for the multiple
inp = int(input("Enter the number for which the multiples need to be searched for: "))

# Step 3: Generate a random dataframe
series = pd.Series(np.random.randint(1, 10, 12))

print(f"Series generated: {series}")
# Step 4: Find the position of multiples
positions = np.where(series % inp == 0)

# Step 5: Print the output
print(positions)

'''
Question 2
'''
# Write a Pandas program to create and display a DataFrame from a specified dictionary data which has the index labels

# Step 1: Import the required libraries
import pandas as pd

# Step 2: Define the data
exam_data = {   'name': ['Anastasia', 'Dima', 'Katherine', 'James', 'Emily', 'Michael', 'Matthew', 'Laura', 'Kevin', 'Jonas'],
                'score': [12.5, 9, 16.5, np.nan, 9, 20, 14.5, np.nan, 8, 19],
                'attempts': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
                'qualify': ['yes', 'no', 'yes', 'no', 'no', 'yes', 'yes', 'no', 'no', 'yes']
}

# Step 3: Define the labels
labels = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']

# Step 4: Create the dataframe
df = pd.DataFrame(exam_data , index=labels)

# Step 5: Print the output
print(df)