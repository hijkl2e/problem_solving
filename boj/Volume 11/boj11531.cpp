#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> right(26);
	vector<int> penalty(26);
	int M{};
	while (cin >> M, M != -1) {
		char P{};
		string V;
		cin >> P >> V;
		P -= 'A';
		if (right[P]) {
			continue;
		}
		if (V == "right") {
			right[P] = true;
			penalty[P] += M;
		} else {
			penalty[P] += 20;
		}
	}
	ii ans;
	for (int i = 0; i < 26; ++i) {
		if (right[i]) {
			++ans.first;
			ans.second += penalty[i];
		}
	}
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
