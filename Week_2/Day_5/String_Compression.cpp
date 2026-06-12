#include<iostream>
#include<vector>
using namespace std;

int compress(vector<char>& chars) {
    int wr = 0;     // write pointer
    int rd = 0;     // read pointer
    int n = chars.size();

    while(rd < n) {         // read < total size
        char c_char = chars[rd];        // current char (initial)
        int c = 0;                  // count

        while(rd < n && chars[rd] == c_char) {
            rd++;           // increment read for read next
            c++;
        }

        chars[wr++] = c_char;       // write the current char
        
        if(c > 1) {
            string c_str = to_string(c);
            for(char c:c_str) 
                chars[wr++] = c;            // push count of repeated char to chars vector
        }
    }

    return wr;          // final write index -> till where chars are written
}

int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};
    cout << compress(chars);
    
    return 0;
}