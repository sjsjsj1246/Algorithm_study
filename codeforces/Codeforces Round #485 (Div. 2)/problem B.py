import math

x,y = map(int,input().split())
f = y*math.log(x)
s = x*math.log(y)
if f<s:
	print("<")
elif f>s:
	print(">")
else:
	print("=")