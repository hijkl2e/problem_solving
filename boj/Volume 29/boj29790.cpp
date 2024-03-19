#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, U{}, L{};
	cin >> N >> U >> L;
	string ans;
	if (N >= 1000) {
		if (U >= 8000 || L >= 260) {
			ans = "Very Good";
		} else {
			ans = "Good";
		}
	} else {
		ans = "Bad";
	}
	cout << ans << "\n";
	return 0;
}
