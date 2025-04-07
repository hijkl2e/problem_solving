#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int cnt1{}, cnt2{};
	while (N--) {
		int x{};
		cin >> x;
		cnt1 += 10 * (x / 30 + 1);
		cnt2 += 15 * (x / 60 + 1);
	}
	cout << (cnt1 < cnt2 ? "Y" : cnt1 > cnt2 ? "M" : "Y M") << " " << min(cnt1, cnt2) << "\n";
	return 0;
}
