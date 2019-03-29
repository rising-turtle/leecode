class Solution {
public:
    
    // int 10 
    string convert(string s, int numRows) 
    {
        if(numRows == 1)
            return s; 
        
        int loop_num = 2*numRows - 2;      
        vector<int> row_map(numRows - 2); 
        for(int i=0; i<row_map.size(); i++)
        {
            row_map[i] = loop_num - 2*(i+1); 
        }
        
        string ret = s;
        int N = s.size(); 
        int j = 0;
        // first row
        for(int i=0; i<N; i+=loop_num)
        {
            ret[j++] = s[i]; 
        }
        // second row to [last-1] row
        for(int i=1; i<numRows-1; i++)
        {
            for(int k = i; k < N; k+=loop_num)
            {
                ret[j++] = s[k]; 
                int l = k+ row_map[i-1]; 
                if(l<N) ret[j++] = s[l];
            }
        }
        
        // last row
        for(int i=numRows-1; i<N; i+=loop_num)
        {
            ret[j++] = s[i]; 
        } 
       
        return ret; 
    }
};


// 0   8   G
// 1  79  F
// 2 6 A E
// 35  BD
// 4   C
