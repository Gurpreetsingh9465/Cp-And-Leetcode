#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

const int MOD = 1000000007;


class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> freq;
    int outliers = 0;
    int count = 0;
    MedianFinder() {
        freq = vector<int>(101,0);
    }
    
    void addNum(int num) {
        if(num>100)
            outliers++;
        else {
            if(freq[num] == 0)
                count++;
            freq[num]++;
        }
    }
    
    double findMedian() {
        if(count == 0)
            return 0;
        int indexes[count];
        vector<int> searchSpace(count);
        int index=0;
        int total = 0;
        int prev = 0;
        for(int i = 0;i<=100;i++) {
            if(freq[i]!=0) {
                indexes[index] = i;
                searchSpace[index] = freq[i] + prev;
                prev = searchSpace[index];
                index++;
            }
        }
        total = searchSpace[index-1] + outliers;
        if((total&1)) {
            int f = (total/2)+1;
            int ans = upper_bound(searchSpace.begin(),searchSpace.end(),f)-searchSpace.begin();
            if(ans<index && searchSpace[ans] == f) {
                return indexes[ans];
            }
            if(ans == 0)
                return indexes[0];
            return indexes[ans-1];
        }
        int first = total/2;
        int second = first+1;
        int f = total/2;
        int ans1 = upper_bound(searchSpace.begin(),searchSpace.end(),first)-searchSpace.begin();
        int ans2 = upper_bound(searchSpace.begin(),searchSpace.end(),second)-searchSpace.begin();
        if(searchSpace[ans1] == first) {
            ans1 = indexes[ans1];
        } else if(ans1 == 0)
            ans1 = indexes[0];
        else
            ans1 = indexes[ans1-1];
        
        if(searchSpace[ans2] == second) {
            ans2 = indexes[ans2];
        } else if(ans2 == 0)
            ans2 = indexes[0];
        else
            ans2 = indexes[ans2-1];
        ans1+=ans2;
        
        return (double)(ans1/(2.0));
        
    }
};

int main() {
    MedianFinder m;

    while (true) {
        char a;
        int b;
        cin>>a;
        if(a == 'i') {
            cin>>b;
            m.addNum(b);
        } else {
            cout<<m.findMedian()<<"\n";
        }
    }
    
}