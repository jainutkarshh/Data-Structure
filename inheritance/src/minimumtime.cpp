#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size() - 1; i++) {
            int currX = points[i][0];
            int currY = points[i][1];
            int targetX = points[i+1][0];
            int targetY = points[i+1][1];
            res += max(abs(targetX - currX), abs(targetY - currY));
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<vector<int>> points1 = {{1,2}, {3,4}, {2,3}};
    cout << "Test 1: " << sol.minTimeToVisitAllPoints(points1) << endl;
    
    // Test case 2
    vector<vector<int>> points2 = {{0,0}, {1,1}, {7,0}};
    cout << "Test 2: " << sol.minTimeToVisitAllPoints(points2) << endl;
    
    // Test case 3
    vector<vector<int>> points3 = {{1,1}, {1,1}, {1,1}};
    cout << "Test 3: " << sol.minTimeToVisitAllPoints(points3) << endl;
    
    return 0;
}
