#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	char B{};
	cin >> N >> B;
	map<char, int> ds{
		{'A', 11}, {'K', 4}, {'Q', 3}, {'J', 20}, {'T', 10}, {'9', 14}
	};
	map<char, int> nds{
		{'A', 11}, {'K', 4}, {'Q', 3}, {'J', 2}, {'T', 10}
	};
	int ans{};
	for (int i = 0; i < 4 * N; ++i) {
		string card;
		cin >> card;
		if (card[1] == B) {
			ans += ds[card[0]];
		} else {
			ans += nds[card[0]];
		}
	}
	cout << ans << "\n";
	return 0;
}
