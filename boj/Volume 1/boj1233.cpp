#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int s1{}, s2{}, s3{};
	cin >> s1 >> s2 >> s3;
	vector<int> A(s1 + s2 + s3 + 1);
	for (int i = 1; i <= s1; ++i) {
		for (int j = 1; j <= s2; ++j) {
			for (int k = 1; k <= s3; ++k) {
				++A[i + j + k];
			}
		}
	}
	int ans = max_element(A.begin(), A.end()) - A.begin();
	cout << ans << "\n";
	return 0;
}
