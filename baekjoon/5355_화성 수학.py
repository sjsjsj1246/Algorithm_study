n = int(input())
for i in range(n):
    arr = list(input().split())
    ans = float(arr[0])
    for j in arr[1:]:
        if j == '@':
            ans *= 3
        elif j == '%':
            ans += 5
        else:
            ans -= 7
    print(format(ans, '.2f'))