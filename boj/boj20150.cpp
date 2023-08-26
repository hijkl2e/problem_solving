#include <bits/stdc++.h>

using namespace std;

using ll = __int128;
using rec = tuple<ll, int, ll, int>;

ll X;

struct point {
	ll x{}, y{};
};

struct line {
	point p1{}, p2{};
};

bool operator<(point &p1, point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

bool operator<(const line &l1, const line &l2) {
	ll a = (l1.p2.y - l1.p1.y) * X + (l1.p2.x * l1.p1.y - l1.p1.x * l1.p2.y);
	ll b = (l2.p2.y - l2.p1.y) * X + (l2.p2.x * l2.p1.y - l2.p1.x * l2.p2.y);
	return (l2.p2.x - l2.p1.x) * a < (l1.p2.x - l1.p1.x) * b;
}

int ccw(const point &p1, const point &p2, const point &p3) {
	ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

void linear_transform(vector<line> &A) {
	set<int> S;
	for (auto &l : A) {
		if (l.p1.y != l.p2.y && (l.p2.x - l.p1.x) % (l.p1.y - l.p2.y) == 0) {
			S.insert((l.p2.x - l.p1.x) / (l.p1.y - l.p2.y));
		}
	}
	int k{};
	auto it = S.find(0);
	while (it != S.end() && *it == k) {
		++it, ++k;
	}
	for (auto &l : A) {
		l.p1 = {l.p1.x + k * l.p1.y, l.p1.y - k * l.p1.x};
		l.p2 = {l.p2.x + k * l.p2.y, l.p2.y - k * l.p2.x};
	}
}

bool are_intersect(const line &l1, const line &l2) {
	int r1 = ccw(l1.p1, l1.p2, l2.p1);
	int r2 = ccw(l1.p1, l1.p2, l2.p2);
	int r3 = ccw(l2.p1, l2.p2, l1.p1);
	int r4 = ccw(l2.p1, l2.p2, l1.p2);
	return r1 * r2 < 1 && r3 * r4 < 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<line> A(N);
	for (int i = 0; i < N; ++i) {
		int x1{}, y1{}, x2{}, y2{};
		cin >> x1 >> y1 >> x2 >> y2;
		A[i] = {{x1, y1}, {x2, y2}};
	}
	linear_transform(A);
	vector<rec> E;
	for (int i = 0; i < N; ++i) {
		auto &l = A[i];
		if (l.p2 < l.p1) {
			swap(l.p1, l.p2);
		}
		E.push_back({l.p1.x, 0, l.p1.y, i});
		E.push_back({l.p2.x, 1, l.p2.y, i});
	}
	sort(E.begin(), E.end());
	bool yes{};
	multiset<line> S;
	for (auto &[x, t, y, idx] : E) {
		X = x;
		if (t) {
			auto it = S.find(A[idx]);
			if (it != S.begin() && next(it) != S.end()
					&& are_intersect(*prev(it), *next(it))) {
				yes = true;
				break;
			}
			S.erase(it);
		} else {
			auto it = S.insert(A[idx]);
			if ((it != S.begin() && are_intersect(*it, *prev(it)))
					|| (next(it) != S.end() && are_intersect(*it, *next(it)))) {
				yes = true;
				break;
			}
		}
	}
	cout << yes << "\n";
	return 0;
}
