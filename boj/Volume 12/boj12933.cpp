#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, int> A{
		{'q', 0}, {'u', 1}, {'a', 2}, {'c', 3}, {'k', 4}
	};
	string S;
	getline(cin, S);
	vector<int> B(5);
	int ans{};
	for (char c : S) {
		int x = A[c];
		if (B[x]) {
			--B[x], ++B[(x + 1) % 5];
		} else if (x == 0) {
			++B[1], ++ans;
		} else {
			ans = -1;
			break;
		}
	}
	if (count(B.begin() + 1, B.end(), 0) < 4) {
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}
