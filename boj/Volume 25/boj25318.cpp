#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	if (N == 0) {
		cout << "0\n";
		return 0;
	}
	vector<time_t> A(N);
	vector<int> L(N);
	for (int i = 0; i < N; ++i) {
		tm time{};
		char c{};
		cin >> time.tm_year >> c >> time.tm_mon >> c >> time.tm_mday;
		cin >> time.tm_hour >> c >> time.tm_min >> c >> time.tm_sec;
		time.tm_year -= 1900;
		--time.tm_mon;
		A[i] = mktime(&time);
		cin >> L[i];
	}
	vector<double> P(N);
	for (int i = 0; i < N; ++i) {
		P[i] = max(pow(0.5, difftime(A[N - 1], A[i]) / 31536000.0), pow(0.9, N - i - 1));
	}
	double d{}, n{};
	for (int i = 0; i < N; ++i) {
		d += P[i];
		n += P[i] * L[i];
	}
	int ans = lround(n / d);
	cout << ans << "\n";
	return 0;
}
