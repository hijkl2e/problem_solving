#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	N += 3071;
	string ans(3, '*');
	ans[0] = N / 4096 + 234;
	ans[1] = N / 64 % 64 + 128;
	ans[2] = N % 64 + 128;
	cout << ans << "\n";
	return 0;
}
