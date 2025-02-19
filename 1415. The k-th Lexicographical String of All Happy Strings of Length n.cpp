//Brute Force
class Solution {
    public:
        string getHappyString(int n, int k) {
            string curr="";
            vector<string>ans;
            generate(n,curr,ans);
            if (ans.size()<k)
            return "";
            sort(ans.begin(),ans.end());
            return ans[k-1];
        }
        void generate(int &n,string curr,vector<string>&ans)
        {
            if (curr.size()==n)
            {
                ans.push_back(curr);
                return;
            }
            for (char a='a';a<='c';a++)
            {
                if (curr.size()>0&&curr.back()==a) continue;
                generate(n,curr+a,ans);
            }
        }
    };






//Optiizes using vitwise operators and math
class Solution {
    public:
        string getHappyString(int n, int k) {
            int total = 3 * (1 << (n - 1));  
    
            k--;  
            if (k >= total) return "";  
    
            string answer;
            int powtwo = 1 << (n - 1); 
            answer.push_back('a' + (k / powtwo));
            k %= powtwo;  
    
            for (int i = 1; i < n; i++) {
                powtwo >>= 1;  
                char prev = answer.back();  
                if (k / powtwo == 0) {  
                    answer.push_back(prev == 'a' ? 'b' : 'a'); 
                } else {
                    answer.push_back(prev == 'c' ? 'b' : 'c');
                }
                
                k %= powtwo;  
            }
    
            return answer;
        }
    };
    
