#include <bits/stdc++.h>

#define pf              printf
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sffl(a,b)       scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
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
#define case1(z)         cout<<"Case "<<z<<": "
#define case2(z,x)       cout<<"Case "<<z<<": "<<x<<endl
#define PI              3.14159265358979323846264338328
#define valid(tx,ty)    tx>=0 && tx<r && ty>=0 && ty<c
#define intlim          2147483648
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

int main()
{
    CIN;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    loop1(z,t)
    {
        int n,a=-100000000,b=100000000;
        cin>>n;
        vector< pair<int,string> >tanmoy;
//        map<string,int> mp;
        loop0(i,n)
        {
            string s;
            cin>>s;
            int p,q,r,gun=1;
            cin>>p>>q>>r;
//            x=x*y*z;
//            x*=y;
//            x*=xx;
            gun=p*q*r;
           tanmoy.pb(make_pair(gun,s));
            a=max(gun,a);
            b=min(gun,b);
        }
        sort(all(tanmoy));
        string s1,s2;
        if(a!=b)
        {
            cout<<"Case "<<z<<": "<<tanmoy[n-1].second<<" took chocolate from "<<tanmoy[0].second<<endl;
        }
        else
            cout<<"Case "<<z<<": no thief"<<endl;
    }
    return 0;
}
