import numpy

pi = 3.14159265358979323846
t = int(input())
for cases in range(t):
    ans=0
    r, s, e = map(int, input().split())
    n = int(input())
    for i in range(n):
        a, b, c = map(int, input().split())
        ans += a - s - r
        ans += b - a + 2 * (c - r)
        if (c >= r):
            ans += pi * r
        else:
            ans += 2 * r * numpy.arccos((r - c) / r)
        s = b + r
    ans += e-s
    print("Case #", t+1)
    print(ans)