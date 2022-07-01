
void permute(int index, string &s, vector<string> &result){
        if(index == s.length()){
            result.push_back(s);
            return;
        }
        for(int i=index;i<s.length();i++){
            swap(s[index],s[i]);
            permute(index+1,s,result);
            swap(s[index],s[i]);
        }
    }
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> result;
        permute(0,s,result);
        return result;
}