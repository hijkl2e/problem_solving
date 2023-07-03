#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	while (cin >> N >> M) {
		cout << M / (N + 1) << "\n";
	}
	return 0;
}
