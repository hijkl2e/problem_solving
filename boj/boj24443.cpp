#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N);
	while (Q--) {
		int q{}, a{}, b{}, c{};
		cin >> q >> a >> b;
		--a, --b;
		if (q == 1) {
			cin >> c;
			copy(A.begin() + a, A.begin() + b + 1, B.begin());
			nth_element(B.begin(), B.begin() + c - 1, B.begin() + b - a + 1);
			cout << B[c - 1] << "\n";
		} else {
			swap(A[a], A[b]);
		}
	}
	return 0;
}
