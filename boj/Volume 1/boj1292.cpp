#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A;
	for (int i = 1; i < 51; ++i) {
		for (int j = 0; j < i; ++j) {
			A.push_back(i);
		}
	}
	int a{}, b{};
	cin >> a >> b;
	int ans = accumulate(A.begin() + a - 1, A.begin() + b, 0);
	cout << ans << "\n";
	return 0;
}
