#include<iostream>
using namespace std;

struct ListNode {       // structure for Linked List node
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
bool hasCycle(ListNode *head) {
    ListNode* slow = head;          // slow and fast pointers 
    ListNode* fast = head;

    while(fast!=nullptr && fast->next != nullptr) {
        fast = fast->next->next;        // moves two step

        if(slow==fast)          // next values are same hence cycle exists
            return true;

        slow = slow->next;      // moves one step
    }

    return false;       // cycle doesn't exist
}

int main() {
    // Create nodes   -> for test case running
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // pos = 1 means tail connects to node with value 2
    head->next->next->next->next = head->next;

    cout << hasCycle(head);
    
    return 0;
}