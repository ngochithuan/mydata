#include<iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

void addLast(ListNode* head, int val) {
    struct ListNode *node = head;
    struct ListNode *newNode = nullptr;
    newNode->val = val;
    newNode->next = nullptr;
    while(node != nullptr){
        if(node->next == nullptr) {
            node->next = newNode;
        }
    }
}

ListNode* reverseList(ListNode* head) {
        struct ListNode *ll = nullptr;

}

int main() {
    // while(node.next != nullptr){
    //     cout << node.val << '\n';
    //     node = node.next;
    // }
    struct ListNode *node = nullptr;
    node->val = 1;
    node->next = nullptr;

    addLast(node, 2);
    struct ListNode *readNode = node;
    while(readNode != nullptr){
        cout << readNode->val << '\n';
        readNode = readNode->next;
    }
    return 0;
}