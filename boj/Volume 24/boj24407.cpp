#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C{}, N{};
	cin >> C >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ii> error, correct;
	if (A[0] > 1) {
		correct.push_back({1, A[0] - 1});
	}
	int from{};
	for (int i = 1; i < N; ++i) {
		if (A[i] == A[i - 1] + 1) {
			continue;
		}
		error.push_back({A[from], A[i - 1]});
		correct.push_back({A[i - 1] + 1, A[i] - 1});
		from = i;
	}
	error.push_back({A[from], A.back()});
	if (A.back() < C) {
		correct.push_back({A.back() + 1, C});
	}
	cout << "Errors: ";
	for (int i = 0; i < error.size(); ++i) {
		auto &p = error[i];
		cout << p.first;
		if (p.first < p.second) {
			cout << "-" << p.second;
		}
		cout << (i == error.size() - 1 ? "\n" : i == error.size() - 2 ? " and " : ", ");
	}
	cout << "Correct: ";
	for (int i = 0; i < correct.size(); ++i) {
		auto &p = correct[i];
		cout << p.first;
		if (p.first < p.second) {
			cout << "-" << p.second;
		}
		cout << (i == correct.size() - 1 ? "\n" : i == correct.size() - 2 ? " and " : ", ");
	}
	return 0;
}
