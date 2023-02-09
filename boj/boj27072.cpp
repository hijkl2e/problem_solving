#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;
const double EPS = 1e-9;

struct line {
	ll a{}, b{};
	double c{};
};

double get_x(line &l1, line &l2) {
	return (l1.b - l2.b) * 1.0 / (l2.a - l1.a);
}

vector<vector<ll>> A;
vector<ll> ans;

void solve(ll x, ll y, ll len) {
	if (len == 1) {
		ll val = A[0][x] + A[1][y] - x * y;
		ans[x] = max(ans[x], val);
		ans[y] = max(ans[y], val);
		return;
	}
	int z = len / 2;
	len -= z;
	solve(x, y, z);
	solve(x + len, y + len, z);
	y += z;
	for (int k = 0; k < 2; ++k) {
		vector<line> C;
		for (int i = x + len - 1; i >= x; --i) {
			line L{-i, A[k][i], -INF};
			while (C.size()) {
				L.c = get_x(L, C.back());
				if (L.c < C.back().c - EPS) {
					C.pop_back();
				} else {
					break;
				}
			}
			C.push_back(L);
		}
		ll maxv = -INF;
		for (int i = 0, j = k ? 0 : (C.size() - 1); i < len; ++i) {
			z = y + (k ? i : (len - i - 1));
			while (z < C[j].c - EPS) {
				--j;
			}
			while (j + 1 < C.size() && C[j + 1].c - EPS < z) {
				++j;
			}
			maxv = max(maxv, C[j].a * z + C[j].b + A[k ^ 1][z]);
			ans[z] = max(ans[z], maxv);
		}
		swap(x, y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.assign(2, vector<ll>(N + 1));
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> A[i][j];
		}
	}
	ans.assign(N + 1, -INF);
	solve(1, 1, N);
	for (int i = 1; i <= N; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}
