#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	deque<bool> p(N + 1, true);
	vector<int> A;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			A.push_back(i);
			for (int j = 2 * i; j < p.size(); j += i) {
				if (p[j]) {
					p[j] = false;
					A.push_back(j);
				}
			}
		}
	}
	cout << A[K - 1] << "\n";
	return 0;
}
