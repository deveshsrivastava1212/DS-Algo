#include<iostream>
#include<vector>
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

//Function to perform the left rotation
int left_rotate(int n, int A[], int d)
{
    int A2[100],i;
    for( i=0;i<n;i++)
    {
        if ((i+d)>n-1)
        {
            A2[i]= A[i+d-n];
            cout<< A2[i]<<" ";
        }
        else
        {
            A2[i] = A[i+d];
            cout<< A2[i]<<" ";
        }
    }

}

//Main Function
int main()
{
    int n,Arr[100], d;
    cout<<"Enter the Size of array: ";
    cin>>n;
    cout<<"\nInput the elements : ";
    Input(n, Arr);
    cout<<"\nYour Array is: ";
    Display(n, Arr);
    cout<<"\nEnter the distance from which you want to do left shifting: ";
    cin>>d;
    left_rotate(n,Arr,d);
    //Display(n,Arr);
    return 0;
}
