#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		string s;
		char c{};
		cin >> s >> A[i].first >> c >> A[i].second;
	}
	sort(A.begin(), A.end());
	vector<ii> B;
	double maxv{};
	for (int i = 0; i < N; ++i) {
		int j = (i + 1) % N;
		tm tm1{}, tm2{};
		tm1.tm_year = 2018;
		tm1.tm_mon = A[i].first - 1;
		tm1.tm_mday = A[i].second;
		tm2.tm_year = j ? 2018 : 2019;
		tm2.tm_mon = A[j].first - 1;
		tm2.tm_mday = A[j].second;
		double diff = difftime(mktime(&tm2), mktime(&tm1));
		if (maxv > diff) {
			continue;
		}
		--tm2.tm_mday;
		mktime(&tm2);
		if (maxv < diff) {
			maxv = diff;
			B.clear();
		}
		B.push_back({tm2.tm_mon + 1, tm2.tm_mday});
	}
	sort(B.begin(), B.end());
	ii ans = B[0];
	if (B.size() > 1) {
		auto it = lower_bound(B.begin(), B.end(), make_pair(10, 28));
		if (it != B.end()) {
			ans = B[it - B.begin()];
		}
	}
	cout << setfill('0');
	cout << setw(2) << ans.first << "-" << setw(2) << ans.second << "\n";
	return 0;
}
