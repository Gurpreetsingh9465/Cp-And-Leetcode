#include<bits/stdc++.h>
#include "fstream"
using namespace std;

void Nth(long long N, ofstream &myfile) {
    long long t = 0;
    long long outlier = 0;
    for(unsigned long long i = 19 ;i<INT_MAX;i+=9) {
        long long sum = 0;
        for (long long x = i; x > 0; x = x / 10)
            sum = sum + x % 10;
        if (sum == 10)
            t++;
        else {
            outlier+=1;
            myfile<<i<<" o = "<<outlier<<endl;
        }
            
        if (t == N) {
            long long val = (19+(N-1)*9);
            //myfile<<"N = "<<N<<" expected = "<<val<<" outlier = "<<outlier<<endl;
            break;
        }
    }
}


int main() {
    long long N;
    ofstream myfile;
    myfile.open ("outlier.txt");
    cin>>N;
    // for(long long i = 1 ;i <= N;i++) {
    //     Nth(i,myfile);
    // }
    Nth(N,myfile);
    myfile.close();
    cout<<endl;
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int T;
//     cin>>T;
//     while(T--) {
//         long long N;
//         cin>>N;
        // long long nthElement = 19 + (N - 1) * 9;
        // long long outliersCount = (long long)log10(nthElement) - 1;
        // nthElement += 9 * outliersCount;
        // cout<<nthElement<<endl;
//     }
//     return 0;
// }
