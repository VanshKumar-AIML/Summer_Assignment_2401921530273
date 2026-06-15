#include<iostream>
using namespace std;

struct ListNode {           // Structure of Linked List node
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;          // slow - fast pointer approach
    ListNode* fast = head;

    while(fast!=nullptr && fast->next!=nullptr) {
        slow = slow->next;          // one step
        fast = fast->next->next;    // two step
    }

    return slow;        // points to the middle (only one middle node)
}

int main() {
    // Linked List nodes created :
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);


    // linked list from middle :
    ListNode* m = middleNode(head);
    ListNode* c = m;

    // display of half linked list from mid :
    while(c!=nullptr) {
        cout << c->val << " -> ";
        c = c->next;
    }
    cout << "null";

    return 0;
}