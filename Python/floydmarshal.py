class Solution:
	def shortest_dist(self, matrix):
		N = len(matrix)

		# changing value of -1 
		# to infinite
		for i in range(N):
			for j in range(N):
				if matrix[i][j] == -1:
					matrix[i][j] = float('inf')

				# The distance of node to 
				# itself will be 0.
				if i == j:
					matrix[i][j] = 0

		# Assign the better distance 
		# (if exist) in the matrix
		# one by one making each node 
		# as our intermediate node
		for via in range(N):
			for i in range(N):
				for j in range(N):
					matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j])

		# Replacing infinity to -1, 
		# after the work is done
		for i in range(N):
			for j in range(N):
				if matrix[i][j] == float('inf'):
					matrix[i][j] = -1

# Driver code
if __name__ == "__main__":
	grid = [[0, 1, 2], [0, 3, 5], [0, 4, 3], [1, 0, 3], [1, 5, 6], [1, 2, 2], [1, 3, 2], [2, 5, 1], [2, 3, 1], [3, 4, 1], [4, 3, 2]]
	V = 6
	matrix = [[-1 for _ in range(V)] for _ in range(V)]

	# Creating matrix representation
	for it in grid:
		u, v, wt = it[0], it[1], it[2]
		matrix[u][v] = wt

	obj = Solution()

	# Function call
	obj.shortest_dist(matrix)

	for row in matrix:
		for it in row:
			if it == -1:
				it = -1
			print(it, end="\t")
		print()



