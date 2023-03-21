#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(5);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 4; ++j) {
			int x{};
			cin >> x;
			A[i] += x;
		}
	}
	int x = max_element(A.begin(), A.end()) - A.begin();
	cout << x + 1 << " " << A[x] << "\n";
	return 0;
}
