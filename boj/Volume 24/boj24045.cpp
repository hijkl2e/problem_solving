#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool dir(ll x) {
	return x < 3 ? true : !dir(x / 2 - (x % 4 == 0));
}

bool pos(ll x) {
	return x % 2 ? false : x < 6 ? x / 4 : x % 8 == 0 ? !dir(x) : pos(x / 4 * 2);
}

struct intv {
	intv(ll _s, ll _l) : s(_s), l(_l) {
		cl = (l - 1) / 2 * 2;
		if (l % 4 == 1 && l > 1) {
			++cl;
		}
		d = dir(l);
	}
	ll s{}, l{}, cl{};
	bool d{};
};

bool operator<(const intv &i1, const intv &i2) {
	return i1.cl < i2.cl || (i1.cl == i2.cl && (i1.d ^ (i1.s < i2.s)));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<ll> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	priority_queue<intv> pq;
	if (A[0] > 1) {
		pq.push(intv(3 - A[0], 2 * A[0] - 3));
	}
	for (int i = 0; i < M - 1; ++i) {
		if (A[i + 1] - A[i] > 1) {
			pq.push(intv(A[i] + 1, A[i + 1] - A[i] - 1));
		}
	}
	if (A[M - 1] < N) {
		pq.push(intv(A[M - 1] + 1, 2 * (N - A[M - 1]) - 1));
	}
	while (K--) {
		intv i = pq.top(); pq.pop();
		ll x = i.s + (i.l - 1) / 2 + pos(i.l);
		cout << x << "\n";
		if (i.l > 2 && x > 1) {
			pq.push(intv(i.s, x - i.s));
		}
		if (i.l > 1 && x < N) {
			pq.push(intv(x + 1, i.s + i.l - x - 1));
		}
	}
	return 0;
}
