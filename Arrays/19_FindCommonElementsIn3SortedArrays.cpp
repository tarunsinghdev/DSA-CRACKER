//Time Complexity : O(n1 + n2+ n3)
//Space Complexity : O(n1 +n2+ n3)

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int> res;
            int i = 0, j = 0, p;
            while(i<n1 && j<n2){
                if(A[i] < B[j])
                    i++;
                else if(B[j] < A[i])
                    j++;
                else{
                   if(!res.empty() && p == A[i]){ 
                       i++;
                       j++;
                   }
                   else{
                        p = A[i];
                        res.push_back(A[i]);
                        i++;
                        j++;
                   }
                }
            }
            int x = res.size();
            vector<int> ans;
            i = 0, j = 0;
            int q;
            while(i<x && j<n3){
                if(res[i] < C[j])
                    i++;
                else if(C[j] < res[i])
                    j++;
                else{
                    if(!ans.empty() && q == res[i]){
                        i++;
                        j++;
                    }
                    else{
                        q = res[i];
                        ans.push_back(res[i]);
                        i++;
                        j++;
                    }
                }
            }
            return ans;
        }
         
};
