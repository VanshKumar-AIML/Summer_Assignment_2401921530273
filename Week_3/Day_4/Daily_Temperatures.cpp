#include<iostream>
#include<vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int hottest = 29;       // max days
    vector<int> ans(temperatures.size());       // answer vector initialised

    for (int i = temperatures.size() - 1; i >= 0; --i) {    // reverse order
        if (temperatures[i] >= hottest) {
            hottest = temperatures[i];      // finding hottest day
            continue;
        }

        int days = 1;       // initialised from day 1
        while (temperatures[i + days] <= temperatures[i]) {     // adding and comparing days 
            days += ans[i + days];
        }

        ans[i] = days;      // taking answer
    }

    return ans;
}

int main() {
    vector<int> t = {73,74,75,71,69,72,76,73};   // input
    vector<int> res = dailyTemperatures(t);      // function called
    for(int i=0; i<res.size(); i++)              // display answer
        cout << res[i] << " ";

    return 0;
}