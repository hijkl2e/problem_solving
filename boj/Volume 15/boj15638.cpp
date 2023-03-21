#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	bool yes = true;
	for (int i = 2; i * i <= N; ++i) {
		if (N % i == 0) {
			yes = false;
			break;
		}
	}
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
