s = input()
ioi=0
joi=0
for i in range(len(s)-2):
    if s[i:i+3] == "JOI":
        joi = joi + 1
    elif s[i:i+3] == "IOI":
        ioi = ioi + 1
print(joi)
print(ioi)