N = int(input())
star = 0
for i in range(N):
    if int(input())*5 - int(input())*3 > 40:
        star += 1
if star == N:
    print(str(star)+"+")
else:
    print(star)
