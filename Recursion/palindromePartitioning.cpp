class Solution {
public:
    bool isPalindrome(string st){
        if(st.size() == 0) return false;
        int i=0,j=st.size()-1;
        while(i<j){
            if(st[i++]!=st[j--]) return false;
        }
        return true;
    }
    void partition(int index, string s, vector<vector<string>> &result,vector<string> &ds){
        if(index == s.size()){
            result.push_back(ds);
            return;
        }
        for(int i=index;i<s.size();i++){
            string st = s.substr(index,i-index+1);
            if(isPalindrome(st)){
                ds.push_back(st);
                partition(i+1,s,result,ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> ds;
        partition(0,s,result,ds);
        return result;
    }
};