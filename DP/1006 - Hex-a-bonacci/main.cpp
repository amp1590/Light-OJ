#include <bits/stdc++.h>

#define sf              scanf
#define pf              printf
#define ms(a,b)         memset(a,b,sizeof(a))
#define pb(a)           push_back(a)
#define db              double
#define ft              float
#define ll              long long
#define ull             unsigned long long
#define ff              first
#define ss              second
#define sz(x)           x.size()
#define qu              queue
#define pqu             priority_queue
#define vc              vector
#define vi              vector<int>
#define vll             vector<long long>
#define pii             pair<int,int>
#define pis             pair<int,string>
#define psi             pair<string,int>
#define all(x)          x.begin(),x.end()
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define loop0(i,n)      for(int i=0;i<n;i++)
#define loop1(i,n)      for(int i=1;i<=n;i++)
#define stlloop(x)     for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define gcd(a, b)       __gcd(a, b)
#define lcm(a, b)       ((a)*((b)/gcd(a,b)))
#define case(z,x)       cout<<"Case "<<i<<": "<<x<<endl
#define case(z)         cout<<"Case "<<z<<": "
#define PI              3.14159265358979323846264338328
#define valid(tx,ty)    tx>=0 && tx<r && ty>=0 && ty<c
#define MAX             2000
#define inf             10000000

/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

using namespace std;

ll a, b, c, d, e, f;
ll dp[10004];

ll fn( ll n )
{
    if( n == 0 ) return a% 10000007;
    if( n == 1 ) return b% 10000007;
    if( n == 2 ) return c% 10000007;
    if( n == 3 ) return d% 10000007;
    if( n == 4 ) return e% 10000007;
    if( n == 5 ) return f% 10000007;
    if(dp[n]!=-1) return dp[n];
    else
    {
        dp[n]= ((fn(n-1)% 10000007) + (fn(n-2)% 10000007) + (fn(n-3)% 10000007) + (fn(n-4)% 10000007) + (fn(n-5)% 10000007) + (fn(n-6)% 10000007)) % 10000007;
        return dp[n];
    }
}

int main()
{
    CIN;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ll n,t;
    cin>>t;
    loop1(i,t)
    {
        ms(dp,-1);
        cin>>a>>b>>c>>d>>e>>f>>n;
        cout<<"Case "<<i<<": "<<(fn(n) % 10000007)<<endl;
    }
    return 0;
}
