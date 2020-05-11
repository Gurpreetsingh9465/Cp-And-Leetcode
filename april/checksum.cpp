#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int hexToDec(string s) {
    int count= 0;
    int ans = 0;
    for(int i = s.length()-1;i>=0;i--) {
        int digit = 0;
        if(s[i] >= '0' && s[i]<= '9') {
            digit = (s[i] - '0');
        } else {
            digit = (s[i] - 'A') + 10;
        }
        ans = ans + (pow(16,count) * (digit));
        count++;
    }
    return ans;
}

string decToHex(int decimal) {
    string ans = "";
    while (decimal) {
        int digit = decimal%16;
        if(digit>=0 && digit<=9) {
            ans = (char)(digit+'0')+ans;
        } else {
            digit%=10;
            ans = (char)(digit+'A')+ans;
        }
        decimal/=16;
    }
    return ans;
}

string addHex(string s1, string s2) {
    int a1 = hexToDec(s1);
    int a2 = hexToDec(s2);
    string s3 = decToHex(a1+a2);
    if(s3.length() == 4) {
        return s3;
    }
    a1 = hexToDec(s3.substr(0,1));
    a2 = hexToDec(s3.substr(1,4));
    return decToHex(a1+a2);
}

string calculateChecksum(string s) {
    string s1 = s.substr(0,4);
    string s2 = s.substr(4,4);
    string s3 = s.substr(8,4);
    string s4 = s.substr(12,4);
    string checksum = addHex(s1,s2);
    checksum = addHex(checksum,s3);
    checksum = addHex(checksum,s4);
    return checksum;
}

int main() {
    string s;
    cout<<"Enter 64 bit Hexadecimal String eg. ABD3ADBF34DADEF0\n";
    cin>>s;
    if(s.length() != 16) {
        cout<<"Invalid string length\n";
        return 0;
    }
    for(auto &i: s) {
        if(!((i>='0' && i<='9') || (i>='A' && i<='F'))) {
            cout<<"Invalid\n";
            return 0;
        }
    }
    string checksum = calculateChecksum(s);

    cout<<"Checksum is = "<<checksum<<"\n";
    return 0;
}


