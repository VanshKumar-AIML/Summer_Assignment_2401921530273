#include<iostream>
using namespace std;

struct ListNode {                   // Structure of Singly Linked List
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);        // dummy node created
    ListNode* slow = dummy;         // slow-fast pointers
    ListNode* fast = dummy;

    for(int i=0; i<n; ++i)      // move till n value
        fast = fast->next;

    while(fast->next != nullptr) {      // slow following fast
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* d = slow->next;       // node to be removed
    slow->next = slow->next->next;  // removed node

    delete d;           // free memory from removed node
    ListNode* new_head = dummy->next;       // new linked list head

    return new_head;            // linked list returned
}

int main() {
    // Create Linked List nodes :
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;                  // Nth element to be removed from end of linked list

    ListNode* c1 = head;            // original input Linked List
    cout << "Original input list:" << endl;
    while(c1!=nullptr) {
        cout << c1->val << " -> ";
        c1 = c1->next;
    }
    cout << "null" << endl;

    ListNode* h = removeNthFromEnd(head,n);     // function called
    ListNode* c2 = h;
    cout << "Removed element list:" << endl;
    while(c2!=nullptr) {             // display Linked List
        cout << c2->val << " -> " ;
        c2 = c2->next;
    }
    cout << "null";

    return 0;
}