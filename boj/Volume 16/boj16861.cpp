#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	while (true) {
		string s = to_string(N);
		int sum = accumulate(s.begin(), s.end(), 0) - s.size() * '0';
		if (N % sum == 0) {
			break;
		}
		++N;
	}
	cout << N << "\n";
	return 0;
}
