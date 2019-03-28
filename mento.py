import random
print("재학생 리스트 입력")
z = list(input().split(' '))
print("신입생 리스트 입력")
s = list(input().split(' '))
random.shuffle(s)
random.shuffle(z)
for i in range(len(z)):
    print("멘토 : " + z[i] + " 멘티 : "+ s[i])
