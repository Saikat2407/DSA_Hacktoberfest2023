# import module
import matplotlib.pyplot as plt

# line 1 positions
x1 = [1,2,3]
y1 = [2,4,1]
# plot line 1
plt.plot(x1, y1, color = 'grey', linestyle = 'solid', linewidth = 2, 
			marker = 'o', markerfacecolor = 'blue', markersize = 8, label = "Line 1")

# line 2 positions
x2 = [1,2,3]
y2 = [4,1,3]

# plot line 2
plt.plot(x2, y2, color = 'black', linestyle = 'solid', linewidth = 2, 
			marker = 'o', markerfacecolor = 'blue', markersize = 8, label = "Line 2")

# x-axis name
plt.xlabel('x - axis')
# y-axis name
plt.ylabels('y - axis')

# title
plt.title('Statistical Graph Output!')
# display legend
ply.legend()

# display plot
plt.show()