//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 100005
#define MOD
#define Task "proD"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n;
int v[maxn];
int x[maxn];
double f(double k)
{
    double mx = DBL_MIN;
    double mn = DBL_MAX;
    for (int i = 1; i <= n; i ++)
    {
        mx = max(k * v[i] + x[i], mx);
        mn = min(k * v[i] + x[i], mn);
    }
    return mx - mn;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> x[i] >> v[i];
    double l = 0;
    double r = 1e18;
    for (int xx = 1; xx <= 600; xx ++)
    {
        double u = l + (r - l)/3;
        double v = r - (r - l)/3;
        if (f(u) <= f(v) + 0.0000000001) r = v;
        else l = u;
    }
    double g = f(0);
    if (f(l) >= g) cout << fixed << setprecision(6) << 0 << " " << g;
    else cout << fixed << setprecision(6) << l << " " << f(l);
}
