class Solution {
  public:
    int findSubArraySum(int k, vector<int> &arr) {
        // code here
        int ans = 0;
        int prefix_sum = 0;
        int n = arr.size();
        unordered_map<int,int> map; //To store the prefix_sum ...
        //This prefix sum will be our (prefix_sum - k)..
        map[0]=1;//Initially prefix_sum = 0;
        
        for(int i=0;i<n;i++){
            prefix_sum +=arr[i];
            int x = prefix_sum - k;
            
            if(map.find(x) != map.end()){
                ans += map[x];//(prefix_sum - k) occurences...
                map[prefix_sum]++; // Add the prefix sum to the map for further checking...
            }else{
                map[prefix_sum]++;
            }
        }
        
        return ans; //returning no of subarrays exists..
    }
};