#include<bits/stdc++.h>
using namespace std;
void dfs(int **cost,int n, int v, int *visited,int *result, int &i)
{
	result[i++] = v+1;
	visited[v]=1;
    for(int j=0; j<n; j++) {
        if(cost[v][j]!=0 && visited[j]!=1)
        {
            dfs(cost,n,j,visited,result,i);
        }
    }
}
int main()
{
	int n, m,v;
    cout <<"Enter no of vertices:";
    cin >> n;
    cout <<"Enter no of edges:";
    cin >> m;
    cout <<"\nEDGES \n";
    int **cost = new int*[n];
    for(int i = 0;i<n;i++) {
    	cost[i] = new int[n];
    	for(int j=0;j<n;j++) {
    		cost[i][j] = 0;
		}
	}
    for(int k=1; k<=m; k++)
    {
    	int i,j;
        cin >>i>>j;
        cost[i-1][j-1]=1;
        cost[j-1][i-1]=1;
    }
    cout <<"Enter initial vertex to traverse from:";
    cin >>v;
    cout <<"DFS ORDER OF VISITED VERTICES:";
    cout << v <<" ";
    int *visited = new int[n];
    memset(visited,0,sizeof(visited)+1);
    int *result = new int[n];
    int rei = 0;
    dfs(cost,n,v,visited, result, rei);
    
    for(int i=0;i<rei;i++) {
    	cout<<result[i]<<" ";
	}
	cout<<endl;
    return 0;
}