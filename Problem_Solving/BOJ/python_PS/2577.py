a=int(input())
b=int(input())
c=int(input())

A = list(str(a*b*c))
for i in range(10):
    print(A.count(str(i)))