#include<iostream>
using namespace std;

//Function to take input elements in array
void Input(int n, int A[])
{
    int i;
    cout<<"\n";
    for(i=0;i<n;i++)
      {
          cout<<i+1<<"th : ";
          cin>>A[i];
      }
}

//Function to display the array
void Display(int n, int A[])
{
    cout<<"[ ";
    for(int i =0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<" ]";
}

//Function to search the element
int linear_search(int n, int A[], int ele)
{
    int i;
    for( i=0;i<n;i++)
    {
        if(A[i] == ele)
        {
            cout<<"Element is found at "<<i+1<<"th position";
            break;
        }
    }
    if(i == n)
    {
        cout<<"OOPS! Element not found";
    }
}

//Main Function
int main()
{
    int n,Arr[100], element;
    cout<<"Enter the Size of array: ";
    cin>>n;
    cout<<"\nInput the elements : ";
    Input(n, Arr);
    cout<<"\nYour Array is: ";
    Display(n, Arr);
    cout<<"\nEnter element you want to search: ";
    cin>>element;
    linear_search(n,Arr,element);
    return 0;
}

