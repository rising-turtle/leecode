class Solution {
public:
    
    // find loc that key <= a[loc] and, in range a[s, e)    
    int halfLoc(int key, vector<int>& a, int s, int e)
    {
        int is = s; 
        int ie = e; 
        if(key > a[e-1])
            return -1; 
        while(is < ie)
        {
            // divide into [s, half) and [half, e)
            int half = is + (ie-is)/2; 
            int half_v = a[half];
            while(half > is && half_v == a[half-1]) --half;
            
            if(key == half_v) return half; 
            
            if(key < half_v)  // left part 
            {
                ie = half; 
            }else // right part 
            {
                while(half < ie-1 && half_v == a[half+1]) ++half;
                is = half + 1;
            }
        }
        // if(a[is] < key)
            // std::cout<<" something not right since a[is] = "<<a[is]<<" < key = "<<key<<" is = "<<is<<std::endl; 
        return is; 
    }
    
    double findLessN(vector<int>& a1, int s1, int e1, vector<int>& a2, int s2, int e2, int M, int odd)
    {
        int N = M; 
        // std::cout << "N = "<<N<<" s1 = "<<s1<<" e1 = "<<e1<<" s2 = "<<s2<<" e2 = "<<e2<<std::endl;
        while(N > 0)
        {
            if(s1 >= e1)
            {
                if(e2 - s2 < N)
                { 
                    // std::cout<<"e2 = "<<e2<<" s2 = "<<s2<<" < N = "<<N<<std::endl; 
                    return -1; 
                }
                if(odd)
                {
                    // std::cout<<"s2 = "<<s2<<" N = "<<N<<std::endl;
                    // return a2[s2+N-1]; 
                    return a2[s2+N]; 
                }
                else{
                    int pre_vi=-1; 
                    // if(s2+N >=2)
                       // pre_vi = a2[s2+N-2]; 
                    if(s2+N >=1)
                        pre_vi = a2[s2+N-1]; 
                    if(e1>0)
                        pre_vi = pre_vi < a1[e1-1] ? a1[e1-1] : pre_vi; 
                    
                    // return (a2[s2+N-1]+pre_vi)/2.0;
                    return (a2[s2+N]+pre_vi)/2.0;
                }
            }
            if(s2 >= e2)
            {
                if(e1 - s1 < N)
                {
                    // std::cout<<"e1 = "<<e1<<" s1 = "<<s1<<" < N = "<<N<<std::endl; 
                    return -1;
                }
                if(odd)
                {
                    // std::cout<<"N = "<<N<<" s1 = "<<s1<<std::endl;
                    // return a1[s1+N-1]; 
                    return a1[s1+N];
                }
                else{
                    int pre_vi=-1; 
                    // if(s1+N >=2)
                        // pre_vi = a1[s1+N-2]; 
                    if(s1+N >=1)
                        pre_vi = a1[s1+N-1]; 
                    if(e2>0)
                        pre_vi = pre_vi < a2[e2-1] ? a2[e2-1] : pre_vi; 
                    // std::cout<<"N = "<<N<<" s1 = "<<s1<<" e2 = "<<e2<<" pre_vi = "<<pre_vi<<std::endl;
                    // return (a1[s1+N-1]+pre_vi)/2.0;
                    return (a1[s1+N]+pre_vi)/2.0;
                }
            } 
            
            int i = s1 + (e1-s1)/2; 
            int vi = a1[i]; 
        
            int j = halfLoc(vi, a2, s2, e2); 
            int left_vi = i-s1; 
            // vi > all vj
            if(j==-1)
            {
                left_vi += e2 - s2; 
            }else
            {
                left_vi += (j-s2);    
            }
            
            if(left_vi == N)
            { 
                int pre_vi = -1; 
                if(odd)
                {
                    // std::cout<<"left_vi = "<<left_vi<<" N = "<<N<<" s1 = "<<s1<<" e1 = "<<e1<<" s2 = "<<s2<<" e2 = "<<e2<<std::endl;
                    return vi;
                }
                else // even find previous 
                {
                    if(i>0)
                        pre_vi = a1[i-1]; 
                    if(j==-1)
                        pre_vi = pre_vi < a2[e2-1]? a2[e2-1] : pre_vi; 
                    else if(j>0)
                        pre_vi = pre_vi < a2[j-1]?a2[j-1] : pre_vi; 
                    // std::cout << "i = "<< i<<" j = "<<j<< " vi = "<<vi<<" pre_vi = "<<pre_vi<<" N = "<<N<<" s1 = "<<s1<<" e1 = "<<e1<<" s2 = "<<s2<<" e2 = "<<e2<<std::endl;
                    return (vi+pre_vi)/2.0;
                }
            }
            
            if(left_vi == 0) // move next 
            {
                if(N == 1) // next is the element to be found 
                {
                    int nxt_vi = 10000000; 
                    if(i+1 < a1.size())
                        nxt_vi = a1[i+1]; 
                    if(j == -1)
                        nxt_vi = a2[e2-1] < nxt_vi ? a2[e2-1] : nxt_vi;
                    else if(j < a2.size())
                        nxt_vi = a2[j] < nxt_vi ? a2[j] : nxt_vi; 
                     // std::cout << "i = "<< i<<" j = "<<j<< " vi = "<<vi<<" left_vi = "<<left_vi<<" N = "<<N<<" s1 = "<<s1<<" e1 = "<<e1<<" s2 = "<<s2<<" e2 = "<<e2<<" nxt_vi = "<<nxt_vi<<std::endl;
                    if(odd) 
                        return nxt_vi; 
                    else
                    {   
                        return (vi+nxt_vi)/2.;
                    }
                }
                left_vi +=1; 
                i+=1;
            }
            
            if(left_vi < N)
            {
                N = N - left_vi; 
                s1 = i;
                
                s2 = j==-1? e2:j;
            }else if(left_vi > N)
            {
                e1 = i; 
                e2 = j == -1?e2:j;
            }
            
           // std::cout << "i = "<< i<<" j = "<<j<< " vi = "<<vi<<" left_vi = "<<left_vi<<" N = "<<N<<" s1 = "<<s1<<" e1 = "<<e1<<" s2 = "<<s2<<" e2 = "<<e2<<std::endl;
        }
        
        // should never arrive here 
        return -1; 
    }

    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() < nums2.size())  nums1.swap(nums2);        
        int M = nums1.size(); int N = nums2.size(); 

        int odd = (M+N)%2; 
        int num = (M+N)/2;
        if (N==0)
        {
            if(odd) return nums1[M/2];
            else{
                return (nums1[M/2]+nums1[M/2-1])/2.;
            }
        }
   
        
        double v = findLessN(nums1, 0, nums1.size(), nums2, 0, nums2.size(), num , odd); 
      
        return v; 
    }
};
