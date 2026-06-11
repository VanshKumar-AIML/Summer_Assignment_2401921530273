#include<iostream>
#include<stack>
using namespace std;

string decodeString(string s) {
    string ans = "";                // initial current string
    stack<string> str_st;           // string stack
    stack<int> num_st;              // number stack
    int c_num = 0;                  // initial repeating number

    for(char c:s) {
        if(isdigit(c))
            c_num = c_num*10 + (c-'0');     // saving number

        else if (c=='[') {          // filling string stack and num stack
            num_st.push(c_num);
            str_st.push(ans);

            ans = "";
            c_num = 0;
        }

        else if (c==']') {          // saving repeat times
            int repeatTimes = num_st.top();
            num_st.pop();

            string prev_str = str_st.top();     // taking last string
            str_st.pop();

            string exp_str = "";            // expanding
            for(int i=0; i<repeatTimes; ++i)    
                exp_str += ans;

            ans = prev_str + exp_str;       // taking answer
        }

        else 
            ans += c;           // for special chars    

    }
    return ans;         // answer
}

int main() {
    string s = "3[a2[c]]";
    cout << decodeString(s) ; 

    return 0;
}