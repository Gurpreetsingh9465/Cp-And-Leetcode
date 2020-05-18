#include <iostream> 
#include <algorithm>    // for lower_bound, upper_bound and sort 
#include <vector>       // for vector 
  
using namespace std; 
  
int main () 
{ 
      
    vector<int> v = {1,5,5,5,8,8,8,8};    //  
  
    sort (v.begin(), v.end());  // 5 5 5 6 6 6 7 7 
  
    vector<int>::iterator lower,upper; 
    lower = upper_bound (v.begin(), v.end(), 4);  
    // upper = upper_bound (v.begin(), v.end(), 6);  
    if(lower == v.end()) {
        cout<<"i am end\n";
    } 
    if(lower == v.begin()) {
        cout<<"i am begin\n";
    }

    cout<<"index is "<<(lower-v.begin())<<"\n";

    return 0; 
} 