#include<iostream>
#include<vector>
using namespace std;

struct ListNode {               // Structure of Linked List
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
void t(ListNode* node, vector<int>& v) {            // traversal function
    if(node==nullptr)           // base case condition
        return ;

    v.push_back(node->val);
    t(node->next,v);        // recursive call
}

bool ispalindrome(ListNode* head) { 
    vector<int>v;                    // vector used to store elements of linked list
    t(head,v);                      // traversal function used

    int l=0, r=v.size()-1;              // two pointer approach to check palindrome
    while(l <= r) {
        if(v[l] != v[r])
            return false;
        l++;
        r--;
    }

    return true;
}

ListNode* reverseList(ListNode* head) {     // reverse function
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next)                   // edge case handling
        return true;

    // Find middle using fast & slow pointers
    ListNode* slow = head;      // slow-fast pointer approach
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode* secondHalf = reverseList(slow->next);

    // Compare both halves
    ListNode* p1 = head;
    ListNode* p2 = secondHalf;
    while (p2) {
        if (p1->val != p2->val)         // checking values
            return false;

        p1 = p1->next;              // moving one move forward      
        p2 = p2->next;
    }

    return true;
}

int main() {
    ListNode* head = new ListNode(1);
    cout << ispalindrome(head) << endl;     // using vector memory (Two pointer approach)
    cout << isPalindrome(head) << endl;     // using reverse function (Slow - Fast pointer approach)

    return 0;
}