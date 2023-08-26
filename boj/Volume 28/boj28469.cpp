#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

double solve(vector<ii> &A, double x) {
	double f{};
	for (int i = 0; i < A.size(); ++i) {
		f += (i ? -1 : 1) * A[i].second / ((x - A[i].first) * (x - A[i].first));
	}
	return f;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first;
	}
	for (int i = 0; i < N; ++i) {
		cin >> A[i].second;
	}
	sort(A.begin(), A.end());
	double lo = A[0].first;
	double hi = A[1].first;
	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2;
		if (solve(A, mid) < 0) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << fixed << setprecision(10);
	cout << lo << "\n";
	return 0;
}
