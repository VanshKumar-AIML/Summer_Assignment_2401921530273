#include<iostream>
using namespace std;

struct ListNode {               // structure of Linked List node
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* p = nullptr;      // previous node
    ListNode* c = head;         // current node

    while(c != nullptr) {
        ListNode* nextNode = c->next;       // next node
        c->next = p;            // swap p and c 
        p = c;
        c = nextNode;
    }

    return p;       // return previous node
}

int main() {
    // created nodes :
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // function called : (reversed)
    ListNode* rh = reverseList(head);       // reversed linked list
    ListNode* c = rh;

    while(c!=nullptr) {     // display of reversed singly linked list
        cout << c->val << " -> " ;
        c = c->next;
    }
    cout << "null";

    return 0;
}