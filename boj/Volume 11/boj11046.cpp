#include <bits/stdc++.h>

using namespace std;

vector<int> manacher(vector<int> &v) {
	int n = v.size();
	vector<int> p(n);
	int x{}, y{};
	for (int i = 0; i < n; ++i) {
		p[i] = y < i ? 0 : min(y - i + 1, p[2 * x - i]);
		while (i - p[i] >= 0 && i + p[i] < n && v[i - p[i]] == v[i + p[i]]) {
			++p[i];
		}
		if (i + p[i] - 1 > y) {
			x = i, y = i + p[i] - 1;
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(2 * N + 1, -1);
	for (int i = 1; i < A.size(); i += 2) {
		cin >> A[i];
	}
	vector<int> p = manacher(A);
	int M{};
	cin >> M;
	while (M--) {
		int s{}, e{};
		cin >> s >> e;
		s = 2 * s - 1;
		e = 2 * e - 1;
		int x = (s + e) / 2;
		cout << (e - s + 1 < 2 * p[x]) << "\n";
	}
	return 0;
}
