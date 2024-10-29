#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int ans{};
		while (N != 6174) {
			string S = to_string(N);
			while (S.size() < 4) {
				S.push_back('0');
			}
			sort(S.rbegin(), S.rend());
			int a = stoi(S);
			reverse(S.begin(), S.end());
			int b = stoi(S);
			N = a - b;
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
