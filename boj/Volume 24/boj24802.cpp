#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

double solve(vector<ii> &A, double t) {
	double ret{};
	for (auto &p : A) {
		if (t < p.second) {
			ret += p.first * t / p.second;
			break;
		}
		ret += p.first;
		t -= p.second;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ii> A(N);
	vector<ii> B(M);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i].first >> B[i].second;
	}
	int H{};
	for (auto &p : A) {
		H += p.first;
	}
	double lo = 0, hi = 5e5;
	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2;
		if (solve(A, mid) < H - solve(B, mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << fixed << setprecision(10);
	cout << lo << "\n";
	return 0;
}
