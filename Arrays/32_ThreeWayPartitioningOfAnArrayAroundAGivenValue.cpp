/*The function should return the modified array
as specified in the problem statement */

//Time Complexity : O(n)
//Space Complexity : O(1)

//Approach : Dutch National Flag Algorithm similar to paritition logic in Quicksort

vector<int> threeWayPartition(vector<int> A, int a, int b)
{
     int low = 0, mid = 0, high = A.size()-1;
     while(mid <= high){
         if(A[mid] < a)
             swap(A[low++], A[mid++]);
         else if(A[mid] > b)
             swap(A[mid], A[high--]);
         else
             mid++;
     }
     return A;
}

