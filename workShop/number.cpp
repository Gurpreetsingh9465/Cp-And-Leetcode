#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int calculate(vector<int> arr){
	int total = 0;
	for(int i = 0; i < arr.size(); i++){
		total += arr[i];
	}
	return total;
}

int main(){
	string m;
	int k;
	cin>>k>>m;
	vector<int> arr(m.length(), 0);
	for(int i = 0; i < m.length(); i++){
		arr[i] = (m[i] - '0');
	}
	
	int sum = calculate(arr);
	if(sum >= k){
		cout<<"0\n";
		return 0;
	}
	sort(arr.begin(), arr.end());
	int total =0;
	int idx = 0;
	while(sum < k){
		sum = sum - arr[idx];
		arr[idx++] = 9;
		sum = sum + 9;
		total++;
	}
	cout<<total<<endl;
}