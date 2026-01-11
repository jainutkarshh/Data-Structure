#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // Find middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* node = nullptr;
        while(second){
            ListNode* temp = second->next;
            second->next = node;
            node = second;
            second = temp;
        }
        
        // Merge first half and reversed second half
        ListNode* first = head;
        second = node;

        while(second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};

// Helper function to create a linked list from array
ListNode* createList(vector<int>& arr) {
    if(arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for(int i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head, string testName) {
    cout << testName << ": ";
    ListNode* current = head;
    while(current) {
        cout << current->val;
        if(current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

// Helper function to delete linked list (free memory)
void deleteList(ListNode* head) {
    while(head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;
    
    cout << "===== Reorder List Test Cases =====" << endl << endl;

    // Test Case 1: [1,2,3,4]
    cout << "Test Case 1: [1,2,3,4]" << endl;
    vector<int> arr1 = {1, 2, 3, 4};
    ListNode* head1 = createList(arr1);
    printList(head1, "Before reorder");
    solution.reorderList(head1);
    printList(head1, "After reorder ");
    cout << "Expected: 1 -> 4 -> 2 -> 3" << endl << endl;
    deleteList(head1);

    // Test Case 2: [1,2,3,4,5]
    cout << "Test Case 2: [1,2,3,4,5]" << endl;
    vector<int> arr2 = {1, 2, 3, 4, 5};
    ListNode* head2 = createList(arr2);
    printList(head2, "Before reorder");
    solution.reorderList(head2);
    printList(head2, "After reorder ");
    cout << "Expected: 1 -> 5 -> 2 -> 4 -> 3" << endl << endl;
    deleteList(head2);

    // Test Case 3: Single element [1]
    cout << "Test Case 3: [1]" << endl;
    vector<int> arr3 = {1};
    ListNode* head3 = createList(arr3);
    printList(head3, "Before reorder");
    solution.reorderList(head3);
    printList(head3, "After reorder ");
    cout << "Expected: 1" << endl << endl;
    deleteList(head3);

    // Test Case 4: Two elements [1,2]
    cout << "Test Case 4: [1,2]" << endl;
    vector<int> arr4 = {1, 2};
    ListNode* head4 = createList(arr4);
    printList(head4, "Before reorder");
    solution.reorderList(head4);
    printList(head4, "After reorder ");
    cout << "Expected: 1 -> 2" << endl << endl;
    deleteList(head4);

    // Test Case 5: [1,2,3]
    cout << "Test Case 5: [1,2,3]" << endl;
    vector<int> arr5 = {1, 2, 3};
    ListNode* head5 = createList(arr5);
    printList(head5, "Before reorder");
    solution.reorderList(head5);
    printList(head5, "After reorder ");
    cout << "Expected: 1 -> 3 -> 2" << endl << endl;
    deleteList(head5);

    // Test Case 6: Larger list [1,2,3,4,5,6,7]
    cout << "Test Case 6: [1,2,3,4,5,6,7]" << endl;
    vector<int> arr6 = {1, 2, 3, 4, 5, 6, 7};
    ListNode* head6 = createList(arr6);
    printList(head6, "Before reorder");
    solution.reorderList(head6);
    printList(head6, "After reorder ");
    cout << "Expected: 1 -> 7 -> 2 -> 6 -> 3 -> 5 -> 4" << endl << endl;
    deleteList(head6);

    cout << "===== All Tests Completed =====" << endl;

    return 0;
}
