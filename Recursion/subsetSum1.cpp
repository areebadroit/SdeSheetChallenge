void subsetSumHelper(int index, vector<int> &result, vector<int> &arr, long long &sum){
        if(index == arr.size()){
            result.push_back(sum);
            return;
        }
        sum+=arr[index];
        subsetSumHelper(index+1, result, arr, sum);
        sum-=arr[index];
        subsetSumHelper(index+1, result, arr, sum);
    }
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> result;
        long long sum = 0;
        subsetSumHelper(0, result, num, sum);
    sort(result.begin(),result.end());
        return result;
}