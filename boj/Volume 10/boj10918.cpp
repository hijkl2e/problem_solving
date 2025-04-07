#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<int, string> A{
		{33080895, "0"}, {33216063, "1"}, {33087039, "2"}, {33085119, "3"}, {33218111, "3"}, {33093183, "4"},
		{33216191, "4"}, {33224255, "5"}, {33087167, "5"}, {33095231, "6"}, {33218239, "6"}, {33093311, "7"},
		{33226303, "7"}, {33224383, "8"}, {33095359, "9"}, {33226431, "10"}, {32655359, "a"}, {33084479, "b"},
		{33453983, "c"}, {33553655, "d"}, {32759327, "e"}, {33195711, "f"}, {31256381, "g"}, {33084989, "h"},
		{22609919, "i"}, {33554333, "j"}, {31389239, "kq"}, {33091131, "l"}, {33539231, "m"}, {33052223, "n"},
		{32759039, "o"}, {31358975, "p"}, {32569247, "z"}, {33211071, "r"}, {24768119, "s"}, {24696383, "t"},
		{33553973, "uv"}, {24379391, "w"}, {30990071, "x"}, {28896831, "y"}, {0, "_"}
	};
	int R{}, C{};
	cin >> R >> C;
	cin.ignore();
	vector<string> B(6 * R - 1);
	for (int i = 0; i < B.size(); ++i) {
		getline(cin, B[i]);
	}
	for (int i = C - 1; i >= 0; --i) {
		for (int j = 0; j < R; ++j) {
			string S;
			for (int k = 0; k < 5; ++k) {
				S += B[6 * j + k].substr(6 * i, 5);
			}
			int x{};
			for (int i = 0; i < S.size(); ++i) {
				x = 2 * x + (S[i] == '#');
			}
			cout << A[x];
		}
		cout << "\n";
	}
	return 0;
}
