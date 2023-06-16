#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll pow(ll x, ll y, ll mod) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % mod;
		}
		x = x * x % mod;
		y /= 2;
	}
	return ret;
}

template <typename T = ll>
class Seg {
public:
	Seg() { }
	Seg(int sz, int m) : n(sz), st1(2 * sz, 1), st2(sz), mod(m) { }
	void update(int p, T x, T d) {
		st2[p] += d;
		st1[p += n] = pow(x, st2[p]);
		for (; p > 1; p /= 2) {
			st1[p / 2] = st1[p] * st1[p ^ 1] % mod;
		}
	}
	T query() {
		return st1[1];
	}
private:
	int n, mod;
	vector<T> st1, st2;
};

deque<bool> sieve() {
	deque<bool> p(200001, true);
	p[0] = p[1] = false;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			for (int j = 2 * i; j < p.size(); j += i) {
				p[j] = false;
			}
		}
	}
	return p;
}

vector<int> A;
Seg seg;

void solve(int x, int y) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i) {
			continue;
		}
		int cnt{};
		while (x % i == 0) {
			x /= i;
			++cnt;
		}
		seg.update(A[i], i, y * cnt);
	}
	if (x > 1) {
		seg.update(A[x], x, y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> p = sieve();
	vector<int> P;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			P.push_back(i);
		}
	}
	A.assign(200001, -1);
	for (int i = 0; i < P.size(); ++i) {
		A[P[i]] = i;
	}
	int N{}, M{};
	cin >> N >> M;
	N -= 2;
	seg = Seg(1 << 15, M);
	ll ans{};
	for (int i = 1; i <= N; ++i) {
		solve(2 * i - 1, 1);
		solve(2 * i, 1);
		solve(i, -1);
		solve(i + 1, -1);
		ans += seg.query();
	}
	ans %= M;
	cout << ans << "\n";
	return 0;
}
