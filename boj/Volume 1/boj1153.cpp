#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

deque<bool> sieve() {
	deque<bool> p(1000001, true);
	p[0] = p[1] = false;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			for (int j = 2 * i; j < p.size(); j += i) {
				p[j] = false;
			}
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	if (N < 8) {
		cout << "-1\n";
		return 0;
	}
	deque<bool> p = sieve();
	vector<int> A;
	if (N % 2) {
		A = {2, 3};
		N -= 5;
	} else {
		A = {2, 2};
		N -= 4;
	}
	for (int i = 2; i < N; ++i) {
		if (p[i] && p[N - i]) {
			A.push_back(i);
			A.push_back(N - i);
			break;
		}
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < 4; ++i) {
		cout << A[i] << (i == 3 ? "\n" : " ");
	}
	return 0;
}
