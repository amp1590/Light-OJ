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
#define MAX                 2000
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

vector<int> v1,v2;

void generating_divisor(int n, int L)
{
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            if(n/i==i && i>L ) v1.pb(i);
            else
            {
                if(i>L) v1.pb(i);
                if(n/i>L) v2.pb(n/i);
            }
        }
    }
}

int main()
{
    //CIN;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t;
    sf(t);
    loop1(z,t)
    {
        int P,L;
        scanf("%d %d",&P,&L);
        int n=P-L;
        generating_divisor(n,L);
        case2(z);
        //if(P==0 && L==0) pf("1"); // eta Udebug er invalid input, eta dileo AC , na dileo AC,but eta valid input na
        if(sz(v1)==0 && sz(v2)==0) pf("impossible");
        else
        {

            if(sz(v1)>0)
            {
                pf("%d",v1[0]);
                for(int i=1; i<sz(v1); i++) pf(" %d",v1[i]);
            }
            if(sz(v2)>0)
            {
                if(sz(v1)>0)
                {
                    for(int i=sz(v2)-1; i>=0; i--) pf(" %d",v2[i]);
                }
                else
                {
                    pf("%d",v2[sz(v2)-1]);
                    for(int i=sz(v2)-2; i>=0; i--) pf(" %d",v2[i]);
                }
            }
        }
        pf("\n");
        v1.clear();
        v2.clear();
    }
    return 0;
}
