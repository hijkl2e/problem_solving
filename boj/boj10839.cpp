#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
	ll x{}, y{};
};

using pi = pair<point, int>;

bool operator<(const point &p1, const point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

int ccw(point &p1, point &p2, point &p3) {
	ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

vector<point> convex_hull(vector<point> &A) {
	int n = A.size(), k{};
	vector<point> H(n);
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && ccw(H[k - 2], H[k - 1], A[i]) > -1) {
			--k;
		}
		H[k++] = A[i];
	}
	H.resize(k);
	return H;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<pi> A(N + 1);
	for (int i = 0; i < N; ++i) {
		auto &p = A[i].first;
		cin >> p.x >> p.y;
		A[i].second = i;
	}
	A[N] = A[0];
	int a{}, b{};
	cin >> a >> b;
	a = a ? a : N;
	b = b ? b : N;
	bool flag{};
	if (a > b) {
		swap(a, b);
		flag = true;
	}
	vector<point> B;
	for (int i = a; i <= b; ++i) {
		B.push_back(A[i].first);
	}
	B = convex_hull(B);
	sort(A.begin(), A.end());
	vector<int> C;
	for (auto &p : B) {
		auto it = lower_bound(A.begin(), A.end(), make_pair(p, -1));
		C.push_back(it->second);
	}
	if (flag) {
		reverse(C.begin(), C.end());
	}
	cout << C.size() << "\n";
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
