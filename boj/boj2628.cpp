#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	int N{};
	cin >> N;
	vector<int> A{0, R};
	vector<int> B{0, C};
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		if (x) {
			A.push_back(y);
		} else {
			B.push_back(y);
		}
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = A.size() - 1; i > 0; --i) {
		A[i] -= A[i - 1];
	}
	for (int i = B.size() - 1; i > 0; --i) {
		B[i] -= B[i - 1];
	}
	int ans = *max_element(A.begin(), A.end()) * *max_element(B.begin(), B.end());
	cout << ans << "\n";
	return 0;
}
