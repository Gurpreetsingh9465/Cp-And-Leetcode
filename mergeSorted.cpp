#include<bits/stdc++.h>
using namespace std;
class Cmp
{
public:
    bool operator() (int a, int b)
    {
        return a>b;
    }
};

int main() {
    priority_queue<int, vector<int>, Cmp> q;
    q.push(5);
    q.push(4);
    q.push(7);
    while (!q.empty()) {
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}