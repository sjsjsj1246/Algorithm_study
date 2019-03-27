h1, m1, s1 = map(int, input().split(":"))
h2, m2, s2 = map(int, input().split(":"))
h2-=h1
m2-=m1
s2-=s1
if s2<0:
    m2-=1
    s2 += 60
if m2<0:
    h2-=1
    m2 += 60
if h2<0:
    h2 += 24

print(str(h2).zfill(2)+":"+str(m2).zfill(2)+":"+str(s2).zfill(2))
