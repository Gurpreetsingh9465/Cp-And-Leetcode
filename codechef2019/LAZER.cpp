#include<bits/stdc++.h>
using namespace std;

bool comparatorY2(vector<int> &a, vector<int> &b) {
    return a.at(3) < b.at(3);
}
bool comparatorY1(vector<int> &a, vector<int> &b) {
    return a.at(2) < b.at(2);
}

class KdTree
{
    public:
      class Node {
          public:
            int x1,x2, y1,y2;
            Node *left, *right;
            Node(int x1, int x2, int y1, int y2) {
                this->x1 = x1;
                this->x2 = x2;
                this->y1 = y1;
                this->y2 = y2;
                this->left = NULL;
                this->right = NULL;
            }
      };
      Node *root;
      KdTree() {
          root = NULL;
      }

      void recurSiveDelete(Node *cur) {
          if(cur->left == NULL && cur->right == NULL) {
              delete cur;
              cur = NULL;
          } else {
              recurSiveDelete(cur->left);
              recurSiveDelete(cur->right);
          }
          delete cur;
      }

      ~KdTree() {
          recurSiveDelete(root);
      }

      void recursiveInsert(int &x1, int &x2, int &y1, int &y2, Node *cur) {
          if(cur->y2<y2) {
            if(cur->right == NULL) {
                cur->right = new Node(x1,x2,y1,y2);
            } else {
                recursiveInsert(x1,x2,y1,y2,cur->right);
            }
        } else {
            if(cur->left == NULL) {
                cur->left = new Node(x1,x2,y1,y2);
            } else {
                recursiveInsert(x1,x2,y1,y2,cur->left);
            }
        }
      }

      void insert(int x1, int x2, int y1, int y2) {
          if(root == NULL) {
              root = new Node(x1, x2, y1, y2);
          } else {
              recursiveInsert(x1,x2,y1,y2,root);
          }
      }

      void constructRecur(vector<vector<int>> &lines, int start, int end) {
          if(start>end) {
              return;
          }
          int median = (start+end)/2;
          this->insert(lines[median][0],lines[median][1],lines[median][2],lines[median][3]);
          constructRecur(lines, start, median-1);
          constructRecur(lines, median+1, end);
      }
      void constructBalanced(vector<vector<int>> lines) {
          sort(lines.begin(), lines.end(), comparatorY1);
          constructRecur(lines, 0, lines.size()-1);
      }

      void recursizeQuery(int &x1, int &x2, int &y, int *count, Node *cur) {
          if(cur == NULL)
            return;
          if(cur->y1 == cur->y2) {
              recursizeQuery(x1,x2,y,count,cur->left);
              recursizeQuery(x1,x2,y,count,cur->right);
              return;
          }
          if(y<=cur->y2 && y>=cur->y1 && x1<=cur->x1 && x2>=cur->x2) {
              *count = *count+1;
          }
          if(y>cur->y2) {
                recursizeQuery(x1,x2,y,count,cur->right);
            } else {
                recursizeQuery(x1,x2,y,count,cur->left);
                recursizeQuery(x1,x2,y,count,cur->right);
            }
      }

      int query(int x1, int x2, int y) {
          int *count = new int;
          *count = 0;
          recursizeQuery(x1,x2,y,count, root);
          return *count;
      }
};


int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N,Q;
        scanf("%d%d", &N, &Q);
        vector<int> v(N+1);
        v[0] = 0;
        for(int i = 1;i<=N;i++) {
            scanf("%d",&v[i]);
        }
        KdTree *tree = new KdTree();
        vector<vector<int>> lines(N-1);
        int index = 0;
        for(int i = 1;i<N;i++) {
            int y2 = v[i]>v[i+1]?v[i]:v[i+1];
            int y1 = v[i]>v[i+1]?v[i+1]:v[i];
            lines[index++] = {i,i+1,y1,y2};
        }
        tree->constructBalanced(lines);
        for(int i =0 ;i<Q;i++) {
            int x_0,x_1,y;
            scanf("%d%d%d", &x_0, &x_1, &y);
            int ans = tree->query(x_0,x_1,y);
            cout<<ans<<endl;
        }
        // delete tree;
    }
    return 0;
}