#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<iii> A;
	for (int i = 1; i <= M; ++i) {
		int a{}, b{};
		cin >> a >> b;
		if (a < b) {
			A.push_back({a, -b, i});
			A.push_back({N + a, -(N + b), i});
		} else {
			A.push_back({a, -(N + b), i});
		}
	}
	sort(A.begin(), A.end());
	deque<bool> B(M + 1, true);
	int maxv{};
	for (auto &[a, b, c] : A) {
		b *= -1;
		if (b <= maxv) {
			B[c] = false;
		}
		maxv = max(maxv, b);
	}
	vector<int> C;
	for (int i = 1; i <= M; ++i) {
		if (B[i]) {
			C.push_back(i);
		}
	}
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
