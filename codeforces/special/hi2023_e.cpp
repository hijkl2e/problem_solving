#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	string s(N, '1');
	for (int i = 0; i < N; ++i) {
		s[i] = '0';
		cout << "? " << i + 1 << " " << s << endl;
		s[i] = '1';
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.rbegin(), A.rend());
	s = string(N, '0');
	int cnt{};
	for (int i = 0; i < N; ++i) {
		auto &[u, v] = A[i];
		s[v] = '1';
		cnt += u;
		if (cnt == (i + 1) * (2 * N - i - 2) / 2) {
			break;
		}
	}
	cout << "! " << s << endl;
	return 0;
}
