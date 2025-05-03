a = int(input())

for i in range(a):
    i += 1
    while i != 0:
        print("*", end="")
        i -= 1
    print("")