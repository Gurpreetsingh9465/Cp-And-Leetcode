#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<char,vector<pair<float,char>>> my_graph({
      {'A',{{0.3,'B'},{0.4,'C'},{0.5,'D'}}},
      {'B',{{0.6,'E'},{0.7,'F'}}},
      {'C',{{0.6,'F'},{0.4,'G'}}},
      {'D',{{0.6,'G'},{0.9,'H'}}},
      {'E',{{0.7,'F'}}},
      {'F',{{0.5,'G'}}},
      {'G',{{0.3,'H'}}},
      {'H',{}}
    });

    char source = 'A';
    char destination = 'H';

    vector<vector<char>> output;
    queue<vector<char>> queue1;
    vector<char> initial = {source};
    queue1.push(initial);
    while(!queue1.empty())
    {
        vector<char> front_node = queue1.front();
        queue1.pop();
        int c = front_node.size()-1;

        if(destination == front_node[c]) {
            output.push_back(front_node);
        }

        vector<pair<float,char>> neighbours = my_graph[front_node[c]];
        for(int i=0;i<neighbours.size();i++)
        {
            vector<char> newPath(front_node);
            newPath.push_back(neighbours[i].second);
            
            queue1.push(newPath);

        }
    }
        for(int i=0;i<output.size();i++)
        {
            for(auto &j : output[i])
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
 
}