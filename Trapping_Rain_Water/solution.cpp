int trappingWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int l=0,r=0;
        int ans=0;
        
        //prefix max array for finding max in the left side..
        int pre_max[n];
        pre_max[0] = arr[0];
        for(int i=1;i<n;i++){
            pre_max[i] = max(pre_max[i-1],arr[i]);
        }
        
        //suffix max array for finding max in the right side...
        int suf_max[n];
        suf_max[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            suf_max[i] = max(suf_max[i+1],arr[i]);
        }
        
        for(int i=0;i<n;i++){
            ans += (min(pre_max[i],suf_max[i])-arr[i]);
        }
        
        return ans;
    }