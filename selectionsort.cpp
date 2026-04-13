#include<iostream>
using namespace std;
int main(){
   int n,temp,min;
   cout<<"Enter no of elements:";
   cin>>n;
   int a[n];
   cout<<"Enter the elements:";
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   for(int i=0;i<n-1;i++){
      min = i;
      for(int j=i+1;j<n;j++){
         if(a[j]<a[min]){
            min = j;
         }
      }
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
   }
   cout<<"Sorted array using delection sort :\n";
   for(int i=0;i<n;i++){
      cout<<a[i]<<" ";
   }
   return 0;
}
