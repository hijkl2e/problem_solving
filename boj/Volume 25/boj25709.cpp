#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	while (N) {
		string S = to_string(N);
		int p = S.find('1');
		if (p == -1) {
			--N;
		} else {
			S.erase(S.begin() + p);
			N = S.size() ? stoi(S) : 0;
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
