#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<iii> A;
	for (int i = 0; i < N; ++i) {
		int s{}, e{};
		cin >> s >> e;
		A.push_back({s, 1, i});
		A.push_back({e, -1, i});
	}
	sort(A.begin(), A.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; ++i) {
		pq.push(i);
	}
	vector<int> B(N);
	vector<int> C(N);
	int X{};
	for (auto &[a, b, c] : A) {
		if (b == 1) {
			int x = pq.top(); pq.pop();
			X = max(X, x + 1);
			++C[x];
			B[c] = x;
		} else {
			pq.push(B[c]);
		}
	}
	cout << X << "\n";
	for (int i = 0; i < X; ++i) {
		cout << C[i] << (i == X - 1 ? "\n" : " ");
	}
	return 0;
}
