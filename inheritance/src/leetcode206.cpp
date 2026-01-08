#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    cout << "[";
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        current = current->next;
        if (current != nullptr) cout << ",";
    }
    cout << "]" << endl;
}

// Helper function to delete the linked list (free memory)
void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;

    // Test Case 1: [1,2,3,4,5] -> [5,4,3,2,1]
    cout << "Test Case 1:" << endl;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createLinkedList(arr1);
    cout << "Input:  ";
    printLinkedList(head1);
    head1 = createLinkedList(arr1); // Recreate since we modified it
    ListNode* result1 = solution.reverseList(head1);
    cout << "Output: ";
    printLinkedList(result1);
    deleteLinkedList(result1);

    // Test Case 2: [1,2] -> [2,1]
    cout << "\nTest Case 2:" << endl;
    vector<int> arr2 = {1, 2};
    ListNode* head2 = createLinkedList(arr2);
    cout << "Input:  ";
    printLinkedList(head2);
    head2 = createLinkedList(arr2); // Recreate since we modified it
    ListNode* result2 = solution.reverseList(head2);
    cout << "Output: ";
    printLinkedList(result2);
    deleteLinkedList(result2);

    // Test Case 3: [] -> []
    cout << "\nTest Case 3:" << endl;
    vector<int> arr3 = {};
    ListNode* head3 = createLinkedList(arr3);
    cout << "Input:  ";
    printLinkedList(head3);
    ListNode* result3 = solution.reverseList(head3);
    cout << "Output: ";
    printLinkedList(result3);
    deleteLinkedList(result3);

    // Additional Test Case: Single element [42] -> [42]
    cout << "\nTest Case 4 (Single Element):" << endl;
    vector<int> arr4 = {42};
    ListNode* head4 = createLinkedList(arr4);
    cout << "Input:  ";
    printLinkedList(head4);
    head4 = createLinkedList(arr4); // Recreate since we modified it
    ListNode* result4 = solution.reverseList(head4);
    cout << "Output: ";
    printLinkedList(result4);
    deleteLinkedList(result4);

    return 0;
}
