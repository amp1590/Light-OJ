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
    //CIN;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    loop1(z,t)
    {
        db r1,r2,r3;
        cin>>r1>>r2>>r3;

        db a=r1+r2;
        db b=r1+r3;
        db c=r2+r3;
        db s=(a+b+c)/2;
        db area1=sqrt(s*(s-a)*(s-b)*(s-c));

        db A=acos((b*b+c*c-a*a)/(2*b*c));
        db B=acos((a*a+c*c-b*b)/(2*a*c));
        db C=acos((a*a+b*b-c*c)/(2*a*b));

        db area_A= A*r3*r3*0.5;
        db area_B= B*r2*r2*0.5;
        db area_C= C*r1*r1*0.5;

        db area2=(area_A+area_B+area_C);

        db ans=area1-area2;
        pf("Case %d: %.10f\n",z,ans);
    }

    return 0;
}
