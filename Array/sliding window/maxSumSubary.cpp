// maximun sum of subarray of size k
#include<iostream>
using namespace std;

int main()
{
    int arr[100], size, k = 3, i=0,j=0, sum=0, maxi=0;
    cout<<"\nEnter the size: ";
    cin>>size;
    cout<<"\nEnter the element: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    while(j<size){
        sum = sum+arr[j];
        if(j-i+1 < k)
            j++;
        else if(j-i+1 == k){
            maxi = max(maxi, sum);
            sum = sum - arr[i];
            i++;
            j++;
        }
    }
    cout<<"The max Sum is : "<<maxi;
    return 0;    
}