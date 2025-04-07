#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using vi = pair<vector<int>, int>;

vector<vi> A;
vector<vector<int>> C;
vector<ii> D{
	{0, 4}, {1, 1}, {1, 3}, {1, 5}, {1, 7}, {2, 2},
	{2, 6}, {3, 1}, {3, 3}, {3, 5}, {3, 7}, {4, 4}
};

void solve1() {
	vector<int> B(4);
	for (B[0] = 1; B[0] < 13; ++B[0]) {
		for (B[1] = 1; B[1] < 13; ++B[1]) {
			for (B[2] = 1; B[2] < 13; ++B[2]) {
				for (B[3] = 1; B[3] < 13; ++B[3]) {
					if (B[0] != B[1] && B[0] != B[2] && B[0] != B[3]
							&& B[1] != B[2] && B[1] != B[3] && B[2] != B[3]
							&& accumulate(B.begin(), B.end(), 0) == 26) {
						A.push_back({B, (1 << B[0]) | (1 << B[1]) | (1 << B[2]) | (1 << B[3])});
					}
				}
			}
		}
	}
}

void solve2(vector<int> &B, int b) {
	static vector<int> A;
	A.clear();
	for (int i = 1; i < 13; ++i) {
		if (b & (1 << i)) {
			A.push_back(i);
		}
	}
	for (int i = 0; i < 4; ++i) {
		int c = b;
		B[8] = A[i];
		B[9] = 26 - B[1] - B[4] - B[8];
		B[10] = 26 - B[2] - B[7] - B[8];
		B[11] = 26 - B[0] - B[5] - B[9];
		bool flag = true;
		for (int j = 8; j < 12; ++j) {
			if (!(1 <= B[j] && B[j] <= 12) || (c & (1 << B[j])) == 0) {
				flag = false;
				break;
			}
			c &= ~(1 << B[j]);
		}
		if (flag) {
			C.push_back(B);
		}
	}
}

void solve3() {
	for (auto &v1 : C) {
		vector<int> v2{
			v1[8], v1[0], v1[1], v1[2], v1[3], v1[9],
			v1[10], v1[4], v1[5], v1[6], v1[7], v1[11]
		};
		swap(v1, v2);
	}
	sort(C.begin(), C.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve1();
	vector<int> B(12);
	for (auto &[v1, b1] : A) {
		copy(v1.begin(), v1.end(), B.begin());
		for (auto &[v2, b2] : A) {
			if ((b1 & b2) == 0) {
				copy(v2.begin(), v2.end(), B.begin() + 4);
				solve2(B, ((1 << 13) - 1) & ~(b1 | b2));
			}
		}
	}
	solve3();
	vector<string> E;
	for (int i = 0; i < 5; ++i) {
		string S;
		getline(cin, S);
		E.push_back(S);
	}
	for (auto &v : C) {
		bool flag = true;
		for (int i = 0; i < 12; ++i) {
			auto &[x, y] = D[i];
			if (E[x][y] != 'x' && E[x][y] != 'A' + v[i] - 1) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			continue;
		}
		for (int i = 0; i < 12; ++i) {
			auto &[x, y] = D[i];
			E[x][y] = 'A' + v[i] - 1;
		}
		break;
	}
	for (auto &s : E) {
		cout << s << "\n";
	}
	return 0;
}
