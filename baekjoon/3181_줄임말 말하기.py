l = list(input().split())
c = ['i', 'pa', 'te', 'ni', 'niti', 'a', 'ali', 'nego', 'no', 'ili']
for s in l:
    if(s not in c or s is l[0]):
        print(s[0].upper(),end='')