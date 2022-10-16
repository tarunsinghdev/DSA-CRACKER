// Time Complexity: O(n^2logn).
// Auxiliary Space: O(n^2)

// Approach: Create a temp[] array of size n^2. Starting with the first row one by one copy the elements of the given matrix into temp[]. Sort temp[].
//           Now one by one copy the elements of temp[] back to the given matrix.
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
{
    vector<int> ans;
    // stored element in 1D array
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans.push_back(Mat[i][j]);
        }
    }
    // sort the element in 1D array
    sort(ans.begin(), ans.end());
    // stored element in 2D array
    for (int i = 0; i < N * N; i++)
    {
        Mat[i / N][i % N] = ans[i];
    }

    return Mat;
}