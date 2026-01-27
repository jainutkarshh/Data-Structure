#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int og = x;
        long rev = 0;
        
        while(x > 0) {
            rev = (rev * 10) + (x % 10);
            x /= 10;
        }
        return og == rev;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    cout << "121 is palindrome: " << (sol.isPalindrome(121) ? "true" : "false") << endl;
    cout << "-121 is palindrome: " << (sol.isPalindrome(-121) ? "true" : "false") << endl;
    cout << "10 is palindrome: " << (sol.isPalindrome(10) ? "true" : "false") << endl;
    cout << "0 is palindrome: " << (sol.isPalindrome(0) ? "true" : "false") << endl;
    cout << "12321 is palindrome: " << (sol.isPalindrome(12321) ? "true" : "false") << endl;
    
    return 0;
}
