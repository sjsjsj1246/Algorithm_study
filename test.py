import random
s = list(input().split(" "))
for i in range(int(len(s)/4)):
   s2 = random.sample(s, 4)
   for x in s2:
       s.remove(x)
   print(s2)
print(s)