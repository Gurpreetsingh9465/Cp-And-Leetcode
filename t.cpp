#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool divisorGame(int N) {
        int count = 0;
        int num = N;
            while(num!=1)
            {
                int x = 1;
                while(num%x!=0)
                {
                    x++;
                }
                num = num-x;
                count++;
            }
                if(count%2 == 0)
                {
                return 0;
            }
        return 1;
    }
};