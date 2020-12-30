#include <bits/stdc++.h>
using namespace std;

//kadane's Algorithm
int largest_sum_subarray (int arr[], int n) {
	int sum = 0;
	int best = INT_MIN;
	
	for (int i = 0; i < n; i++) {
		sum = max (arr[i], sum + arr[i]);
		best = max (best, sum);
	}
	
	return best;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int test_cases;
	cin >> test_cases;
	
	while (test_cases--) {
		int n;
		cin >> n;
		
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		int max_sum = largest_sum_subarray (arr, n);
		
		cout << max_sum << "\n";
	}
	
	return 0;
}
