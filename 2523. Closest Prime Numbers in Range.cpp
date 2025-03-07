class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<int> prime;
            vector<int> ans(2, -1);
            int smallest = INT_MAX;
            for (int i = left; i <= right; i++) {
                if (isPrime(i))
                    prime.push_back(i);
            }
            for (int i = 1; i < prime.size(); i++) {
                if (prime[i] - prime[i - 1] < smallest) {
                    smallest = prime[i] - prime[i - 1];
                    ans = {prime[i - 1], prime[i]};
                }
            }
            return ans;
        }
        bool isPrime(int n) {
            if (n <= 1)
                return false;
            if (n == 2 || n == 3)
                return true;
            if (n % 2 == 0 || n % 3 == 0)
                return false;
    
            for (int i = 5; i * i <= n; i += 6) {
                if (n % i == 0 || n % (i + 2) == 0)
                    return false;
            }
    
            return true;
        }
    };