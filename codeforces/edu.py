import math
T = int(input())

while T:
    n = int(input())
    if n%2 == 0:
        rad = 0.0174533
        internal_angle = ((n-1)*180*1.0)/(n*1.0)
        prevAngle = 0
        ans = 1.0
        while True:
            cur_angle = (180-internal_angle)+prevAngle
            prevAngle = cur_angle
            co = math.cos(cur_angle*rad)
            if co<=0:
                break
            ans = ans + 2.0 * co
        print(ans)
    else:
        angle = (math.pi/n)/4
        ans = (0.5)/math.sin(angle)
        print(ans)

    T-=1





