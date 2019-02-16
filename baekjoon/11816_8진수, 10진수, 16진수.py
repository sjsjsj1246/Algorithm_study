s = input()
if s[:2] == "0x" :
    print(int(s[2:],16))
elif s[:1] == "0" :
    print(int(s[1:],8))
else :
    print(s)