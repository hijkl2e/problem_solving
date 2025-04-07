#include <bits/stdc++.h>

using namespace std;

double solve(vector<string> &A, int i) {
	int cnt{};
	for (auto &s : A) {
		if (s[i] == 'Y') {
			++cnt;
		}
	}
	return cnt * 1.0 / A.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> A, B;
	cout << fixed << setprecision(10);
	while (N--) {
		string s;
		cin >> s;
		if (s[0] == 'Y') {
			A.push_back(s);
		} else {
			B.push_back(s);
		}
	}
	for (int i = 1; i < 4; ++i) {
		double x = solve(A, i);
		double y = solve(B, i);
		if (x < y) {
			double ans = (y - x) / y * 100;
			cout << ans << "\n";
		} else {
			cout << "Not Effective\n";
		}
	}
	return 0;
}
