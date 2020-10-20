class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	     long long ans = arr[0];
	     long long minVal = (long long)arr[0], maxVal = (long long)arr[0];
	     for(int i = 1; i < n; i++){
	          if(arr[i] < 0)
	             swap(minVal, maxVal);
	          minVal = min((long long)arr[i], (long long)arr[i]*minVal);
	          maxVal = max((long long)arr[i], (long long)arr[i]*maxVal);
	          
	          ans = max(ans, maxVal);
	     }
	     return ans;
	}
};
