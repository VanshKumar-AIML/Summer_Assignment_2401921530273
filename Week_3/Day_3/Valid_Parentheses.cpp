#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;     // stack initialised

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') 
            st.push(c);         // for opening parentheses
            
        else {
            if (st.empty())         // if no closing then false
                return false;

            char top = st.top();    // take top char
            st.pop();               // remove top char

            if ((c == ')' && top != '(') ||         // see conditions on top and c -> char
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) 
                return false;

        }
    }

    return st.empty();          // if complete stack is empty then true else false
}

int main() {
    string s = "()[]{}";        // input string
    cout << isValid(s);         // function called

    return 0;
}