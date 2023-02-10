#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cout << string(N + 2, '@') << "\n";
	for (int i = 0; i < N; ++i) {
		cout << "@" << string(N, ' ') << "@\n";
	}
	cout << string(N + 2, '@') << "\n";
	return 0;
}
