s = input()

l = s.split(" ")

for i in range(len(l)//2):
    l[i], l[len(l)-i-1] = l[len(l)-i-1], l[i]

out = ""

for i in l:
    out = out + i +" +"
print(out)