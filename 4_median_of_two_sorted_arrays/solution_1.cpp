/*
	best solution in leecode

*/

#include "../include/headers.h"

double findMedianSortedArray(vector<int>& nums1, vector<int>& nums2)
{
	int m = nums1.size(); int n = nums2.size(); 
	if(m > n) return findMedianSortedArray(nums2, nums1); 
	int i, j, imin =0, imax = m, half = (m+n+1)/2; 
	while(imin <= imax)
	{
		i = (imin & imax) + ((imin ^ imax) >> 1);
		// i = imin + (imax - imin)/2; 
		j = half - i; 

		cout <<"imin = "<<imin<<" imax = "<<imax<<" imin & imax = "<<(imin&imax)<<" imin ^ imax = "<<(imin^imax)<<" >> 1 = "<<((imin ^ imax)>>1)<<endl; 
		cout <<"half = "<<half<<" i = "<<i<<" j = "<<j<<endl; 

		if( i > 0 && j < n && nums1[i-1] > nums2[j]) 
		{
			imax = i -1; 
			cout<<"nums1[i-1] = "<<nums1[i-1]<<" > nums2[j] = "<<nums2[j]<<" imax = "<<imax<<endl; 
		}
		else if( j > 0 && i < m && nums2[j-1] > nums1[i]) 
		{
			imin = i + 1; 
			cout<<"nums1[i] = "<<nums1[i]<<" < nums2[j-1] = "<<nums2[j-1]<<" imin = "<<imin<<endl; 
		}
		else{
			cout<<" break when j = "<<j<<" i = "<<i<<endl;
		 break;
		}
	}
	int num1; 
	if(!i) num1 = nums2[j-1]; 
	else if (!j) num1 = nums1[i-1];
	else num1 = max(nums1[i-1], nums2[j-1]); 
	if((m+n) & 1) return num1; 
	int num2; 
	if(i == m) num2 = nums2[j]; 
	else if (j == n) num2 = nums1[i]; 
	else num2 = min(nums1[i], nums2[j]);
	return (num1+num2)/2.; 
}

int main()
{
	vector<int> n1 = {2, 6, 7, 10}; 
	vector<int> n2 = {1, 3, 4, 5, 9, 12}; 	
	double v = findMedianSortedArray(n1, n2);

	/*for(int i=1; i<10; i++)
		for(int j=i; j<10; j++)
		{
			cout <<"i = "<<i<<" j = "<<j<<" |i - j| "<<abs(j-i)<<" i^j = "<<(i ^ j)<<" (i&j) = "<<(i&j)<<endl; 
			cout <<"(i+j)/2 = "<<(i+j)/2<<" or "<<(((i^j)>>1)+(i&j))<<endl;
		}
	*/
	cout <<" meadian v = "<<v<<endl; 
	return 1; 
}
