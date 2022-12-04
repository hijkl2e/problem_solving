#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using dii = tuple<double, int, int>;

double dist(ii &p1, ii &p2) {
	auto &[x1, y1] = p1;
	auto &[x2, y2] = p2;
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double solve(vector<ii> &A, vector<ii> &B) {
	vector<dii> D;
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < B.size(); ++j) {
			D.push_back({dist(A[i], B[j]), i, j});
		}
	}
	sort(D.begin(), D.end());
	deque<bool> vstA(A.size());
	deque<bool> vstB(B.size());
	double ret{};
	for (auto &[d, i, j] : D) {
		if (vstA[i] || vstB[j]) {
			continue;
		}
		vstA[i] = vstB[j] = true;
		ret += d;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, P{};
	cin >> N >> M >> P;
	vector<ii> A(N);
	vector<ii> B(M);
	vector<ii> C(P);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i].first >> B[i].second;
	}
	for (int i = 0; i < P; ++i) {
		cin >> C[i].first >> C[i].second;
	}
	double ans = solve(A, B) + solve(A, C);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
