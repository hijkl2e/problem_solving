#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cout << (100 * N >= M ? "Yes" : "No") << "\n";
	return 0;
}
