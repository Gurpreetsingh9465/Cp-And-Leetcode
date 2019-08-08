#include<bits/stdc++.h>
using namespace std;

void swap(pair<int,int> *xp, pair<int,int> *yp) 
{ 
    pair<int,int> temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubbleSort(pair<int,int> arr[], int n) 
{ 
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++) 
   {
     swapped = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j].second > arr[j+1].second) 
        {
           swap(&arr[j], &arr[j+1]); 
           swapped = true; 
        } 
     } 
     if (swapped == false) 
        break; 
   } 
} 

int main() {
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        int pos[N];
        pair<int,int> p[N];
        for(int i = 0;i<N;i++) {
            cin>>p[i].first;
        }
        for(int i = 0 ;i<N;i++) {
            cin>>p[i].second;
        }
        bubbleSort(p,N);
        int ans = 1;
        int i = 0;
        for(int j=1;j<N;j++){
            if(p[j].first>=p[i].second) {
                ans+=1;
                i=j;
            } 
        }
        cout<<ans<<endl;
    }
    return 0;
}