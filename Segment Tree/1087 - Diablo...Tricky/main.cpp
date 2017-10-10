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
#define sfc(a)              scanf("%c",&a)
#define ms(a,b)             memset(a,b,sizeof(a))
#define pb(a)               push_back(a)
#define pbp(a,b)            push_back({a,b})
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
#define for0(i,n)          for(int i=0;i<n;i++)
#define for1(i,n)          for(int i=1;i<=n;i++)
#define forcmp(i,n)        for(int i=1;i<n;i++)
#define forrev(i,n)        for(int i=n-1; i>=0; i--)
#define forab(i,a,b)       for(int i=a;i<=b;i++)
#define forba(i,b,a)       for(int i=b;i>=a;i--)
#define stlloop(x)          for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define gcd(a, b)           __gcd(a, b)
#define lcm(a, b)           ((a)*((b)/gcd(a,b)))
#define case1(z)            cout<<"Case "<<z<<": "
#define case2(z)            printf("Case %d:\n",z)
#define PI                  acos(-1) //3.14159265358979323846264338328
#define valid(tx,ty)        tx>=0 && tx<row && ty>=0 && ty<col
#define intlim              2147483648
#define MAX                 1000000
#define inf                 100000000
#define mx                  150005

/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

using namespace std;

struct data
{
    ll sum,val,pos;
};

char ch[5];
ll limit;
data tree[4*mx];

void update(int node,int low,int high,int index,ll val,ll vis)
{
    if(low==high)
    {
        tree[node].sum=vis;
        tree[node].val=val;
        tree[node].pos=index;
        return;
    }
    int mid=(low+high)/2;
    int left=2*node;
    int right=2*node+1;
    if(index<=mid) update(left,low,mid,index,val,vis);
    else update(right,mid+1,high,index,val,vis);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

ll query(int node,int low,int high,int index)
{
    tree[node].sum--;
    if(low==high) return tree[node].val;
    int mid=(low+high)/2;
    int left=2*node;
    int right=2*node+1;
    if(index<=tree[left].sum) return query(left,low,mid,index);
    else return query(right,mid+1,high,index-tree[left].sum);
}

int main()
{
    //CIN;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ll t;
    ll x;
    sfl(t);
    for1(z,t)
    {
        ll n,q;
        sffl(n,q);
        limit=n+q;  /// It's the highest limit if in every query there is "a" operation
        for1(i,n)
        {
            sfl(x);
            update(1,1,limit,i,x,1);
        }
        case2(z);
        for1(i,q)
        {
            scanf("%s",ch);
            sfl(x);
            if(ch[0]=='a')
            {
                n++;
                update(1,1,limit,n,x,1);
            }
            else
            {
                if(tree[1].sum<x) pf("none\n");
                else pf("%lld\n",query(1,1,limit,x));
            }
        }
        ms(tree,0);
    }
    return 0;
}
