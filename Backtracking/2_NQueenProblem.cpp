/* Approach : Backtracking - easiest approach you'll find.
              We start with (0,0)th cell. We place the queen and move to the next row since we
	      can't place the next queen in the same row, hence we jump to the next row. We keep
	      moving column wise and check if the position is safe for our queen(i.e no queens attack)
	      and then we jump to the next row. The process continues till we jump to a row that is
	      greater than the size of the grid, row >= n. We print the solution grid and return.

Time Complexity : O(2^n)
Space Complexity : O(2^n)
*/

#include<bits/stdc++.h>
using namespace std;

void printSol(vector<vector<int>> &mat, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool isSafe(vector<vector<int>> &mat, int x, int y, int n){
	for(int i = 0; i < x; i++){    //check if the column above has a Queen already placed.
		if(mat[i][y] == 1)
			return false;
	}

	int row = x;
	int col = y;
	while(row >= 0 && col >= 0){
		if(mat[row][col] == 1){  //check if their exists any Queen in the left diagonal
			return false;
		}
		row--;
		col--;
	}
	row = x; 
	col = y;
	while(row >=0 && col < n){          //check if their exists any Queen in the right diagonal
		if(mat[row][col] == 1){
			return false;
		}
		row--;
		col++;
	}
	return true;
}

bool nQueen(vector<vector<int>> &mat, int x, int n){
	if(x >= n){            //placed all the n queens
	        printSol(mat, n);	
		return true;
	}
	for(int col = 0; col < n; col++){
		if(isSafe(mat, x, col, n)){
			mat[x][col] = 1;
			nQueen(mat, x+1, n);  //printing all possible solutions
			mat[x][col] = 0; // backtracking
		}
        }
	return false;
}

int main(){
	int n;
	cout<<"Enter size"<<endl;
	cin>>n;
	vector<vector<int>> mat(n,vector<int>(n,0));
	nQueen(mat, 0, n);
        return 0;
}
		
        
