#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<ii> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i].first;
		B[i].second = i;
	}
	bool yes = true;
	vector<string> C(N, string(N, '0'));
	for (int i = 0; i < N; ++i) {
		sort(B.rbegin(), B.rend());
		for (int j = 0; j < A[i]; ++j) {
			--B[j].first;
			C[i][B[j].second] = '1';
		}
	}
	yes &= max_element(B.begin(), B.end())->first == 0;
	yes &= min_element(B.begin(), B.end())->first == 0;
	if (yes) {
		cout << "1\n";
		for (auto &s : C) {
			cout << s << "\n";
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
