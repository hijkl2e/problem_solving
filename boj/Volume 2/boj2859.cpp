#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> day{
		"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"
	};
	vector<int> A(4);
	for (int i = 0; i < 4; ++i) {
		int H{}, M{};
		char c{};
		cin >> H >> c >> M;
		A[i] = 60 * H + M;
	}
	if (A[0] > A[1]) {
		swap(A[0], A[1]);
		swap(A[2], A[3]);
	}
	if ((A[1] - A[0]) % gcd(A[2], A[3])) {
		cout << "Never\n";
		return 0;
	}
	int ans{};
	for (int i = 1;; ++i) {
		int x = A[0] + A[2] * i;
		if (x >= A[1] && (x - A[1]) % A[3] == 0) {
			ans = x;
			break;
		}
	}
	cout << day[ans / 1440 % 7] << "\n";
	cout << setfill('0') << setw(2) << ans % 1440 / 60;
	cout << ":" << setw(2) << ans % 60 << "\n";
	return 0;
}
