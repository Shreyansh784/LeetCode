class Solution {
    public:
        string smallestNumber(string pattern) {
            stack<char> st;
            int n = pattern.size();
            string ans = "";
            for (int i = 0; i <= n; i++) {
                st.push(i + 1);
                if (i==n||pattern[i] == 'I')
                    while (!st.empty()) {
                        ans += (st.top()+'0');
                        st.pop();
                    }
            }
            return ans;
        }
    };