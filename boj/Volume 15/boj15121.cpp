#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int S{};
	cin >> S;
	cout << S << ":\n";
	for (int i = 2; i < S; ++i) {
		for (int j = i - 1; j <= i; ++j) {
			if (S % (i + j) == 0 || (S - i) % (i + j) == 0) {
				cout << i << "," << j << "\n";
			}
		}
	}
	return 0;
}
