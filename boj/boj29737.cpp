#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, int, int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, w{};
	cin >> N >> w;
	cin.ignore();
	vector<rec> A(N);
	for (int k = 0; k < N; ++k) {
		string id;
		getline(cin, id);
		vector<string> B(7);
		for (int i = 0; i < 7; ++i) {
			getline(cin, B[i]);
		}
		string S;
		for (int i = 0; i < w; ++i) {
			for (int j = 0; j < 7; ++j) {
				S += B[j][i];
			}
		}
		for (int i = 0, j = 1; i < S.size(); i = j++) {
			if (S[i] != 'O') {
				continue;
			}
			int cnt = 1, last = i;
			while (j < S.size() && S[j] != 'X') {
				if (S[j] == 'O') {
					last = j, ++cnt;
				}
				++j;
			}
			A[k] = min(A[k], {-cnt, last - i, i, 0, ""});
		}
		get<3>(A[k]) = count(S.begin(), S.end(), 'X');
		get<4>(A[k]) = id;
	}
	sort(A.begin(), A.end());
	for (int i = 0, r = 1; i < N; ++i) {
		string id = get<4>(A[i]);
		get<4>(A[i]) = "";
		if (i && A[i - 1] < A[i]) {
			++r;
		}
		cout << r << ". " << id << "\n";
	}
	return 0;
}
