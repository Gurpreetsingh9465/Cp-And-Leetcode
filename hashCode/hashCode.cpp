#include<bits/stdc++.h>
using namespace std;

string file_name = "b_read_on.txt";
string output_name = "b_read_on_output.txt";

unordered_map<int, int> bookUsed;
vector<int> sequence;
unordered_set<int> set_sequence;

vector<int> split(string str, string token){
    vector<int>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(stoi(str.substr(0,index)));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(stoi(str));
        } else {
            result.push_back(stoi(str));
            str = "";
        }
    }
    return result;
}

bool comparator(pair<int,int> l, pair<int, int> r) {
    return l.first>r.first;
}

bool comparator2(pair<int,int> l, pair<int, int> r) {
    return l.second>r.second;
}

class Library {
    public:
      int b,sp,ships;
      vector<pair<int,int>> ids;
      Library(int b, int sp, int ships, vector<pair<int,int>> ids) { // id,score
          this->b = b;
          this->sp = sp;
          this->ships = ships;
          sort(ids.begin(), ids.end(), comparator2);
          this->ids = ids;
      }
      int getScore(int D, int currentDay) {
          int numberOfBooks = (D-currentDay-sp)*ships;
          if(numberOfBooks < 0) {
              return 0;
          }
          int score = 0;
          int bookCount = 0;
          unordered_set<int> local_set;
          for(int i = 0;i<ids.size();i++) {
              if(bookUsed.find(ids[i].first) == bookUsed.end() && local_set.find(ids[i].first) == local_set.end()) {
                  score+=ids[i].second;
                  local_set.insert(ids[i].first);
                  bookCount++;
              }
              if(bookCount >= numberOfBooks) {
                  break;
              }
          }
          return score;
      }
      bool addScore(int D, int currentDay, int index) {
          int numberOfBooks = (D-currentDay-sp)*ships;
          if(numberOfBooks < 0) {
              return false;
          }
          int score = 0;
          int bookCount = 0;
          unordered_set<int> local_set;
          for(int i = 0;i<ids.size();i++) {
              if(bookUsed.find(ids[i].first) == bookUsed.end() && local_set.find(ids[i].first) == local_set.end()) {
                  score+=ids[i].second;
                  local_set.insert(ids[i].first);
                  bookUsed.insert({ids[i].first, index});
                  bookCount++;
              }
              if(bookCount >= numberOfBooks) {
                  break;
              }
          }
          return true;
      }
};

void calculate(int B, int L, int D, vector<Library> &libraries, unordered_map<int,int> &scores) { // score, index
    for(int i=0;i<D;i++) {
        int max_score = INT_MIN;
        int pick = -1;
        for(int j=0;j<libraries.size();j++) {
            if(set_sequence.find(j) != set_sequence.end()) {
                continue;
            }
            int score = libraries[j].getScore(D,i);
            if(score>max_score) {
                pick = j;
                max_score = score;
            }
        }
        if(pick!=-1) {
            bool con = libraries[pick].addScore(D, i, pick);
            if(con) {
                i+=(libraries[pick].sp);
                set_sequence.insert(pick);
                sequence.push_back(pick);
            }
        }
    }
}

int main() {
    char* inFile = strcpy(new char[file_name.length() + 1], file_name.c_str());
    char* outFile = strcpy(new char[output_name.length() + 1], output_name.c_str());
    freopen(inFile, "r", stdin);
    freopen(outFile, "w", stdout);
    int B,L,D;
    cin>>B>>L>>D;
    unordered_map<int,int> scores;
    vector<Library> libraries;
    for(int i = 0;i<B;i++) {
        int x;
        cin>>x;
        scores[x] = i;
    }
    for(int i = 0;i<L;i++) {
        int b,sp,ships;
        cin>>b>>sp>>ships;
        vector<int> line2(b);
        int index = 0;
        for(int j=0;j<b;j++) {
            int idOfBook;
            cin>>idOfBook;
            line2[index++] = idOfBook;
        }
        vector<pair<int,int>> id_score;
        for(auto &k: line2) {
            id_score.push_back({k, scores[k]});
        }
        Library lib(b,sp, ships, id_score);
        libraries.push_back(lib);
    }
    calculate(B, L, D, libraries, scores);
    int number_of_lib = sequence.size();
    unordered_map<int, vector<int>> ans;
    for(auto &i: bookUsed) {
        ans[i.second].push_back(i.first);
    }
    cout<<number_of_lib<<endl;
    for(auto &i: ans) {
        cout<<i.first<<" "<<i.second.size()<<endl;
        for(auto &j: i.second) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


