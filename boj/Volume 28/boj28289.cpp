#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(4);
	while (N--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		if (a == 1) {
			++A[3];
		} else {
			++A[max(b - 2, 0)];
		}
	}
	for (int i = 0; i < 4; ++i) {
		cout << A[i] << "\n";
	}
	return 0;
}
