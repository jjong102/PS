t = int(input())
to_guest = list()

for i in range(t):
    h, w, n = map(int, input().split())
    if n%h == 0:
        h_for_guest = str(h)
        w_for_guest = str(format(int(n/h), '02'))
    else:
        h_for_guest = str(n%h)
        w_for_guest = str(format(int(n/h+1), '02'))
    to_guest.append(int(h_for_guest + w_for_guest))

for i in range(t):
    print(to_guest[i])
