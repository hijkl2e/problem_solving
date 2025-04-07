#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	vector<int> B(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<double> C(3);
	for (int i = 0; i < 3; ++i) {
		int x = 10 * B[i];
		int y = 10 * A[i];
		if (y >= 5000) {
			y -= 500;
		}
		C[i] = x * 1.0 / y;
	}
	char ans = "SNU"[max_element(C.begin(), C.end()) - C.begin()];
	cout << ans << "\n";
	return 0;
}
