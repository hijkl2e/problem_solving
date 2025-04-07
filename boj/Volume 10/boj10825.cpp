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
		cin >> d >> a >> b >> c;
		a *= -1;
		c *= -1;
	}
	sort(A.begin(), A.end());
	for (auto &[a, b, c, d] : A) {
		cout << d << "\n";
	}
	return 0;
}
