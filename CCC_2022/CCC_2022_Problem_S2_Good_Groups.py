x = int(input())
cnt = 0
same = []
name = {}
group = [-1] * 5000005
for i in range(x):
    a, b = input().split(" ")
    if a not in name:
        name[a] = cnt
        cnt += 1
    if b not in name:
        name[b] = cnt
        cnt += 1
    same.append([name[a], name[b]])
y = int(input())
dif = []
for i in range(y):
    a, b = input().split(" ")
    if a not in name:
        name[a] = cnt
        cnt += 1
    if b not in name:
        name[b] = cnt
        cnt += 1
    dif.append([name[a], name[b]])
ans = 0
n = int(input())
for i in range(n):
    a, b, c = input().split(" ")
    if a not in name:
        name[a] = cnt
        cnt += 1
    if b not in name:
        name[b] = cnt
        cnt += 1
    if c not in name:
        name[c] = cnt
        cnt += 1
    group[name[a]] = group[name[b]] = group[name[c]] = i;
for [a, b] in same:
    if group[a] != group[b]:
        ans += 1
for [a, b] in dif:
    if group[a] == group[b]:
        ans += 1
print(ans)
