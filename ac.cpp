#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
   long int n ;
   cin >> n;
   long at[n], po[n];
   for(long int i=0;i<n;i++){
       cin>>at[i]>>po[i];
   }
   
   //final calculation 
   long int res = 0;
   for(long int i=0;i<n-1;i++){
       for(long int j=i+1;j<n;j++){
           long int distance = abs(po[i]-po[j]);           
           res += distance * max(at[i],at[j]);
       }
   }
   cout<<res<<endl;
    return 0;
}
