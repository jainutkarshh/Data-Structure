#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans ='{';
        for(int i=0;i<letters.size();i++){
            if(letters[i]>target&&letters[i]<ans){
                ans= letters[i];
            }
        }
        if (ans == '{') {
            return letters[0];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<char> letters1 = {'c', 'f', 'j'};
    char target1 = 'a';
    cout << "Input: letters = [c, f, j], target = a" << endl;
    cout << "Output: " << sol.nextGreatestLetter(letters1, target1) << endl << endl;
    
    // Test case 2
    vector<char> letters2 = {'c', 'f', 'j'};
    char target2 = 'c';
    cout << "Input: letters = [c, f, j], target = c" << endl;
    cout << "Output: " << sol.nextGreatestLetter(letters2, target2) << endl << endl;
    
    // Test case 3
    vector<char> letters3 = {'c', 'f', 'j'};
    char target3 = 'j';
    cout << "Input: letters = [c, f, j], target = j" << endl;
    cout << "Output: " << sol.nextGreatestLetter(letters3, target3) << endl << endl;
    
    return 0;
}
