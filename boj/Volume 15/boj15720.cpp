#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> B(3);
	for (int i = 0; i < 3; ++i) {
		B[i].resize(A[i]);
		for (int j = 0; j < A[i]; ++j) {
			cin >> B[i][j];
		}
	}
	int minv = *min_element(A.begin(), A.end());
	int sum1{}, sum2{};
	for (auto &v : B) {
		sort(v.rbegin(), v.rend());
		sum1 += accumulate(v.begin(), v.begin() + minv, 0);
		sum2 += accumulate(v.begin() + minv, v.end(), 0);
	}
	cout << sum1 + sum2 << "\n";
	cout << sum1 / 10 * 9 + sum2 << "\n";
	return 0;
}
