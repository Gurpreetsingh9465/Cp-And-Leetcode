class Solution {
public:
    
    pair<int,int> longestSubstring(string str1, string str2) {
        int row = -1;
        int col = -1;
        string result = "";
        int max = 0;
        int LCS[str1.length()+1][str2.length()+1];
        for(int i=0 ;i<=str1.length();i++) {
            for(int j=0;j<=str2.length();j++) {
                if(i==0||j==0) {
                    LCS[i][j] = 0;
                } else if(str1[i-1] == str2[j-1]) {
                    LCS[i][j] = LCS[i-1][j-1] +1;
                    if(max < LCS[i][j]) {
                        max = LCS[i][j];
                        row = i;
                        col = j;
                    }
                } else {
                    LCS[i][j] = 0;
                }
            }
        }
        int first = max-col;
        int second = col-1;
        for(first;first<=second;first++) {
            result+=str2[first];
        }
        return result;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int l = strs.size();
        if(l == 0) {
            return "";
        } else if(l == 1) {
            return strs[0];
        }
        string result = strs[0];
        for(int i =1;i<li++) {
            result = longestSubstring(result,strs[i]);
        }
        return result;
    }
};

// int main() {
//     Solution s();
//     cout<<s.
//     return 0;
// }