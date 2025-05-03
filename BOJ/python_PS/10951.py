A = list()

while 1:
    try :
        a, b = map(int, input().split())
        A.append(a+b)
    except : 
        break

for i in range(len(A)):
    print(A[i])


