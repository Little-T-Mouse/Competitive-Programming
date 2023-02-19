s = input()
tmp = ""
for i in range(len(s)):
    if len(tmp) != 0 and not s[i].isnumeric() and s[i-1].isnumeric():
        print(tmp)
        tmp = "";
    if s[i].isupper():
        tmp += s[i]
    elif s[i] == '-':
        tmp += " loosen "
    elif s[i] == '+':
        tmp += " tighten "
    elif s[i].isnumeric():
        tmp += s[i]
print(tmp)
