def fun():
    N, K = map(int,input().split(' '))
    if K == 1:
        return "NO"
    first = N/K
    isFloat = first/K
    if isFloat == int(isFloat):
        return "NO"
    return "YES"
T = int(input())
while T:
    print(fun())
    T-=1