#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	string S;
	while (N) {
		S += to_string(N % 9);
		N /= 9;
	}
	reverse(S.begin(), S.end());
	cout << S << "\n";
	return 0;
}
