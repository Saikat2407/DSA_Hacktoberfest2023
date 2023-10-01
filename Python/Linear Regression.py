import numpy as np
import matplotlib.pyplot as plt
from scipy import stats

x = [5,7,8,9,4,11,12,9,6]
y = [99,86,87,87,94,78,77,85,86]

slope, intercept, r, p, std_err = stats.linregress(x, y)

def myfunc(x):
  return slope * x + intercept

mymodel = list(map(myfunc, x))

plt.scatter(x, y)
plt.plot(x, mymodel)
plt.show()
