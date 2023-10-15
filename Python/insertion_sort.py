n = int(input("Number of elements - "))
l = []

for i in range(n):
    a = int(input("Enter the element - "))
    l.append(a)

for i in range(n):
    elem = l[i]
    for j in range(i+1, n):
        if l[j]<=elem:
            l[i]=l[j]
            l[j]=elem
print(l)
        
