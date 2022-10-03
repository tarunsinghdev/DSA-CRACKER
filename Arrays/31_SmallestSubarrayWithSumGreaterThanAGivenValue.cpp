class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int minLen = numeric_limits<int>::max();
        for (int i = 0; i < n && minLen > 1; i++){
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum > x){
                    minLen = min(minLen, j - i + 1);
                    break;  
                }
            }
        }
        
        return minLen == numeric_limits<int>::max() ? 0 : minLen;
    }
};
