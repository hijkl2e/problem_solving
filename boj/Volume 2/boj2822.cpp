#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ii> A(8);
	for (int i = 0; i < 8; ++i) {
		cin >> A[i].first;
		A[i].second = i + 1;
	}
	sort(A.rbegin(), A.rend());
	int ans{};
	for (int i = 0; i < 5; ++i) {
		ans += A[i].first;
		swap(A[i].first, A[i].second);
	}
	sort(A.begin(), A.begin() + 5);
	cout << ans << "\n";
	for (int i = 0; i < 5; ++i) {
		cout << A[i].first << (i == 4 ? "\n" : " ");
	}
	return 0;
}
