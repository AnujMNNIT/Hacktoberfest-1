#include<bits/stdc++.h>
using namespace std;
#include <stdio.h> 

void multiply(long long  int F[2][2], long long int M[2][2]); 

void power(long long int F[2][2],long long int n); 
int fib(long long int n) 
{ 
long long int F[2][2] = {{1,1},{1,0}}; 
if (n == 0) 
	return 0; 
power(F, n-1); 
return F[0][0]; 
} 

void power(long long int F[2][2], long long int n) 
{ 
if( n == 0 || n == 1) 
	return; 
long long int M[2][2] = {{1,1},{1,0}}; 
power(F, n/2); 
multiply(F, F); 
if (n%2 != 0) 
	multiply(F, M); 
} 

void multiply(long long int F[2][2], long long int M[2][2]) 
{ 
long long int x = F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
long long int y = F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
long long int z = F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
long long int w = F[1][0]*M[0][1] + F[1][1]*M[1][1]; 

F[0][0] = x%10; 
F[0][1] = y%10; 
F[1][0] = z%10; 
F[1][1] = w%10; 
} 

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long p=n,m=1;
        while(p>1)
        {
            p/=2;
            m*=2;
        }
        
        cout<<fib(m-1)<<endl;
    }
    
	return 0;
}
