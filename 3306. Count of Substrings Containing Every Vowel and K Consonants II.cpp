class Solution {
    public:
        long long countOfSubstrings(string word, int k) {
            return f(word,k)-f(word,k-1);
        }
        bool isVowel(char a){
            return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
        }
        long long f(string word,int k)
        {
            unordered_map<char, long long> mpp;
            long long l = 0, r = 0;
            long long con = 0, count = 0;
            while (r < word.size()) {
                if (isVowel(word[r])) mpp[word[r]]++;
                else con++;
                while(con>k&&mpp.size()>=5)
                {
                    if (isVowel(word[l])){ 
                        mpp[word[l]]--;
                        if (mpp[word[l]]==0) mpp.erase(word[l]);
                        }
                    else con--;
                    l++;
                }
                    count+=r-l+1;
                r++;
            }
            return count;
        }
    };