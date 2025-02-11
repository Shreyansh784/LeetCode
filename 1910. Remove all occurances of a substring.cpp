#include <iostream>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.size();
        
        while (true) {
            size_t i = s.find(part);
            if (i == string::npos) break;  // If 'part' not found, exit loop
            s.erase(i, m);  // Correct erase: remove 'm' characters from index 'i'
        }
        return s;
    }
};

// Driver Code
int main() {
    Solution sol;
    string s = "daabcbaabcbc", part = "abc";
    cout << sol.removeOccurrences(s, part) << endl;  // Output: "dab"

    return 0;
}
