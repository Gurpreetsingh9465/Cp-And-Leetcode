#include<bits/stdc++.h>
#include "string.h"
class Solution {
private:
    int count = 0;
public:
    void expand(string a, int start, int end){
        while(start >= 0 && end < a.length() && a[start] == a[end]){
            count += 1;
            start --;
            end ++;
        }
    }
    int countSubstrings(string s) {
        for(int i=0; i<s.length();i++){
            expand(s, i, i);
            expand(s, i, i + 1);
        }
        return count;
    }
};

int main() {
    std::string s = "abcb";
    std::cout<<Solution().countSubstrings(s)<<std::endl;
    return 0;
}