#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

unordered_map<int,int> primeFactors(int n)  
{
    unordered_map<int,int> ans;
    while (n % 2 == 0)  
    {  
        ans[2]+=1; 
        n = n/2;  
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {
        while (n % i == 0)  
        {  
            ans[i] += 1; 
            n = n/i;
        }
    }
    if (n > 2)  
        ans[n] += 1;  
    return ans;
}

bool calculate(int x, int k) {
    unordered_map<int,int> m = primeFactors(x);
    int a=0;
    for(auto &i: m) {
        a+=i.second;
    }
    if(a>=k)
        return true;
    return false;
}

int main() {
    fastIO;
    int T;
    cin>>T;
    while (T--) {
        int x,k;
        cin>>x>>k;
        cout<<calculate(x,k)<<"\n";
    }
    
    return 0;
}


