#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

bool canH(int i, int j, int R, int C, char **matrix) {
    if(matrix[i][j] != '.')
        return false;
    for(int j_next=j;j_next<=C;j_next++) {
        if(matrix[i][j_next] == '#') {
            return false;
        } else if(matrix[i][j_next] == 'b') {
            break;
        }
    }
    for(int j_next=j;j_next>0;j_next--) {
        if(matrix[i][j_next] == '#') {
            return false;
        } else if(matrix[i][j_next] == 'b') {
            break;
        }
    }
    return true;
}

bool canV(int i, int j, int R, int C, char **matrix) {
    if(matrix[i][j] != '.')
        return false;
    for(int i_next=i;i_next<=R;i_next++) {
        if(matrix[i_next][j] == '#') {
            return false;
        } else if(matrix[i_next][j] == 'b') {
            break;
        }
    }
    for(int i_next=i;i_next>0;i_next--) {
        if(matrix[i_next][j] == '#') {
            return false;
        } else if(matrix[i_next][j] == 'b') {
            break;
        }
    }
    return true;
}

pair<int,char> optimal_move(int i, int j, int R, int C, char **matrix) { 
    if(matrix[i][j] != '.')
        return {0,'\n'};
    bool canplace = true;
    int h_move=0, v_move = 0;
    for(int j_next=j;j_next<=C;j_next++) {
        if(matrix[i][j_next] == '#') {
            canplace = false;
            break;
        } else if(matrix[i][j_next] == 'b') {
            break;
        }
        h_move++;
    }
    if(canplace == true) {
        for(int j_next=j;j_next>0;j_next--) {
            if(matrix[i][j_next] == '#') {
                canplace = false;
                break;
            } else if(matrix[i][j_next] == 'b') {
                break;
            }
        }
        h_move++;
    }
    int H = 0;
    if(canplace)
        H = 1;
    canplace = true;
    for(int i_next=i;i_next<=R;i_next++) {
        if(matrix[i_next][j] == '#') {
            canplace = false;
            break;
        } else if(matrix[i_next][j] == 'b') {
            break;
        }
        v_move++;
    }
    if(canplace == true) {
        for(int i_next=i;i_next>0;i_next--) {
            if(matrix[i_next][j] == '#') {
                canplace = false;
                break;
            } else if(matrix[i_next][j] == 'b') {
                break;
            }
        }
        v_move++;
    }
    int V = 0;
    if(canplace)
        V = 2;
    if(v_move == 0 && h_move)
        return {0,'\n'};
    if(H == 0)
        return {v_move, 'V'};
    if(V == 0)
        return {h_move, 'H'};
    if(v_move>h_move)
        return {v_move, 'V'};
    return {h_move, 'H'};
}

void applyChange(char **matrix, int R, int C, int i, int j, char HorV) {
    if(HorV == 'H') {
        for(int j_next=j;j_next<=C;j_next++) {
            if(matrix[i][j_next] == 'b') {
                break;
            } else {
                matrix[i][j_next] = 'b';
            }
        }
        for(int j_next=j;j_next>0;j_next--) {
            if(matrix[i][j_next] == 'b') {
            break;
            } else {
                matrix[i][j_next] = 'b';
            }
        }
    } else {
        for(int i_next=i;i_next<=R;i_next++) {
            if(matrix[i_next][j] == 'b') {
                break;
            } else {
                matrix[i_next][j] = 'b';
            }
        }
        for(int i_next=i;i_next>0;i_next--) {
            if(matrix[i_next][j] == 'b') {
                break;
            } else {
                matrix[i_next][j] = 'b';
            }
        }
    }
}

bool rec(char **matrix, int C, int R, bool a) {
    int optimal = INT_MIN;
    char move = '\n';
    int i_next,j_next;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            pair<int,char> inter = optimal_move(i,j,R,C,matrix);
            if(inter.first != 0 && inter.first>optimal) {
                optimal = inter.first;
                move = inter.second;
                i_next = i;
                j_next = j;
            }
        }
    }
    if(optimal == INT_MIN) {
        return !a;
    }
    applyChange(matrix,R,C,i_next,j_next,move);
    return rec(matrix,C,R,!a);
}

void solve() {
    int R,C;
    cin>>R>>C;
    char **matrix = new char*[R+1];
    for(int i=1;i<=R;i++) {
        matrix[i]= new char[C+1];
        for(int j=1;j<=C;j++) {
            cin>>matrix[i][j];
        }
    }
    int canPlace = 0;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            canPlace = canPlace + canH(i,j,R,C,matrix) + canV(i,j,R,C,matrix);
        }
    }
    if(canPlace == 0) {
        cout<<"0\n";
    } else if(rec(matrix,C,R,true)) {
        cout<<canPlace<<"\n";
    } else {
        cout<<"0\n";
    }
    


}


int main() {
    fastIO;
    ll T;
    cin>>T;
    for(ll t=1;t<=T;t++) {
        cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
