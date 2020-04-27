#include<bits/stdc++.h>
using namespace std;
int myAtoi(string str) {
    long long sum = 0;
    int isNegative = 1;
    bool alreadyUsed = false;
    for(int i=0;i<str.length();i++) {
        int val = (int)str[i];
        if(val == 45) {
            isNegative = -1;
        }else if(val>=48 && val<=57) {
            alreadyUsed = true;
            val-=48;
            sum = sum*10 + val;
            if(sum>INT_MAX) {
                if(isNegative == -1) {
                    return INT_MIN;
                } else {
                        return INT_MAX;
                }
            }
        } else if(val == 32 || val == 43) {
            if(alreadyUsed)
                return 0;
            continue;
        } else {
            return isNegative*sum;
        }
        
    }
    return isNegative*sum;
}

int main() {
    cout<<myAtoi("-987");
    return 0;
}