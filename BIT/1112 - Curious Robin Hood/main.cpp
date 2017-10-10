/// 1. By applying Segment Tree ///
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

ll input[mx],tree[3*mx];

void build(int node,int low,int high)
{
    if(low==high)
    {
        tree[node]=input[low];
        return;
    }
    int mid=(low+high)/2;
    int left=2*node;
    int right=2*node+1;
    build(left,low,mid);
    build(right,mid+1,high);
    tree[node]=tree[left]+tree[right];
}

ll query(int node,int low,int high,int qlow,int qhigh)
{
    if(low>qhigh || high<qlow) /// No overlap
        return 0;
    else if(low>=qlow && high<=qhigh) /// Total overlap
        return tree[node];
    int mid=(low+high)/2;
    int left=2*node;
    int right=2*node+1;
    ll l=query(left,low,mid,qlow,qhigh);
    ll r=query(right,mid+1,high,qlow,qhigh);
    return l+r;
}

void update(int node,int low,int high,int index,ll val)
{
    if(low>index || high<index) /// No overlap
        return;
    else if(low>=index && high<=index) ///Or, if(low==high) /// Total overlap
    {
        tree[node]+=val;
        return;
    }
    int mid=(low+high)/2;
    int left=2*node;
    int right=2*node+1;
    update(left,low,mid,index,val);
    update(right,mid+1,high,index,val);
    tree[node]=tree[left]+tree[right];
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
        int n,q;
        sff(n,q);
        for1(i,n) sf(input[i]);
        build(1,1,n);
        case2(z);
        for1(i,q)
        {
            int mark,qlow,qhigh,val,index;
            sf(mark);
            if(mark==1)
            {
                sf(index);
                index++;
                int a=query(1,1,n,index,index);
                pf("%d\n",a);
                update(1, 1, n, index, -a);
            }
            else if(mark==2)
            {
                sff(index,val);
                index++;
                update(1, 1, n, index, val);
            }
            else
            {
                sff(qlow,qhigh);
                qlow++,qhigh++;
                pf("%lld\n",query(1, 1, n, qlow,qhigh));
            }
        }
    }
    return 0;
}

/// 2. By applying BIT ///
//#include <bits/stdc++.h>
//
//#define pf                  printf
//#define sf(a)               scanf("%d",&a)
//#define sfl(a)              scanf("%lld",&a)
//#define sff(a,b)            scanf("%d %d",&a,&b)
//#define sffl(a,b)           scanf("%lld %lld",&a,&b)
//#define sfff(a,b,c)         scanf("%d %d %d",&a,&b,&c)
//#define sfffl(a,b,c)        scanf("%lld %lld %lld",&a,&b,&c)
//#define sffff(a,b,c,d)      scanf("%d %d %d %d",&a,&b,&c,&d)
//#define sffffl(a,b,c,d)     scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
//#define sfffff(a,b,c,d,e)   scanf("%d %d %d %d %d",&a,&b,&c,&d,&e)
//#define sfffffl(a,b,c,d,e)  scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e)
//#define sfc(a)              scanf("%c",&a)
//#define pii                 pair<int,int>
//#define ms(a,b)             memset(a,b,sizeof(a))
//#define pb(a)               push_back(a)
//#define pbp(a,b)            push_back({a,b})
//#define db                  double
//#define ft                  float
//#define ll                  long long
//#define ull                 unsigned long long
//#define pii                 pair<int,int>
//#define ff                  first
//#define ss                  second
//#define sz(x)               x.size()
//#define all(x)              x.begin(),x.end()
//#define CIN                 ios_base::sync_with_stdio(0); cin.tie(0)
//#define max3(a, b, c)       max(a, b) > max(b, c) ? max(a, b) : max(b, c)
//#define min3(a, b, c)       min(a, b) < min(b, c) ? min(a, b) : min(b, c)
//#define for0(i,n)           for(int i=0;i<n;i++)
//#define for1(i,n)           for(int i=1;i<=n;i++)
//#define forrev(i,n)         for(int i=n-1; i>=0; i--)
//#define forab(i,a,b)        for(int i=a;i<=b;i++)
//#define forba(i,b,a)        for(int i=b;i>=a;i--)
//#define stlloop(x)          for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
//#define gcd(a, b)           __gcd(a, b)
//#define lcm(a, b)           ((a)*((b)/gcd(a,b)))
//#define case1(z)            cout<<"Case "<<z<<": "
//#define case2(z)            printf("Case %d:\n",z)
//#define PI                  acos(-1) //3.14159265358979323846264338328
//#define valid(tx,ty)        tx>=0 && tx<row && ty>=0 && ty<col
//#define intlim              2147483648
//#define MAX                 100005
//#define inf                 100000008
//
///*------------------------------Graph Moves----------------------------*/
////const int fx[]={+1,-1,+0,+0};
////const int fy[]={+0,+0,+1,-1};
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
////const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
////const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
///*---------------------------------------------------------------------*/
//
//using namespace std;
//
//ll input[MAX],tree[MAX];
//
//ll query(int idx)
//{
//    ll sum=0;
//    while(idx>0)
//    {
//        sum+=tree[idx];
//        idx-=idx & (-idx);
//    }
//    return sum;
//}
//
//void update(int idx,ll val,int n)
//{
//    while(idx<=n)
//    {
//        tree[idx]+=val;
//        idx+=idx & (-idx);
//    }
//}
//
//int main()
//{
//    //CIN;
////    freopen("in.txt","r",stdin);
////    freopen("out.txt","w",stdout);
//    int t,x,y;
//    sf(t);
//    for1(z,t)
//    {
//        case2(z);
//        int n,q,x,idx,qlow,qhigh;
//        ll val;
//        sff(n,q);
//        for1(i,n)
//        {
//            sfl(input[i]);
//            update(i,input[i],n);
//        }
//        for1(i,q)
//        {
//            sf(x);
//            if(x==1)
//            {
//                sf(idx);
//                idx++;
//                pf("%lld\n",input[idx]);
//                update(idx,-input[idx],n);
//                input[idx]=0;
//            }
//            else if(x==2)
//            {
//                sf(idx);
//                sfl(val);
//                idx++;
//                update(idx,val,n);
//                input[idx]+=val;
//            }
//            else
//            {
//                sff(qlow,qhigh);
//                qlow++;
//                qhigh++;
//                pf("%lld\n",query(qhigh)-query(qlow-1));
//            }
//        }
//        ms(tree,0);
//    }
//    return 0;
//}
