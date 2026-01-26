#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return NULL;
        ListNode* ans= new ListNode(0,head);
        ListNode* dummy=ans;

        while(dummy != nullptr){
            while(dummy->next !=nullptr&& dummy->next->val==val){
                dummy->next = dummy->next->next;
            }
            dummy= dummy->next;
        }
        ListNode* result = ans->next;
        delete ans;
        return result;
    }    
};

// Helper function to print linked list
void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to delete linked list
void deleteList(ListNode* head) {
    while(head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test case: [1, 2, 6, 3, 4, 5, 6], val = 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    
    cout << "Original list: ";
    printList(head);
    
    Solution sol;
    head = sol.removeElements(head, 6);
    
    cout << "After removing 6: ";
    printList(head);
    
    deleteList(head);
    return 0;
}
