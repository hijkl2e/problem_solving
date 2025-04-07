#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<rec> A(N);
	for (int i = 0; i < N; ++i) {
		auto &[s, c, l, n] = A[i];
		cin >> s >> c >> l;
		n = i + 1;
		s *= -1;
	}
	auto &[s, c, l, n] = *min_element(A.begin(), A.end());
	cout << n << "\n";
	return 0;
}
