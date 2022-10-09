// Question link : https://leetcode.com/problems/palindrome-partitioning/

//your code goes here

class Solution {
public:
    vector<vector<string>> vect;
    bool checkpalindrome(string s,int i, int j) {
        while(i<=j) {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string s,int i,vector<string> v1) {
        if(i==s.length()) {
            vect.push_back(v1);
        }
        for(int k=i;k<s.length();k++) {
            if(checkpalindrome(s,i,k)) {
                v1.push_back(s.substr(i,k-i+1));
                solve(s,k+1,v1);
                v1.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v1;
        solve(s,0,v1);
        return vect;
    }
};
