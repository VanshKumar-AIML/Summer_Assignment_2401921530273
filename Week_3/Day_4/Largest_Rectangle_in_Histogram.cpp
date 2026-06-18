#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    // Add a sentinel height of 0 at the end. This forces every bar still
    // sitting in the stack to get "closed out" and have its area computed
    // by the time we finish the loop, so we don't need cleanup code after.
    heights.push_back(0);

    // Stack holds indices of bars in increasing order of height.
    // -1 acts as a sentinel "left wall" so width math works for the first bar.
    stack<int> st;
    st.push(-1);
    int max_area = 0;

    for (int i = 0; i < heights.size(); i++) {
        // If the current bar is shorter than the bar on top of the stack,
        // the bar on top can't extend any further right — this is the
        // moment we know its rectangle's full extent, so we finalize it.
        while (st.top() != -1 && heights[st.top()] >= heights[i]) {
            int top_height = heights[st.top()];
            st.pop();

            // Width = distance between the bar just left exposed on the
            // stack (the new shorter left boundary) and the current index.
            int width = i - st.top() - 1;

            max_area = max(max_area, top_height * width);
        }

        // Current bar is taller than (or equal to) the new stack top,
        // so it might extend a future rectangle — push it for later.
        st.push(i);
    }

    heights.pop_back();  // remove the sentinel we added
    return max_area;
}

int main() {
    vector<int> h = {2,1,5,6,2,3};          // input :
    cout << largestRectangleArea(h);        // function called

    return 0;
}