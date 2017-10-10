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
#define MAX                 1000006
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

void sieve(int n)
{
    p[0]=p[1]=1;
    int root=sqrt(n);
    for(int i=2; i<=root; i++)
    {
        if(p[i]==0)
        {
            for(int j=i*i; j<n; j+=i)
            {
                p[j]=1;
                if(i%2==1) j+=i;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(p[i]==0) prime.push_back(i);
    }
}

ull div_count(ull n)
{
    ull divisor=1;
    ull root=sqrt(n);
    for(int i=0;prime[i]<=root;i++)
    {
        if(n%prime[i]==0)
        {
            ull c=1;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                c++;
            }
            root=sqrt(n); // It's an optimizng point, without it the code can get TLE
            divisor*=c;
        }
    }
    if(n>1)
    {
        divisor*=2;
    }
    return divisor-1;
}

int main()
{
    //CIN;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    sieve(MAX);
    int t;
    sf(t);
    loop1(z,t)
    {
        ull n;
        scanf("%llu",&n);
        case2(z);
        pf("%llu\n",div_count(n));
    }

    return 0;
}
