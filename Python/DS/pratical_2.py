import csv
import random
import os

current_directory = os.getcwd()
# Function to generate random data
def generate_random_data(num_entries):
    data = []
    for _ in range(num_entries):
        sex = random.choice(["Male", "Female"])
        age = random.randint(14, 22)
        grade = random.randint(1, 12)
        family_members = random.randint(1, 10)
        data.append([sex, age, grade, family_members])
    return data

# Number of random entries to generate
num_entries = 200

# Generate random data
random_data = generate_random_data(num_entries)

# Specify the CSV file name
csv_file = "Pratical_2.csv"

# Write the data to a CSV file
with open(csv_file, "w", newline="") as file:
    writer = csv.writer(file)
    writer.writerow(["Gender", "Age", "Grade", "No. of Family Members"])
    writer.writerows(random_data)

csv_file_path = os.path.join(current_directory, csv_file)

print(f"The CSV file is saved at: {csv_file_path}")

print(f"Random data saved to {csv_file}")
