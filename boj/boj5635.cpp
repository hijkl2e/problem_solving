#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<rec> A(N);
	for (auto &[a, b, c, d] : A) {
		cin >> d >> c >> b >> a;
	}
	sort(A.begin(), A.end());
	cout << get<3>(A[N - 1]) << "\n";
	cout << get<3>(A[0]) << "\n";
	return 0;
}
