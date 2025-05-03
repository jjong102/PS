


T = int(input())
A = list() # A = []*T하고 for문 안에서 바로 A[i]=a+b 해도 상관 없음.

for i in range(T):
    a, b = map(int, input().split())
    A.append(a+b)

for i in range(T):
    print(A[i])



