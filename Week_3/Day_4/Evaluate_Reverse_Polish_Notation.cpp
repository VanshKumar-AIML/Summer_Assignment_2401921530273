#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int evalRPN(vector<string>& tokens) {       // evaluate reverse polish notation
    stack<int> st;          // take stack to solve expression
    vector<string> s = tokens ;     // take tokens in vector space

    for(int i=0; i<s.size(); i++) {
        // if operation as input then perform task
        if((s[i]=="+") || (s[i]=="-") || (s[i]=="*") || (s[i]=="/")) {
            long b = st.top();      // take values from stack
            st.pop();
            long a = st.top();
            st.pop();
            
            if(s[i]=="+")           // perform operation
                st.push(a+b);
            else if(s[i]=="-")
                st.push(a-b);
            else if(s[i]=="*")
                st.push(a*b);
            else if(s[i]=="/")
                st.push(a/b);
            }

        else
            st.push(stoi(s[i]));        // else push value to stack 
                                        // by using stoi (string to integer)
    }

    return (int)st.top();       // final answer at top of the stack (taking as integer)
}                

int main() {
    vector<string> t = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};       // input tokens
    cout << evalRPN(t);         // final evaluated answer

    return 0;
}