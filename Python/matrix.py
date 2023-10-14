# matrix addition in python

rows = int(input('ENter number of rows: '))
cols  = int(input('ENter number of column: '))

print() # for new line
print('Enter values for matrix A')

matrix_A = [[int(input(f"column {j+1} -> ENter {i+1} element:")) for j in range(cols)] for i in range(rows) ]  

print() # for new line
print('Enter values for matrix B ')

matrix_B = [[int(input(f"column {j+1} -> ENter {i+1} element:")) for j in range(cols)] for i in range(rows) ]  

print() #for new line

print('Matrix-A :')
for i in matrix_A:
    print(i)

print() #for new line

print('Matrix-B :')
for i in matrix_B:
    print(i)

# resultant matrix (matrix that store answer and intially it is Zero)
result = [[0 for j in range(cols)] for i in range(rows)]

# addition
for i in range(rows):
    for j in range(cols):
        result[i][j] = matrix_A[i][j] + matrix_B[i][j]

print() #for new line
print('Addition of Matrix-A and Matrix-B is :')

for i in result:
    print(i)
