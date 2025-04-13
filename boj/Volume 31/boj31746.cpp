#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	string S = "SciComLove";
	if (N % 2) {
		reverse(S.begin(), S.end());
	}
	cout << S << "\n";
	return 0;
}
