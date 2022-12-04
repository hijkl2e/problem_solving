#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		string s;
		getline(cin, s);
		A[i] = stoi(s, nullptr, 2);
	}
	vector<ii> B{
		{0x80, 0x00}, {0xE0, 0xC0}, {0xF0, 0xE0}, {0xF8, 0xF0}
	};
	vector<int> type(4);
	bool valid = true;
	for (int i = 0; i < N && valid; ++i) {
		valid = false;
		for (int j = 0; j < 4; ++j) {
			if (i + j == N || (j && (A[i + j] & 0xC0) != 0x80)) {
				break;
			}
			if ((A[i] & B[j].first) == B[j].second) {
				++type[j];
				i += j;
				valid = true;
				break;
			}
		}
	}
	if (valid) {
		for (int i = 0; i < 4; ++i) {
			cout << type[i] << "\n";
		}
	} else {
		cout << "invalid\n";
	}
	return 0;
}
