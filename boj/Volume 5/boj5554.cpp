#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t{};
	for (int i = 0; i < 4; ++i) {
		int x{};
		cin >> x;
		t += x;
	}
	cout << t / 60 << "\n" << t % 60 << "\n";
	return 0;
}
