#include<iostream>
#include<vector>
using namespace std;

void backtrack(int n,int open,int close,string curr,vector<string> &res) {          // backtrack function
    if(curr.length() == 2*n) {          // when the current string is completed
        res.push_back(curr);            // push current in vector 
        return ;                        // base case (end of execution)
    }

    if(open<n)                      // start parentheses condition
        backtrack(n,open+1,close,curr+"(",res);
    if(close<open)                  // end parentheses condition
        backtrack(n,open,close+1,curr+")",res);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;             // pass vector for storing strings
    backtrack(n,0,0,"",res);        // call recursive backtrack function

    return res;
}

int main() {
    int n = 6;

    vector<string> ans = generateParenthesis(n);        // catch vector<string> generated
    for(int i=0; i<ans.size(); i++)                     // display all possible parentheses generated
        cout << ans[i] << endl ;

    return 0;
}