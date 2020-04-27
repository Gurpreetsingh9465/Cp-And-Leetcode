T = int(input())
while T:
    k = int(input())
    up = 10**k
    maxi = up//2
    totalCount = 0
    for i in range(0,maxi):
        count = 0
        p = [False]*10
        x = i
        if x==0:
            p[0] = True
            count+=1
        else:
            while x != 0:
                dig = x%10
                if p[dig] == False:
                    p[dig] == True
                    count+=1
                    if count > 2:
                        continue
                x=x//10
        x = up-1-i
        if x==0:
            p[0] = True
            count+=1
        else:
            while x != 0:
                dig = x%10
                if p[dig] == False:
                    p[dig] == True
                    count+=1
                    if count > 2:
                        continue
                x=x//10
        if count == 2:
            totalCount+=1
    print(totalCount*2)

    T-=1