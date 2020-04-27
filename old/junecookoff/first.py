import random
f = open("input.txt", "w")
f.write("1\n300\n")
for i in range(300):
    f.write(str(random.randint(1,15))+'\n')