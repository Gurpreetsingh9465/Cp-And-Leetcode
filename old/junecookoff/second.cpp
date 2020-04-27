#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
        int R,C;
        cin>>R>>C;
        string s[R];
        int arr[R][C];
        for(int i = 0;i<R;i++) {
            cin>>s;
        }
        int count = 0;
        for(int i = 0;i<R;i++) {
            for(int j = 0;j<C;j++) {
                if(s[i][j] == '#') {
                    arr[i][j] = -1;
                } else if (s[i][j] == '-') {
                    arr[i][j] = 0;
                } else {
                    arr[i][j] = 1;
                }
            }
        }
        void fun() {
            
        }
	}
	return 0;
}