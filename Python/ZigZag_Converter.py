#Leetcode Problem 6
#Zigzag Conversion
#Medium

def convert(s: str, numRows: int) -> str:
    if numRows < 2:
        return s
    row_string = [""] * numRows
    curr_row = 0
    step = 1
    for i in s:
        row_string[curr_row] += i
        if curr_row == numRows - 1:
            step = -1
        elif curr_row == 0:
            step = 1
        curr_row += step
    return "\n".join(row_string)


print("Welcome to Zigzag coverter!")
string = input("Enter a String: ")
rows_count = int(input("Enter the number of rows: "))

print(convert(string, rows_count))


