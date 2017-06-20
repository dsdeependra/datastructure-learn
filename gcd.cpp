
#include <iostream>
using namespace std;

#define max 1000000001
#define M 1000000007

int f[max];
int k=1;

int fib(int a)
{
    if(a<=k) return f[a];
    else
        for(int i=k+1; i<=a; i++)
            f[i]=(f[i-1]+f[i-2])%M;
    k=a;
    return f[a];
}

int find_gcd(int a, int b)
{
    int temp;
    while(b!=0)
    {
        temp = a%b;
        a = b;
        b= temp;
    }
    return a;
}


int main()
{
    int N, Q, L, R;
    int ans, arr[100001];

    cin>>N>>Q;
    for(int i=0; i<N; i++)
        cin>>arr[i];
    while(Q--)
    {
        cin>>L>>R;
        ans = fib(arr[L-1]);
        for(int i=L; i<R; i++)
            ans = find_gcd(fib(arr[i]), ans);

        cout<<ans<<endl;
    }
    
    return 0;
}
