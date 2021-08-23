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
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n;
double w, h;
int a[maxn], b[maxn];
bool check(double k)
{
    double dai = 0, rong = h;
    for (int i = 1; i <= n; i ++)
    {
        dai += k * a[i];
        if (dai > w) return 0;
        if(b[i] != b[i + 1] || dai + a[i + 1] * k > w){
            dai = 0;
            rong -= k * b[i];
        }
    }
    return rong >= 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> w >> h;
    for (int i = 1; i <= n; i ++) cin >> a[i] >> b[i];
    double l = 0;
    double r = 1000000000;
    while (r - l > 0.0000001)
    {
        double mid = (l + r)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision (6) << l;
}
