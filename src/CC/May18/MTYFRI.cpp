#include <bits/stdc++.h>
using namespace std;
//#include <bigInt.h>

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector< vll > vvll;



template<class T> T abs(T x) { return x > 0 ? x : -x;}

const ll mod = 1000000000 + 7;
#define sz(a) int((a).size())
#define pb push_back
#define fi first
#define se second
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define trr(c,i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define repc(c,i,l,r) for (auto b = next(c.begin(),(l)),i=b, e=next((c).begin(),(r)); i!=e; ++i)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(m,arr) {cout<<"\n"<<(m); for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m);for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}
#define debug(m,x) cout <<"\n"<<(m)<<#x<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<<#x << ", "<<#y<<"| "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<<" "<<#x<<", "<<#y<<", "<<#z<<"| "<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<#w<<", "<<#x<<", "<<#y<<", "<<#z<<"| "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
#define _(x) cout <<"\n"<< (#x) <<" "<< (x) ;

const LD EPS=1e-12;
const LD INF=1e100;

//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}

// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const vector<T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for maps
template < class T, class U >
ostream& operator << (ostream& os, const map<T, U>& mp)
{
    os << "mp:[";
    for (auto ii = mp.begin(); ii != mp.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

//class holding state
template <class T>
class state
{
public:
    state(int size): s(size, 0) {}

    vll s;

     friend ostream& operator<<( ostream& os , state<T> &st)
    {
        os<<st.s;
        return os;
    }
};



int main()
{
    freopen("inMTYFRI.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    ll T, N, K;
    cin>>T;

    rep(t,0,T)
    {
        cin>>N>>K;
        vll A(N);
        vll A1sd,A2sa;//1-Motu, 2-Tomu
        string res;

        rep(i,0,N) {cin>>A[i];if(i%2==0)A1sd.pb(A[i]); else A2sa.pb(A[i]);}
        sort(all(A1sd), [](ll el1, ll el2)->bool{ return el1>el2 ;});
        sort(all(A2sa), [](ll el1, ll el2)->bool{ return el1<el2 ;} );

        ll sc1=0, sc2=0;
        rep(i,0,A1sd.size()) sc1+=A1sd[i];
        rep(i,0,A2sa.size()) sc2+=A2sa[i];

        rep(i,0,min( K, (ll)min(A1sd.size(), A2sa.size()) ) )
        {
            if(A1sd[i]> A2sa[i])
            {
                ll c=abs(A1sd[i]- A2sa[i]);
                sc1+=-c;
                sc2+=c;
            }
            else
            {
                break;
            }
        }
        if(sc2>sc1) res="YES"; else res="NO";

        cout<<((t==0)?(""):("\n"))<<res;
    }


    return 0;
}
