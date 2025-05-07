A = list()

while 1:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    A.append(a+b)

for i in range(len(A)):
    print(A[i])
