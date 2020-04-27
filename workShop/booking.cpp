#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<float,char> left, pair<float,char> right) {
    return right.first>left.first;
}

vector<pair<float, char>> mergeArray(vector<float> arrival, vector<float> deparcher) {
    vector<pair<float, char>> combined(arrival.size()+deparcher.size());
    int index = 0;
    int aIndex = 0;
    int dIndex = 0;
    while (aIndex < arrival.size() && dIndex < deparcher.size()) {
        if(arrival[aIndex] > deparcher[dIndex]) {
            combined[index++] = {deparcher[dIndex++], 'd'};
        } else {
            combined[index++] = {arrival[aIndex++], 'a'};
        }
    }

    while (aIndex < arrival.size()) {
        combined[index++] = {arrival[aIndex++], 'a'};
    }
    
    while (dIndex < deparcher.size()) {
        combined[index++] = {deparcher[dIndex++], 'd'};
    }
    return combined;
}



void resultCalculator(vector<float> arrival, vector<float> deparcher) {
    vector<pair<float, char>> combined = mergeArray(arrival, deparcher);
    float totalTime = combined[combined.size()-1].first;
    pair<pair<vector<float>,map<float, int>>, vector<pair<float, float>>> ans = calculate(combined);
}


int main() {
    vector<float> arrival = {0.4, 1.6, 2.1, 3.8,4.0,5.6,5.8,7.2};
    vector<float> deparcher = {2.4,3.1,3.3,4.9,8.6};
    resultCalculator(arrival, deparcher);
    return 0;
}
