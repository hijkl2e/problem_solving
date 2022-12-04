#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> name(N);
	for (int i = 0; i < N; ++i) {
		cin >> name[i];
	}
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> A(S.size());
	A[0] = 1;
	for (int i = 1; i < S.size(); ++i) {
		A[i] = S[i] == S[i - 1] ? A[i - 1] + 1 : 1;
	}
	int maxv = *max_element(A.begin(), A.end());
	int wo = 0, bo = 1, wd = 2, bd = 3;
	int W = wo * N + wd;
	int B = bo * N + bd;
	queue<int> q;
	for (int i = 4; i < N; ++i) {
		q.push(i);
	}
	for (int i = 0; i < S.size(); ++i) {
		swap(wo, wd);
		swap(bo, bd);
		if (S[i] == 'W') {
			q.push(bo);
			bo = q.front();
			q.pop();
			B = bd * N + bo;
		} else {
			q.push(wo);
			wo = q.front();
			q.pop();
			W = wd * N + wo;
		}
		if (A[i] == maxv) {
			int team = S[i] == 'W' ? W : B;
			cout << name[team / N] << " " << name[team % N] << "\n";
		}
	}
	return 0;
}
