 public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(m<n) return kthElement(arr2,arr1,m,n,k);
        int low = max(0,k-m), high = min(k,n);
        while(low<=high){
            int cut1 = (low+high) >> 1;
            int cut2 =  k - cut1;
            int l1 = (cut1!=0)?arr1[cut1-1]:INT_MIN;
            int l2 = (cut2!=0)?arr2[cut2-1]:INT_MIN;
            int r1 = (cut1!=n)?arr1[cut1]:INT_MAX;
            int r2 = (cut2!=m)?arr2[cut2]:INT_MAX;
            
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }else if(l1>r2){
                high = cut1 - 1;
            }else{
                low = cut1 + 1;
            }
        }
        return 1;
    }