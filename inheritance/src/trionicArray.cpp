#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), i = 1;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        int p = i - 1;
        while (i < n && nums[i - 1] > nums[i]) {
            i++;
        }
        int q = i - 1;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        int flag = i - 1;
        return (p != 0) && (q != p) && (flag == n - 1 && flag != q);
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Valid trionic array (ascending -> descending -> ascending)
    vector<int> test1 = {1, 2, 3, 2, 1, 2, 3};
    cout << "Test 1 [1,2,3,2,1,2,3]: " << (sol.isTrionic(test1) ? "true" : "false") << endl;
    
    // Test case 2: Simple trionic array
    vector<int> test2 = {1, 3, 2};
    cout << "Test 2 [1,3,2]: " << (sol.isTrionic(test2) ? "true" : "false") << endl;
    
    // Test case 3: Not trionic - missing first ascending part
    vector<int> test3 = {3, 2, 1};
    cout << "Test 3 [3,2,1]: " << (sol.isTrionic(test3) ? "true" : "false") << endl;
    
    // Test case 4: Valid trionic array
    vector<int> test4 = {1, 2, 3, 4, 5, 4, 3, 2, 1, 2, 3};
    cout << "Test 4 [1,2,3,4,5,4,3,2,1,2,3]: " << (sol.isTrionic(test4) ? "true" : "false") << endl;
    
    // Test case 5: Not trionic - missing last ascending part
    vector<int> test5 = {1, 2, 3, 2, 1};
    cout << "Test 5 [1,2,3,2,1]: " << (sol.isTrionic(test5) ? "true" : "false") << endl;
    
    return 0;
}
