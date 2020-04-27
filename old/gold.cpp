#include <bits/stdc++.h>

using namespace std;

// string ltrim(const string &);
// string rtrim(const string &);


// class cmp {
//     public:
//     bool operator() (pair<string,int> left, pair<string,int> right) {
//         if(right.second == left.second) {
//             return right.first<left.first;
//         }
//         return right.second<left.second;
//     }
// };
// // Complete the closestStraightCity function below.
// vector<string> closestStraightCity(vector<string> c, vector<int> x, vector<int> y, vector<string> q) {
//     map<string, pair<string,int>> m;
//     for(int i = 0;i<c.size();i++) {

//         m[c[i]] = {c[i],INT_MAX};
//     }
//     for(int i = 0; i<c.size();i++) {
//         for(int j = 0;j<c.size();j++) {
//             if(i == j) {
//                 continue;
//             } else {
//                 int distance = abs(x[i]-x[j])*abs(x[i]-x[j]) + abs(y[i]-y[j])*abs(y[i]-y[j]);
//                 if(m[c[i]].second > distance) {
//                     cout<<i<<" "<<j<<endl;
//                     m[c[i]] = {c[j],distance};
//                 }
//             }
//         }
//     }
//     vector<string> res(q.size());
//     for(int i = 0;i<q.size();i++) {
//         string r = m[q[i]].first;
//         cout<<m[q[i]].second<<" "<<endl;
//         res.push_back(r);
//     }
//     return res;
// }

int main() {
    // vector<string> s = {"f","b","x"};
    // vector<int> x = {23,23,23};
    // vector<int> y = {1,10,20};
    // vector<string> res = closestStraightCity(s,x,y,s);
    // for(auto i : res) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    char a[] = "amana";
    printf("%s\n",&a);
    return 0;
}