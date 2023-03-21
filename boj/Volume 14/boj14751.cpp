#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using iii = tuple<int, int, int>;

const ll INF = 1e9 + 7;

struct frac {
	ll n{}, d{};
};

bool operator<=(frac &f1, frac &f2) {
	return f1.n * f2.d <= f2.n * f1.d;
}

struct line {
	ll a{}, b{};
	frac c{};
	int d{};
};

frac get_x(line &l1, line &l2) {
	return {l1.b - l2.b, l2.a - l1.a};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int maxX{}, minX{}, N{};
	cin >> maxX >> minX >> N;
	vector<iii> A(N);
	for (int i = 0; i < N; ++i) {
		auto &[l, u, idx] = A[i];
		cin >> u >> l;
		idx = i + 1;
	}
	sort(A.begin(), A.end());
	vector<iii> B;
	for (int i = 0; i < N; ++i) {
		if (B.empty() || get<1>(A[i]) < get<1>(B.back())) {
			B.push_back(A[i]);
		}
	}
	vector<line> C;
	for (auto &[l, u, idx] : B) {
		line L{u - l, l * maxX - u * minX, {-INF, 1}, idx};
		while (C.size()) {
			L.c = get_x(L, C.back());
			if (L.c <= C.back().c) {
				C.pop_back();
			} else {
				break;
			}
		}
		C.push_back(L);
	}
	int M{};
	cin >> M;
	while (M--) {
		double x{};
		cin >> x;
		frac f{lround(1000 * x), 1000};
		int lo = 0, hi = C.size();
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (C[mid].c <= f) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		cout << C[lo].d << "\n";
	}
	return 0;
}
