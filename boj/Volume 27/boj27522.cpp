#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> R, B, T;
	for (int i = 0; i < 8; ++i) {
		string s;
		char c{};
		cin >> s >> c;
		if (c == 'R') {
			R.push_back(s);
		} else {
			B.push_back(s);
		}
		T.push_back(s);
	}
	sort(R.begin(), R.end());
	sort(B.begin(), B.end());
	sort(T.begin(), T.end());
	vector<int> A{10, 8, 6, 5, 4, 3, 2, 1};
	int R_sum{}, B_sum{};
	for (int i = 0; i < 4; ++i) {
		R_sum += A[lower_bound(T.begin(), T.end(), R[i]) - T.begin()];
	}
	for (int i = 0; i < 4; ++i) {
		B_sum += A[lower_bound(T.begin(), T.end(), B[i]) - T.begin()];
	}
	bool flag = R_sum > B_sum;
	if (R_sum == B_sum) {
		int x = lower_bound(T.begin(), T.end(), R[0]) - T.begin();
		int y = lower_bound(T.begin(), T.end(), B[0]) - T.begin();
		flag = x < y;
	}
	cout << (flag ? "Red" : "Blue") << "\n";
	return 0;
}
