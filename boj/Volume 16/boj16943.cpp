#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string A;
	int B{};
	cin >> A >> B;
	sort(A.begin(), A.end());
	int ans = -1;
	do {
		if (A[0] == '0') {
			continue;
		}
		int x = stoi(A);
		if (x > B) {
			break;
		}
		ans = x;
	} while (next_permutation(A.begin(), A.end()));
	cout << ans << "\n";
	return 0;
}
