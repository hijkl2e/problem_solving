#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> A(10001);
	for (int i = 1; i < A.size(); ++i) {
		int sum = i;
		int j = i;
		while (j) {
			sum += j % 10;
			j /= 10;
		}
		if (sum < A.size()) {
			A[sum] = true;
		}
	}
	for (int i = 1; i < A.size(); ++i) {
		if (!A[i]) {
			cout << i << "\n";
		}
	}
	return 0;
}
