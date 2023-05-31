#include <bits/stdc++.h>

using namespace std;

const int MOD = 20000303;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string N;
	getline(cin, N);
	int x{};
	for (char c : N) {
		x = (10 * x + c - '0') % MOD;
	}
	cout << x << "\n";
	return 0;
}
