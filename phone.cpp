#include<bits/stdc++.h>

using namespace std;

vector<char> getLetters(char digit){
    switch(digit){
        case '2':
            return {'a','b','c'};
        case '3':
            return {'d','e','f'};
        case '4':
            return {'g','h','i'};
        case '5':
            return {'j','k','l'};
        case '6':
            return {'m','n','o'};
        case '7':
            return {'p','q','r','s'};
        case '8':
            return {'t','u','v'};
        case '9':
            return {'w','x','y','z'};
        default:
            return {};
    }
}



vector<vector<char>> letterCombinations(string digits) {
    if
    vector<vector<char>> arr(digits.length());
    for(int i=0;i<digits.length();i++) {
        arr[i] = getLetters(digits[i]);
    }
    return arr;
}

// string getPrint(vector<char> c) {
//     string ans = "";
//     for(char i : c) {
//         ans = ans + i + " ";
//     }
//     return ans;
// }
// void printVector(vector<vector<char>> c) {
//     for(vector<char> i: c) {
//         cout<<getPrint(i)<<", ";
//     }
//     cout<<endl;
// }

int main() {
    printVector(letterCombinations("2457"));
    return 0;
}