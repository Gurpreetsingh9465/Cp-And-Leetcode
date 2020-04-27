#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

class Solution {
public:
    int ans = INT_MAX;
    string endWord;
    bool canApply(string s1, string s2) {
        bool ans = true;
        int index = 0;
        while(index<s1.size()) {
            if(s1[index] != s2[index]) {
                if(ans == false)
                    return false;
                ans = false;
            }
            index++;
        }
        return ans == false;
    }
    void rec(string current, vector<string> wordList, int count, unordered_set<string> &se) {
        if(wordList.size() == 0)
            return;
        if(current == endWord) {
            ans = min(ans, count);
            return;
        }
        se.insert(current);
        for(int i = 0;i<wordList.size();i++) {
            if(canApply(current, wordList[i]) && se.count(wordList[i]) == 0) {
                vector<string> clone = wordList;
                clone.erase(clone.begin()+i);
                rec(wordList[i],clone, count+1,se);
            }
        }
        se.erase(current);
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        this->endWord = endWord;
        unordered_set<string> s;
        rec(beginWord, wordList, 0,s);
        if(ans == INT_MAX)
            return 0;
        return ans+1;
    }
};

int main() {
    string s1 = "qa";
    string s2 = "sq";
    vector<string> s = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    
    cout<<Solution().ladderLength(s1,s2,s)<<"\n";
    
    return 0;
}