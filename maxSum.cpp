#include<iostream>
using namespace std;

int maxSum(int A[], int n){
    int curSum=0;
    int maxsum =0;
    for(int i=0;i<n;i++)
    {
        curSum = curSum + A[i];
        if(curSum>maxsum)
            maxsum = curSum;
        if(curSum<0)
            curSum = 0;
    }
    return maxsum;
}

int main (){
    int A[100], n=6;
    cout<<"\nEnter the values: ";
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int res = maxSum(A,n);
    cout<<"Maximum sum is: "<<res;
    return 0;
}