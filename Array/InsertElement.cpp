// Program to insert at specified position in array....
#include<iostream>
using namespace std;

void insert(int a[], int s, int n, int p){
    if(p<0)
        cout<<"wrong position";
    else{
       s++;
       for(int i=s-1; i>=p-1;i--){
           a[i+1] = a[i];
       }
       a[p-1] =n;
       if(p>s)
            cout<<"\nInsertion out of bound";
        cout<<"\nAfter insertion: ";
        for(int i=0;i<s;i++)
            cout<<a[i]<<" ";
    }
}

int main(){
    int arr[100], size, num, pos;
    cout<<"\nEnter the size of array: ";
    cin>>size;
    cout<<"\nEnter the elements: ";
    for(int i=0;i<size;i++)
        cin>>arr[i];
    cout<<"\nYour array is: ";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<"\nEnter the element you want to insert: ";
    cin>>num;
    cout<<"\nEnter the position: ";
    cin>>pos;
    insert(arr, size, num, pos);
    return 0;
}