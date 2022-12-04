#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{4, 3, 2, 7, 6, 5, 0, 4, 3, 2, 1};
	string S;
	getline(cin, S);
	int x{};
	for (int i = 0; i < S.size(); ++i) {
		x += A[i] * (S[i] - '0');
	}
	cout << (x % 11 == 0) << "\n";
	return 0;
}
