#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<iii> A(N);
	for (int i = 0; i < N; ++i) {
		auto &[x1, x2, idx] = A[i];
		int y{};
		cin >> x1 >> x2 >> y;
		idx = i + 1;
	}
	sort(A.begin(), A.end());
	vector<int> B(N + 1);
	int maxv = -1, p{};
	for (auto &[x1, x2, idx] : A) {
		if (maxv < x1) {
			++p;
		}
		B[idx] = p;
		maxv = max(maxv, x2);
	}
	while (Q--) {
		int a{}, b{};
		cin >> a >> b;
		cout << (B[a] == B[b]) << "\n";
	}
	return 0;
}
