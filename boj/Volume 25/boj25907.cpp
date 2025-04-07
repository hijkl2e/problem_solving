#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int lo = 1, hi = N + 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		cout << "? " << mid << endl;
		int res{};
		cin >> res;
		res *= 2;
		if (res == mid) {
			cout << "! " << mid << endl;
			break;
		} else if (res > mid) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	return 0;
}
