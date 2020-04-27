#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;


int main() {
    vector<int> v = {1,4,7,8,11,15};
    vector<int> v2 = {1,4,5,7,8,11,15};
    int fi = 5;

    cout<<lower_bound(v.begin(), v.end(),fi) - v.begin()<<"\n";
    cout<<lower_bound(v2.begin(), v2.end(),20) - v2.begin();

    return 0;
}