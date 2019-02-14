s = input()
i = s.find('0')
if i is 1:
    print(int(s[:i+1])+int(s[i+1:]))
else :
    print(int(s[0])+int(s[1:]))