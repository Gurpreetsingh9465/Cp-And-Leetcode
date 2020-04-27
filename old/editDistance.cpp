#include <bits/stdc++.h>
using namespace std;

int fun(string s1, string s2, int i, int j, int operations) {
	if(s1 == s2)
        return operations;
    if(i>=s1.length() || j >= s2.length()) 
        return INT_MAX;
    if(s1[i] == s1[j]) {
        return fun(s1,s2,i+1,j+1,operations);
    }
    int newOperations = INT_MAX;
    string s2Inter = s2;
    s2Inter[j] = s1[i];
    newOperations = min(newOperations, fun(s1,s2Inter,i+1,j+1,operations+1)); // edit
    s2Inter.erase(j);
    newOperations = min(newOperations, fun(s1,s2Inter,i+1,j,operations+1)); // delete
    s2Inter = s2;
    s2Inter.insert(j,string(s1[i],1));
    newOperations = min(newOperations, fun(s1,s2Inter,i+1,j+2,operations+1)); // insert
    return newOperations;
}

int main() {
    string s1 = "abcdef";
    string s2 = "azced";
	cout<<fun(s1,s2,0,0,0)<<endl;
	return 0;
}