class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int flags[256]; 
        for (int i=0; i<256; i++)
        {
            flags[i] = -1;
        } 
        int ret = 0; 
        int len = 0;
        int conflict = -1; 
        
        for(int i=0; i<s.size(); i++)
        {
            if(flags[s[i]] != -1) // already seen before  
            {
                if(flags[s[i]] < conflict) 
                {
                    ++len; 
                }else
                {
                    conflict = flags[s[i]]; 
                    len = i - conflict; 
                }
            }else{
                ++len;
            }
            flags[s[i]] = i;
            ret = len > ret ? len : ret; 
            
           //std::cout <<i<<" = "<< s[i] <<" len = "<<len<<" ret ="<<ret<<std::endl;
        }
        
        return ret; 
    }
};
