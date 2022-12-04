#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, P{};
	cin >> N >> M >> P;
	vector<int> C(N);
	vector<int> D(M);
	for (int i = 0; i < N; ++i) {
		cin >> C[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> D[i];
	}
	vector<double> E;
	E.reserve(N * M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			E.push_back(D[j] * 1.0 / C[i]);
		}
	}
	sort(E.begin(), E.end());
	bool yes = true;
	for (int i = 0; i < E.size() - 1; ++i) {
		if (E[i] * (100 + P) / 100 + EPS < E[i + 1]) {
			yes = false;
			break;
		}
	}
	cout << (yes ? "Ride on!" : "Time to change gears!") << "\n";
	return 0;
}
