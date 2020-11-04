/* Approach : 1 Brute Force

 Time Complexity : O(n*n)
 Space Complexity : O(1)

*/

class Solution {
  public:
    int findMaxLen(string s) {
    int count = 0;
    int max = 0;
    for (int i = 0; i < s.length(); i++) {
        count = 0;
        for (int j = i; j < s.length(); j++) {
            if (s[j] == '(') {
                count++;
            } else {
                count--;
            }
            if (count < 0) {
                break;

            }
            if (count == 0) {
                if (j - i + 1 > max) {
                    max = j - i + 1;
                }
            }
        }
    }
    return max;        
    }
};

/*Approach 2 : Using Stack
               In this approach we initialize stack by pushing -1. -1 acts as a base for the next valid
	       substring and then we store indexes of the opening braces encountered in the stack. As
	       soon as we encounter a closing bracket we pop the index stored at the top and if while
	       popping, the stack is not empty that means there exists a boundary or base index then we can 
	       calculate the length by subtracting current index with the stack's top.
 Time Complexity : O(n)
 Space Complexity : O(n)
 
*/

class Solution {
  public:
    int findMaxLen(string s) {
        stack<int> st;
        int res = 0;
        st.push(-1);
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                st.push(i);
            else{
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                    res = max(res, i-st.top());
            }
        }
        return res;       
    }
};

/* Approach 3 : Without extra space.

   Time Complexity : O(n)
   Space Complexity : O(1)

*/
class Solution {
  public:
    int findMaxLen(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') 
                left++;
            else 
                right++;
            
            if (left == right)
                maxlength = max(maxlength, 2 * right);
            else if (right >= left)
                left = right = 0;
            
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') 
                left++;
            else
                right++;
            
            if (left == right)
                maxlength = max(maxlength, 2 * left);
            else if (left >= right)
                left = right = 0;
        }
        return maxlength;     
    }
};
