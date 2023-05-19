#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int S{}, C{}, K{};
	cin >> S >> C >> K;
	vector<int> D(S);
	for (int i = 0; i < S; ++i) {
		cin >> D[i];
	}
	sort(D.begin(), D.end());
	int ans{};
	for (int i = 0; i < S;) {
		int j = i + 1;
		while (j < S && D[j] - D[i] <= K && j - i < C) {
			++j;
		}
		++ans;
		i = j;
	}
	cout << ans << "\n";
	return 0;
}
