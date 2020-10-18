#include<bits/stdc++.h>
using namespace std;

/*   Approach 1 : If ordering was not important we can simply separte the positive values to one side and negative value to the other and then rearrange them alternatively
int main(){
	int n;
	cin>>n;
	vector<int >v(n);
	for(auto &it : v) cin>>it;
	int k = n-1, j = 0;
	while(j < k){                     //Arranging all the negative values to the end of the array
		while(j < n && v[j] > 0 )
			j++;
		while(k >j && v[j] < 0)
			k--;
		if(j < k)
		    swap(v[j], v[k]);
	}
        if(j == n-1){
		for(auto i : v)
			cout<<i<<" ";
	}
	else{
		int x = 0; 
		while(j < n && x<n){          //Rearranging the elements alternatively
			swap(v[x], v[j]);
			j+=1;
			x+=2;
		}
		for(auto i : v)
			cout<<i<<" ";
	}
	return 0;
}
*/


/*Approach 2 : Using partition logic of quicksort. Still we assume that ordering is not important.


int partition(vector<int> &v, int n){               //This forces all the negative elements of the array to the beginning
	int pivot = 0;
	int pIndex = 0;
	for(int i = 0; i<n; i++){
		if(v[i] < pivot){
			swap(v[i], v[pIndex]);
			pIndex++;
		}
	}
	return pIndex;
}

int main(){
        int n;
	cin>>n;
	vector<int >v(n);
	for(auto &it : v) cin>>it;
	int p = partition(v, n);
	int i = 0;
        while(p < n && v[i]<0){
		swap(v[i], v[p]);
		i+=2;
		p+=1;
	}
	for(auto i : v)
		cout<<i<<" ";
}*/

/* Approach 3 : We maintain ordering as well
   As per the question an important think to not is that a valid answer can begin from a positive no. or a negative no. Here we consider our shall
   begin with a positive no. that means we have our positive no. at even indices and odd no. at odd indices in our final answer apart from the leftover 
   at the end.

   Steps to be followed:  First, find the first element which is outofplace that means either positive no. is at odd index or negative no. at even index.
   Next, following this element find the element which is of opposite sign as this.
   Then, we right rotate the array. If we fail to find the next opposite element then we break out of the loop as only elements we are left with are the
   extra elements at the end which can be either positive or negative depending on the element which was the reason we break out from the loop.
   
   Time Complexity : O(n^2)
   Space Complexity : O(1)
*/

bool isAtRightPosition(vector<int> v,int index){
	if(index%2 == 0){
		if(v[index] > 0)
			return true;
		else
			return false;
	}
	else{
		if(v[index] < 0)
			return true;
		else
			return false;
	}
}

int getNextOpposite(vector<int > v, int index){
         for(int i = index+1; i < (int)v.size(); i++){
		 if(v[index]*v[i] < 0)
			 return i;
	 }
	 return -1;
}
			 
void rotateSubarrayRightbyone(vector<int>&v, int start, int end){
	int last = v[end];
	for(int i = end; i>start; i--)
		v[i]=v[i-1];
	v[start] = last;
}

int main(){
      int n;
	cin>>n;
	vector<int >v(n);
	for(auto &it : v) cin>>it;
        for(int i = 0; i < n; i++){
		if(isAtRightPosition(v, i) == false){
			int nextOppositeIndex = getNextOpposite(v, i);
			if(nextOppositeIndex != -1){
				rotateSubarrayRightbyone(v, i, nextOppositeIndex);
			}
			else
				break;
		}
	}
	for(auto i : v)
		cout<<i<<" ";
	return 0;
}



