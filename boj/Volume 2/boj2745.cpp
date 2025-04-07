#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string N;
	int B{};
	cin >> N >> B;
	int ans = stoi(N, nullptr, B);
	cout << ans << "\n";
	return 0;
}
