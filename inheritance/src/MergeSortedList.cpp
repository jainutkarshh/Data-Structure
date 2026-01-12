#include <iostream>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode(0);
        ListNode* curr = temp;

        while(list1 && list2){
            if(list1->val > list2->val){
                curr->next = list2;
                list2 = list2->next;
            }else{
                curr->next = list1;
                list1 = list1->next;
            }
            curr = curr->next;
        }
        curr->next = list1 ? list1 : list2;

        ListNode* head = temp->next;
        delete temp;
        return head;
    }
};

// Helper function to create a linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    cout << "List: ";
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to delete linked list (free memory)
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;

    // Test Case 1: [1,2,4] and [1,3,4]
    cout << "Test Case 1:" << endl;
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);
    
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    
    list1 = createList(arr1, 3);
    list2 = createList(arr2, 3);
    ListNode* merged = solution.mergeTwoLists(list1, list2);
    cout << "Merged: ";
    printList(merged);
    deleteList(merged);
    cout << endl;

    // Test Case 2: [] and []
    cout << "Test Case 2:" << endl;
    list1 = createList(arr1, 0);
    list2 = createList(arr2, 0);
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    merged = solution.mergeTwoLists(list1, list2);
    cout << "Merged: ";
    printList(merged);
    deleteList(merged);
    cout << endl;

    // Test Case 3: [] and [0]
    cout << "Test Case 3:" << endl;
    list1 = createList(arr1, 0);
    int arr3[] = {0};
    list2 = createList(arr3, 1);
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    merged = solution.mergeTwoLists(list1, list2);
    cout << "Merged: ";
    printList(merged);
    deleteList(merged);
    cout << endl;

    // Test Case 4: [1,3,5,7] and [2,4,6,8]
    cout << "Test Case 4:" << endl;
    int arr4[] = {1, 3, 5, 7};
    int arr5[] = {2, 4, 6, 8};
    list1 = createList(arr4, 4);
    list2 = createList(arr5, 4);
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    merged = solution.mergeTwoLists(list1, list2);
    cout << "Merged: ";
    printList(merged);
    deleteList(merged);
    cout << endl;

    // Test Case 5: Single element lists [5] and [3]
    cout << "Test Case 5:" << endl;
    int arr6[] = {5};
    int arr7[] = {3};
    list1 = createList(arr6, 1);
    list2 = createList(arr7, 1);
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    merged = solution.mergeTwoLists(list1, list2);
    cout << "Merged: ";
    printList(merged);
    deleteList(merged);

    return 0;
}
