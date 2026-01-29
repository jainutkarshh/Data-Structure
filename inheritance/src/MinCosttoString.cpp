#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = 1e18;
        long long ans = 0;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        for(int i = 0; i < 26; i++){
            dist[i][i] = 0;
        }
        
        for(int i = 0; i < original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd-Warshall Algorithm
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        for(int i = 0; i < source.size(); i++){
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if(dist[s][t] == INF){
                return -1;
            }
            ans += dist[s][t];
        }
        return ans;
    }
};

int main(){
    Solution sol;
    
    // Test case 1
    string source1 = "abcd";
    string target1 = "acbe";
    vector<char> original1 = {'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed1 = {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost1 = {2, 5, 5, 1, 2, 20};
    
    long long result1 = sol.minimumCost(source1, target1, original1, changed1, cost1);
    cout << "Test case 1: " << result1 << endl;
    
    // Test case 2
    string source2 = "aaaa";
    string target2 = "bbbb";
    vector<char> original2 = {'a', 'c'};
    vector<char> changed2 = {'b', 'd'};
    vector<int> cost2 = {1, 2};
    
    long long result2 = sol.minimumCost(source2, target2, original2, changed2, cost2);
    cout << "Test case 2: " << result2 << endl;
    
    // Test case 3
    string source3 = "abc";
    string target3 = "bbb";
    vector<char> original3 = {'a', 'c'};
    vector<char> changed3 = {'b', 'b'};
    vector<int> cost3 = {1, 2};
    
    long long result3 = sol.minimumCost(source3, target3, original3, changed3, cost3);
    cout << "Test case 3: " << result3 << endl;
    
    return 0;
}
