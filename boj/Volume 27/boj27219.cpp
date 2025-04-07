#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	string ans = string(N / 5, 'V') + string(N % 5, 'I');
	cout << ans << "\n";
	return 0;
}
