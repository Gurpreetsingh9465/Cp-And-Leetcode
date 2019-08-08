#include<bits/stdc++.h>
using namespace std;

int main() {
	map<int, int> p;
	if(p.find(5) != p.end()) {
		cout<<"Found"<<endl;
	}
	p.insert(pair<int,int>(5,0));
	if(p.find(5) != p.end()) {
		cout<<"Found"<<endl;
	}
	p.find(5)->second+=1;
	cout<<p.find(5)->second<<endl;
	cout<<p.size()<<endl;
}