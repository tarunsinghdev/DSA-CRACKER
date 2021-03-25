/*  refer : https://www.youtube.com/watch?v=4BBB0mvvbGA&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=43

Approach : Backtracking
   
    We pass x and y which is the position of the rat to the ratinMaze() function. The function then
    check for every path as in recursion but it "backtracks" as soon as it fails to find a path. 

*/

#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &mat, int x, int y, int n){
	if(x < n && y < n && mat[x][y] == 1)
		return true;
	return false;	
}

bool ratinMaze(vector<vector<int>>& mat, int x, int y, vector<vector<int>> &solMat, int n){
        if(x == n-1 && y == n-1){
		solMat[x][y] = 1;
		return true;
	}
	if(isSafe(mat, x, y, n)){
		solMat[x][y] = 1;
		if(ratinMaze(mat, x+1, y, solMat, n)){
			return true;
		}
		if(ratinMaze(mat, x, y+1, solMat, n)){
			return true;
		}
		solMat[x][y] = 0; // backtracking
		return false;
	}
	return false;

}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> mat(n, vector<int>(n,0));
	vector<vector<int>> solMat(n, vector<int>(n,0));

        for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>mat[i][j];
		}
	}

	if(ratinMaze(mat, 0, 0, solMat, n)){
		cout<<"Path available"<<endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout<<solMat[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else{
		cout<<"Path doesn't exist"<<endl;
	}
        return 0;
}
                        
// Input : 1 0 1 0 1
//         1 1 1 1 1
//         0 1 0 1 0
//         1 0 0 1 1
//         1 1 1 0 1
