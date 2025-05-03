A = list()
for _ in range(3):
    A.append(input())

A_int = list(map(int, A))
print(A_int[0]+A_int[1]-A_int[2])

A_str = list(map(str, A))
print(int(A_str[0]+A_str[1])-A_int[2])