#include<bits/stdc++.h>

using namespace std;

int binarysearch(int a[],int n, int k)
{
	int s = 0;
	int e = n-1;
	
	sort(a,a+n); // { 1,3,5,7,8,12,13,14,15,16,19,20,21,29,39,42,65}
	
	while(s<=e)
	{
		int mid = (s+e)/2;
		
		if(a[mid]==k)
			return mid;
			
		else if(a[mid] > k)
		{
			e = mid-1;
		}
		else //a[mid] <k
		{
			s = mid+1;
		}
	}
	return -1;
}

int main() {
	// Your code goes here;
	int A[]={1,3,7,5,29,13,42,65,8,39,20,14,15,16,12,19,21};
	int n = sizeof(A)/sizeof(A[0]);
	int k = 39;
	int index = binarysearch(A,n,k);
	cout<<"The element "<<k<<" is present at index: "<<index<<endl;
	return 0;
}