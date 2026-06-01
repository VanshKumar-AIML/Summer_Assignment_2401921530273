#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minP =prices[0];        // initial minimum price
    int maxProfit = 0;

    for(int i=0; i<prices.size(); i++) {
        minP = min(minP,prices[i]);          // get min price

        int cp = prices[i]-minP;            // profit 
        maxProfit = max(maxProfit,cp);        // update max
    }
        
    return maxProfit;
}

int main() {
    vector<int> prices = {8,1,5,3,7,4} ;
    cout << maxProfit(prices) ;
    return 0;
}