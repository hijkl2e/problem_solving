#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, K{};
	cin >> M >> K;
	cout << (M % K == 0 ? "Yes" : "No") << "\n";
	return 0;
}
