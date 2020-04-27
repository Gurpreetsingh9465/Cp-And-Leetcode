
def mincostTickets(days, costs):
    """
    :type days: List[int]
    :type costs: List[int]
    :rtype: int
    """
    curDay = 0
    arr = 366*[0]
    for j in range(1,366):
        if(days[curDay] == j):
            l = max(0,j-7)
            b = min(arr[j-1]+costs[0],arr[l]+costs[1])
            l = max(0,j-30)
            arr[j] = min(b,arr[l]+costs[2])
            curDay+=1
        else:
            arr[j] = arr[j-1]
        if j == days[-1]:
            break
    return arr[days[-1]]

days = [1,4,6,7,8,20]
costs = [2,7,15]
print(mincostTickets(days,costs))


s = "a45s4a5"
s[-1]
