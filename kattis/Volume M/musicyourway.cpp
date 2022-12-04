#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> attr;
	string S;
	getline(cin, S);
	istringstream iss(S);
	while (iss >> S) {
		attr.push_back(S);
	}
	int M{};
	cin >> M;
	vector<vector<string>> A(M, vector<string>(attr.size()));
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < attr.size(); ++j) {
			cin >> A[i][j];
		}
	}
	int N{};
	cin >> N;
	while (N--) {
		cin >> S;
		int idx = find(attr.begin(), attr.end(), S) - attr.begin();
		stable_sort(A.begin(), A.end(), [&](const auto &v1, const auto &v2) {
			return v1[idx] < v2[idx];
		});
		for (int i = 0; i < attr.size(); ++i) {
			cout << attr[i] << (i == attr.size() - 1 ? "\n" : " ");
		}
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < attr.size(); ++j) {
				cout << A[i][j] << (j == attr.size() - 1 ? "\n" : " ");
			}
		}
		if (N) {
			cout << "\n";
		}
	}
	return 0;
}
