#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

struct point {
	int x{}, y{};
};

int solve(point &p1, point &p2, point &p3) {
	int res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return abs(res);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<point> A(N + 1);
	for (int i = 0; i <= N; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	vector<int> B(N + 1);
	for (int i = 1; i < N; ++i) {
		B[i] = solve(A[i - 1], A[i], A[i + 1]);
	}
	set<int> S;
	for (int i = 0; i <= N; ++i) {
		S.insert(S.end(), i);
	}
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for (int i = 1; i < N; ++i) {
		pq.push({B[i], i});
	}
	M = N - M;
	while (M--) {
		while (pq.top().first != B[pq.top().second]) {
			pq.pop();
		}
		auto [a, b] = pq.top(); pq.pop();
		cout << b << "\n";
		B[b] = -1;
		auto it = S.find(b);
		it = S.erase(it);
		if (*it < N) {
			B[*it] = solve(A[*prev(it)], A[*it], A[*next(it)]);
			pq.push({B[*it], *it});
		}
		if (*--it) {
			B[*it] = solve(A[*prev(it)], A[*it], A[*next(it)]);
			pq.push({B[*it], *it});
		}
	}
	return 0;
}
