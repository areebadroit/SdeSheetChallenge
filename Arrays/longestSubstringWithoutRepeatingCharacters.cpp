//Solution 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sLen = s.length();
        int leftIndex = 0;
        int rightIndex = 0;
        int maxLen = 0;
        unordered_set<char> hashSet;
        while(rightIndex<sLen){
            if(hashSet.find(s[rightIndex])==hashSet.end()){
                //no repeat
                hashSet.insert(s[rightIndex]);
                maxLen=max(maxLen,(rightIndex-leftIndex)+1);
                rightIndex++;
            }else{
                hashSet.erase(s[leftIndex]);
                leftIndex++;
            }
        }
        return maxLen;
    }
};

// Solution 2 - Instead of using set, we will use map to optimise the code