#include<bits/stdc++.h>
using namespace std;

void swap(pair<int,int> *xp, pair<int,int> *yp) 
{ 
    pair<int,int> temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubbleSort(pair<int,int> arr[], int n, int *pos) 
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
           swap(&pos[j],&pos[j+1]);
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
            pos[i] = i+1;
        }
        for(int i = 0 ;i<N;i++) {
            cin>>p[i].second;
        }
        bubbleSort(p,N,pos);
        int *ans = new int[N];
        ans[0] = 1;
        int i = 0;
        for(int j=1;j<N;j++){
            if(p[j].first>=p[i].second) {
                ans[j]=1;
                i=j;
            } else {
                ans[j] = 0;
            }
        }
        for(int i = 0;i<N;i++) {
            if(ans[i] == 1) {
                cout<<pos[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}