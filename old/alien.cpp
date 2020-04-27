
#include<bits/stdc++.h>
using namespace std;
string printOrder(string [], int , int );
string order;
bool f(string a,string b)
{
	int p1=0;int p2=0;
	for(int i=0;i<min(a.size(),b.size()) and p1 ==p2;i++ )
	{
		p1 = order.find(a[i]);
		p2 = order.find(b[i]);
	//	cout<<p1<<" "<<p2<<endl;
	}
	
	if(p1 == p2 and a.size()!=b.size())
	return a.size()<b.size();
	
	return p1<p2;
}
	
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    
        string ss = printOrder(s,n,k);
        // order="";
        // for(int i=0;i<ss.size();i++)
        // order+=ss[i];
        
        // string temp[n];
        // std::copy(s, s + n, temp);
        // sort(temp,temp+n,f);
        
        // bool f= true;
        // for(int i=0;i<n;i++)
        // if(s[i]!=temp[i])f=false;
        
        // cout<<f;
        // cout<<endl;
        
    }
	return 0;
}

class Graph {
    public:
    int v;
    list<int> *adj;
    Graph(int v) {
        this->v = v;
        adj = new list<int>[v];
    }
    void addNode(int par, int child) {
        adj[par].push_back(child);
    }
    
    void topologicalSort(int i, bool visited[], stack<int> &s) {
        int v = i;
        visited[v] = true;
        for(auto &j: adj[v]) {
            if(visited[j] == false) {
                topologicalSort(j,visited,s);
            }
        }
        s.push(v);
    }
    
    string sort(queue<int> &q) {
        stack<int> s;
        bool visited[this->v];
        for(int i = 0;i<v;i++) {
            visited[i] = false;
        }
        while(!q.empty()) {
            if(visited[q.front()] == false) {
                topologicalSort(q.front(),visited,s);
            }
            q.pop();
        }
        string res = "";
        while(!s.empty()) {
            res = res + (char)(s.top() + 'a');
            s.pop();
        }
        return res;
    }
};

string printOrder(string dict[], int N, int k)
{
   //Your code here
   string res;
   Graph g(k);
   queue<int> q;
   for(int i = 0;i<N-1;i++) {
       string s1 = dict[i];
       string s2 = dict[i+1];
       for(int j = 0;j<min(s1.length(), s2.length());j++) {
           if(s1[j] != s2[j]) {
               q.push(s1[j]-'a');
               
                g.addNode(s1[j]-'a',s2[j]-'a');
           }
       }
   }
   res = g.sort(q);
   return res;
}