# Taking marks input separated by spaces (like C++ cin)
# Direct conversion: input string → split → convert to float list
marks = [float(mark) for mark in input("Enter marks separated by spaces: ").split()]

print("Marks entered:", marks)
print(f"Number of marks: {len(marks)}")
highest_mark = max(marks)
lowest_mark = min(marks)
average_mark = sum(marks) / len(marks) if marks else 0