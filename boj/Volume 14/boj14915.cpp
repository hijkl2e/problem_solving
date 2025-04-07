#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	if (N == 0) {
		cout << "0\n";
		return 0;
	}
	string S;
	while (N) {
		int r = N % M;
		N /= M;
		if (r < 10) {
			S.push_back(r + '0');
		} else {
			S.push_back(r + 'A' - 10);
		}
	}
	reverse(S.begin(), S.end());
	cout << S << "\n";
	return 0;
}
