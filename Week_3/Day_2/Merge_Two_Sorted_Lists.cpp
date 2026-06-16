#include<iostream>
using namespace std;

struct ListNode {               // Structure of Linked List
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode d(0);          // dummy  
    ListNode* t = &d;       // tail node

    while(list1 && list2) {
        if(list1->val < list2->val) {       // take lesser value first
            t->next = list1;        
            list1 = list1->next;        // move list1 
        }
        else {
            t->next = list2;
            list2 = list2->next;        // move list2
        }
        t = t->next;            // move tail forward
    }

    t->next = list1 ? list1 : list2;        // non-empty list attached
    return d.next;      // return linkded list attached to dummy 
}

int main() {
    // Create lists : (nodes)
    ListNode* h1 = new ListNode(1);     // list-1
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(4);
    ListNode* h2 = new ListNode(1);     // list-2
    h2->next = new ListNode(3);
    h2->next->next = new ListNode(4);

    ListNode* m = mergeTwoLists(h1,h2);     // merge two sorted list (function called)
    ListNode* t = m;
    while(t!=nullptr) {                 // display function
        cout << t->val << " -> ";
        t = t->next;
    }
    cout << "null";

    return 0;
}