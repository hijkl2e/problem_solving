#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A{
		"", "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"
	};
	vector<string> B{
		"", "Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"
	};
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int a{}, b{};
		cin >> a >> b;
		if (a < b) {
			swap(a, b);
		}
		cout << "Case " << tc << ": ";
		if (a == b) {
			cout << B[a] << "\n";
		} else if (a == 6 && b == 5) {
			cout << "Sheesh Beesh\n";
		} else {
			cout << A[a] << " " << A[b] << "\n";
		}
	}
	return 0;
}
