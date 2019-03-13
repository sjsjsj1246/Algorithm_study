a,b = map(int,input().split(":"))
c,d = map(int,input().split(":"))
x = a*60+b
y = c*60+d
x += (y-x)/2
print(str(int(x/60)).zfill(2) + ":" + str(int(x%60)).zfill(2))