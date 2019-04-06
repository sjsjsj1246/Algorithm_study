from random import *
n = 50000
ans = ""
e = s = 0
while e < n-1 or s<n-1:
    i = randint(0,2)
    if i is 0 and e < n-1:
        ans+="E"
        e+=1
    elif i is 1 and s < n-1:
        ans+="S"
        s+=1

f = open("test.txt", 'w')
f.write(str(n)+"\n"+ans)
f.close()