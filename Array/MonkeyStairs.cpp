/* Monkey stand on the stair and there is given number of array 
Find the minimun number of step that is positive after perform the adition and subtraction
so that the monkey is on anyone stairs...not on the ground

ex- suppose we choose stairs of 6 steps and array is jumps = [1,-4,-2,3]

 Stair              jumps[i]
 6                    1
 7                    -4
 3                    -2
 1                    3
 4

For starting stair =6, the stair number remains>=1 throughout the jumps. THis is the least
possible value of startingStair for the condition to be true.
Therefore the answer is 6
*/

#include<iostream>
using namespace std;

int main()
{
    int n,i=0,jumps[100];
    cout<<"\nEnter the size of array: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"\nEnter the "<<i+1<<" element: ";
        cin>>jumps[i];
    }
    for(i=n-1;i>0;i--){
        if(jumps[i] <0){
            break;
        }
    }
    int sum = 0;
    for(int j=0;j<=i;j++){
        sum += jumps[j];
    }
    cout<<"Answer is: "<<abs(sum)+1;

}