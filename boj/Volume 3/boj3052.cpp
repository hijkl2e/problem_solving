#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<int> S;
	for (int i = 0; i < 10; ++i) {
		int x{};
		cin >> x;
		S.insert(x % 42);
	}
	cout << S.size() << "\n";
	return 0;
}
