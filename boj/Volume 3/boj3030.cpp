#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string p1, p2;
	cin >> p1 >> p2;
	int N{};
	cin >> N;
	cin.ignore();
	while (N--) {
		string S;
		getline(cin, S);
		istringstream iss(S);
		vector<int> A;
		vector<int> B;
		int a{}, b{};
		char c{};
		while (iss >> a >> c >> b) {
			A.push_back(a);
			B.push_back(b);
		}
		int score{};
		bool yes = A.size() == 2 || A.size() == 3;
		for (int i = 0; i < A.size(); ++i) {
			int maxv = max(A[i], B[i]);
			int minv = min(A[i], B[i]);
			yes &= maxv > minv;
			if (i == 2) {
				yes &= score == 0;
				yes &= (maxv > 6 && maxv - minv == 2) || (maxv == 6 && minv <= 4);
			} else {
				yes &= (maxv == 7 && minv >= 5) || (maxv == 6 && minv <= 4);
			}
			score += A[i] > B[i] ? 1 : -1;
		}
		yes &= score != 0;
		if (p1 == "federer") {
			yes &= A.size() == score;
		} else if (p2 == "federer") {
			yes &= A.size() == -score;
		}
		cout << (yes ? "da" : "ne") << "\n";
	}
	return 0;
}
