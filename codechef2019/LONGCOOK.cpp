#include<bits/stdc++.h>
using namespace std;

unsigned day_of_week( unsigned year, unsigned month, unsigned day ) {   
    unsigned a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

bool isLeap(int year) {
    return (year%400 == 0) || (year%4 == 0 && year%100 != 0);
}

int calculate(int y1, int y2) {
    if(y1>y2) {
        return 0;
    }
    if(y1 == 0 || y2 == 0) {
        return 0;
    }
    int ans = 0;
    int day6 = day_of_week(y1,2,6);
    int day7 = (day6+1)%7;
    for(int i = y1;i<=y2;i++) {
        if(isLeap(i)) {
            if(day7 == 5) {
                ans+=1;
            }
            day6+=(2);
            day6%=7;
            day7+=(2);
            day7%=7;
        } else {
            if(day7 == 5 || day6 == 5) {
                ans+=1;
            }
            day6+=(1);
            day6%=7;
            day7+=(1);
            day7%=7;
        }
    }
    return ans;
}

int calculate1(int y1, int y2) {
    if(y2-y1 < 400) {
        return calculate(y1, y2);
    } 

    int ans = 0;
    int lower = (y1/400)*400;
    if(lower == 0) {
        lower++;
    }
    int upper = ((y2/400) + 1)*400;
    ans = (101 * ((upper-lower+1)/400)) - calculate(lower, y1-1) - calculate(y2+1, upper);
    return ans;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        int m1, m2, y1, y2;
        cin>>m1>>y1;
        cin>>m2>>y2;
        if(m1 > 2) {
            y1++;
        }
        if(m2 < 2) {
            y2--;
        }
        int ans = calculate1(y1, y2);
        cout<<calculate(y1,y2)<<endl;
        cout<<ans<<endl;
    }
    return 0;
}