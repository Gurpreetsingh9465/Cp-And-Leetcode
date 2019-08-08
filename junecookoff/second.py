
def maxIndex(List:list, temp:list, i):

    for j in range(i+1, len(temp)):
        
    maximum=0
    for i,value in enumerate(List):
        if value>maximum:
            maximum=value
            index=i
    return index

T = int(input())
while T:
    N = list(map(int,input().split(" ")))
    M = N[1]
    N = N[0]
    C = list(map(int,input().split(" ")))
    output = []
    count = 0
    temp = []
    for i in range(N):
        val = list(map(int,input().split(" ")))
        temp.append(val)
    for i in temp:
        if(C[i[0]-1] == 0):
            key = maxIndex(C, temp, i)
            C[key] -= 1
            output.append(key+1)
            count += i[2]
        else:
            output.append(i[0])
            C[i[0]-1] -= 1
            count += i[1]
    print(count)
    for i in output:
        print(i,end=" ")
    print
    T-=1
