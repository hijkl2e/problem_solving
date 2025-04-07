#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	if (N == 1) {
		cout << "A\n";
		return 0;
	}
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ii> B(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		B[i] = {A[i], A[i + 1]};
	}
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	if (B.size() == 1) {
		if (A[0] == A[1]) {
			cout << A[0] << "\n";
		} else {
			cout << "A\n";
		}
		return 0;
	}
	bool yes = true;
	vector<int> C;
	for (int i = 1; i < B.size(); ++i) {
		if (B[i - 1].first == B[i].first
				|| ((B[i].second - B[i - 1].second) % (B[i].first - B[i - 1].first))) {
			yes = false;
			break;
		}
		C.push_back((B[i].second - B[i - 1].second) / (B[i].first - B[i - 1].first));
	}
	sort(C.begin(), C.end());
	C.resize(unique(C.begin(), C.end()) - C.begin());
	yes &= C.size() == 1;
	if (yes) {
		int a = C[0];
		int b = A[1] - A[0] * a;
		int ans = A[N - 1] * a + b;
		cout << ans << "\n";
	} else {
		cout << "B\n";
	}
	return 0;
}
