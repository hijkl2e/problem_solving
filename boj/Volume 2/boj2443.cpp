#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = N - 1; i >= 0; --i) {
		cout << string(N - i - 1, ' ') << string(2 * i + 1, '*') << "\n";
	}
	return 0;
}
