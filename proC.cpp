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
#define Task "proC"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
pair <double, double> a[maxn];
int n;
bool check(double k)
{
    double mx = -oo;
    double mn = oo;
    pair <double, double> giao[maxn];
    for (int i = 1; i <= n; i ++)
    {
        double g = sqrt(k * k - 1.00 * (a[i].S - k) * (a[i].S - k));
        giao[i].F = a[i].F - g;
        giao[i].S = a[i].F + g;
        mx = max(mx, giao[i].F);
        mn = min(mn, giao[i].S);
        if (mx > mn) return 0;
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    double mx = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].F >> a[i].S;
        a[i].S = abs(a[i].S);
        mx = max(mx, a[i].S);
    }
    double r = oo;
    double l = 1.00 * mx / 2;
    while (r - l > 0.0001)
    {
        double mid = (l + r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(3) << r;
}
