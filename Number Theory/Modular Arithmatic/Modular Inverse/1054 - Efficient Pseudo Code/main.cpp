#include <bits/stdc++.h>

#define pf                  printf
#define sf(a)               scanf("%d",&a)
#define sfl(a)              scanf("%lld",&a)
#define sff(a,b)            scanf("%d %d",&a,&b)
#define sffl(a,b)           scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)         scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)        scanf("%lld %lld %lld",&a,&b,&c)
#define sffff(a,b,c,d)      scanf("%d %d %d %d",&a,&b,&c,&d)
#define sffffl(a,b,c,d)     scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define sfffff(a,b,c,d,e)   scanf("%d %d %d %d %d",&a,&b,&c,&d,&e)
#define sfffffl(a,b,c,d,e)  scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e)
#define ms(a,b)             memset(a,b,sizeof(a))
#define pb(a)               push_back(a)
#define db                  double
#define ft                  float
#define ll                  long long
#define ull                 unsigned long long
#define ff                  first
#define ss                  second
#define sz(x)               x.size()
#define qu                  queue
#define pqu                 priority_queue
#define vc                  vector
#define vi                  vector<int>
#define vll                 vector<long long>
#define pii                 pair<int,int>
#define pis                 pair<int,string>
#define psi                 pair<string,int>
#define all(x)              x.begin(),x.end()
#define CIN                 ios_base::sync_with_stdio(0); cin.tie(0)
#define max3(a, b, c)       max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c)       min(a, b) < min(b, c) ? min(a, b) : min(b, c)
#define loop0(i,n)          for(int i=0;i<n;i++)
#define loop1(i,n)          for(int i=1;i<=n;i++)
#define loopab(a,b)         for(int i=a;i<=b;i++)
#define stlloop(x)          for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define gcd(a, b)           __gcd(a, b)
#define lcm(a, b)           ((a)*((b)/gcd(a,b)))
#define case1(z)            cout<<"Case "<<z<<": "
#define case2(z)            printf("Case %d: ",z)
#define PI                  3.14159265358979323846264338328
#define valid(tx,ty)        tx>=0 && tx<r && ty>=0 && ty<c
#define intlim              2147483648
#define MAX                 100000
#define inf                 10000000

/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

using namespace std;

bool p[MAX+2];
vector<int>prime;

void sieve()
{
    p[0]=p[1]=1;
    int root=sqrt(MAX);
    for(int i=2; i<=root; i++)
    {
        if(p[i]==0)
        {
            //prime.push_back(i);
            for(int j=i*i; j<=MAX; j+=i)
            {
                p[j]=1;
                if(i%2==1) j+=i;
            }
        }
    }
    for(int i=2; i<=MAX; i++)
    {
        if(p[i]==0) prime.push_back(i);
    }
}

ll m=1000000007;

ll big_mod(ll n,ll p)
{
    if(p==0) return 1;
    if(p%2==0)
    {
        ll x=big_mod(n,p/2)%m;
        return (x*x)%m;
    }
    else return ((n%m)*(big_mod(n,p-1)%m))%m;
}

ll mod_inverse(ll n)
{
    return big_mod(n,m-2);
}

ll sum_of_divisor(ll n,ll p)
{
    ll sum=1,c,s;
    ll k=n;
    ll root=sqrt(n);
    for(ll i=0; prime[i]<=root; i++)
    {
        if(k%prime[i]==0)
        {
            c=0;
            while(k%prime[i]==0)
            {
                k/=prime[i];
                c++;
            }
            root=sqrt(k);
            ll x=big_mod(prime[i],(c*p)+1);
            ll y=mod_inverse(prime[i]-1);
            s=(((x-1+m)%m)*((y+m)%m))%m; // here we add m to get the exact result because x or y can be of negative value since in the problem, n & m are signed integer
            sum=((sum%m)*(s%m))%m;
        }
    }
    if(k>1)
    {
        ll x=big_mod(k,p+1);
        ll y=mod_inverse(k-1);
        s=(((x-1+m)%m)*((y+m)%m))%m;
        sum=((sum%m)*(s%m))%m;
    }
    return sum;
}

int main()
{
    //CIN;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t;
    sf(t);
    sieve();
    loop1(z,t)
    {
        ll n,p;
        sffl(n,p);
        case2(z);
        pf("%lld\n",sum_of_divisor(n,p));
    }
    return 0;
}
