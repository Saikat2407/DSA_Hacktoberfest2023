# #make a function that takes 2 matrices of 3x3 dimensions and returns the product of the two matrices

# def matrixMultiplication(matrix1, matrix2):
#     result = [[0,0,0],[0,0,0],[0,0,0]]
#     for i in range(len(matrix1)):
#         for j in range(len(matrix2[0])):
#             for k in range(len(matrix2)):
#                 result[i][j] += matrix1[i][k] * matrix2[k][j]
#     return result
# #take user input for the multiplication

# matrix1=[]
# matrix2=[]
# for i in range(3):
#     row=[]
#     for j in range(3):
#         row.append(int(input("Enter the value for matrix1 (row-wise): ")))
#     matrix1.append(row)
# print(matrix1)

# for i in range(3):
#     row=[]
#     for j in range(3):
#         row.append(int(input("Enter the value for matrix2 (row-wise): ")))
#     matrix2.append(row)
# print(matrix2)

# print("The product of the two matrices is :",matrixMultiplication(matrix1, matrix2))
def matrixMultiplication(matrix1, matrix2):
    result = [[0,0,0],[0,0,0],[0,0,0]]
    for i in range(len(matrix1)):
        for j in range(len(matrix2[0])):
            for k in range(len(matrix2)):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    return result

matrix1=[]
matrix2=[]
for i in range(3):
    row=[]
    for j in range(3):
        row.append(int(input("Enter the value for matrix1 (column-wise): ")))
    matrix1.append(row)
print(matrix1)

for i in range(3):
    row=[]
    for j in range(3):
        row.append(int(input("Enter the value for matrix2 (column-wise): ")))
    matrix2.append(row)
print(matrix2)

print("The product of the two matrices is:")
result = matrixMultiplication(matrix1, matrix2)
for row in result:
    print(row)

