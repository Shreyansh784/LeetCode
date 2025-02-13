class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue <long, vector<long>, greater<long> > pq; 
            for (int i=0;i<nums.size();i++)
            pq.push(nums[i]);
            int count=0;
            while(pq.top()<k)
            {
                long x=pq.top();
                pq.pop();
                long y=pq.top();
                pq.pop();
                pq.push(x * 2 + y);
                count++;
            }
            return count;
        }
    };