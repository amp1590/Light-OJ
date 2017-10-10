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
#define mx                  100005

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
    ll prop,sum;
};

bool c;
data tree[3*mx],input[mx];

void build(int node,int low,int high)
{
    if(low==high) {tree[node].sum=input[low].sum;return; }
    int mid=(low+high)/2;
    int left=2*node;
    int right=2*node+1;
    build(left,low,mid);
    build(right,mid+1,high);
}

void pushdown(int node, int low, int high)
{
    if(tree[node].prop!=0)
    {
        int mid=(low+high)/2;
        int left=2*node;
        int right=2*node+1;
        tree[left].prop+=tree[node].prop;
        tree[right].prop+=tree[node].prop;
        tree[node].prop=0;
    }
}

void update(int node, int low, int high, int qlow, int qhigh)
{
    if(high<qlow || low>qhigh) return;  ///No Overlap
    else if(low>=qlow && high<=qhigh)  ///Total Overlap
    {
        tree[node].prop++;
        return;
    }

    pushdown(node,low,high);

    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    update(left,low,mid,qlow,qhigh);
    update(right,mid+1,high,qlow,qhigh);
}

int query(int node, int low, int high, int qlow, int qhigh)
{
    if(high<qlow || low>qhigh) return 0; ///No Overlap
    else if(low>=qlow && high<=qhigh)   ///Total Overlap
    {
        if(tree[node].prop%2==1) c= 1-tree[node].sum;
        else c= tree[node].sum;
        return 0;
    }
    pushdown(node,low,high);
    int left=node*2;
    int right=left+1;
    int mid=(low+high)/2;

    query(left,low,mid,qlow,qhigh);
    query(right,mid+1,high,qlow,qhigh);
}

int main()
{
    //CIN;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t;
    sf(t);
    for1(z,t)
    {
        string str;
        cin>>str,s;
        for0(i,sz(str)) input[i+1].sum=str[i]-'0';
        build(1,1,sz(str));
        int q,qlow,qhigh,val;
        sf(q);
        case2(z);
        for1(i,q)
        {
            cin>>s
            if(s=="I")
            {
                sff(qlow,qhigh);
                update(1,1,sz(str),qlow,qhigh);
            }
            else
            {
                sf(val);
                query(1,1,sz(str),val,val);
                pf("%d\n",c);
            }
        }
        ms(tree,0);
    }
    return 0;
}
