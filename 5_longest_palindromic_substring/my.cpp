class Solution {
public:
    string longestPalindrome(string s) 
    {
        int N = s.size(); 
        if(N == 0) return "";
        bool b[N][N]; 
        for(int i=0; i<N; i++)
            b[i][i] = true; 
        
        int si = 0; 
        int len = 1; 
        
        for(int i=N-2; i>=0; --i)
            for(int j=i+1; j<N; j++)
            {
                if(i+1 <= j-1)
                    b[i][j] = (b[i+1][j-1] && s[i] == s[j]);
                else
                    b[i][j] = (s[i] == s[j]); 
                if(b[i][j])
                {
                    if(len < j-i+1)
                    {
                        len = j-i+1; 
                        si = i; 
                    }
                }
            }
        
        
        return s.substr(si, len); 
    }
};
