#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	int s = -1;
	for (int i = L; i < 101; ++i) {
		int x = i * (i - 1) / 2;
		if (N < x) {
			break;
		} else if ((N - x) % i == 0) {
			s = (N - x) / i;
			L = i;
			break;
		}
	}
	if (s == -1) {
		cout << "-1\n";
	} else {
		for (int i = 0; i < L; ++i) {
			cout << (s + i) << (i == L - 1 ? "\n" : " ");
		}
	}
	return 0;
}
