#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;
const double EPS = 1e-9;

struct line {
	ll a{}, b{};
	double c{};
};

bool operator<(line &l1, line &l2) {
	return l1.a < l2.a || (l1.a == l2.a && l1.b < l2.b);
}

double get_x(line &l1, line &l2) {
	return (l1.b - l2.b) * 1.0 / (l2.a - l1.a);
}

vector<line> merge(vector<line> &A, vector<line> &B) {
	vector<line> C;
	for (int i = 0, j = 0; i < A.size() || j < B.size();) {
		line L = j == B.size() || (i < A.size() && A[i] < B[j]) ? A[i++] : B[j++];
		if (C.size() && L.a == C.back().a) {
			C.pop_back();
		}
		while (C.size()) {
			L.c = get_x(L, C.back());
			if (L.c < C.back().c + EPS) {
				C.pop_back();
			} else {
				break;
			}
		}
		C.push_back(L);
	}
	return C;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q{};
	cin >> Q;
	vector<line> A, B;
	while (Q--) {
		int q{};
		cin >> q;
		if (q == 1) {
			ll a{}, b{};
			cin >> a >> b;
			B.push_back({a, b, -INF});
			continue;
		}
		ll x{};
		cin >> x;
		if (B.size() > 400) {
			sort(B.begin(), B.end());
			A = merge(A, B);
			B.clear();
		}
		ll ans = -INF;
		for (auto &L : B) {
			ans = max(ans, L.a * x + L.b);
		}
		if (A.empty()) {
			cout << ans << "\n";
			continue;
		}
		int lo = 0, hi = A.size();
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (A[mid].c + EPS < x) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		ans = max(ans, A[lo].a * x + A[lo].b);
		cout << ans << "\n";
	}
	return 0;
}
