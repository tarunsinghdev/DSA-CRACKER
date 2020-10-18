class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int x = (k-arr[i]);
            if(mp[x] > 0){
                cnt += mp[k-arr[i]];
                
                if(k-arr[i] == arr[i])      //Making sure that the counter counts when two different pairs are found not with itself
                   cnt--;                   //i.e , consider pairs other than itself
               
            }
        }
        return cnt/2;
    }
};
