#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x1{}, x2{};
	cin >> x1 >> x2;
	deque<bool> A(1e6 + 1);
	deque<bool> B(1e6 + 1);
	int N1{};
	cin >> N1;
	while (N1--) {
		int x{};
		cin >> x;
		A[x] = true;
	}
	int N2{};
	cin >> N2;
	while (N2--) {
		int x{};
		cin >> x;
		B[x] = true;
	}
	if (x1 > x2) {
		swap(x1, x2);
		swap(A, B);
	}
	bool d1{}, d2{};
	int ans{};
	for (int i = 1; i < A.size(); ++i) {
		if (x2 - x1 < 5) {
			ans = i;
			break;
		}
		if (A[i]) {
			d1 ^= true;
		}
		if (B[i]) {
			d2 ^= true;
		}
		x1 += d1;
		x2 += d2;
	}
	if (ans == 0 && d1 && !d2) {
		ans = A.size() + x2 - x1 - 4;
	}
	if (ans) {
		cout << "bumper tap at time " << ans << "\n";
	} else {
		cout << "safe and sound\n";
	}
	return 0;
}
