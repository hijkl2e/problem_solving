#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve0() {
	cout << "ONTAK 2010\n";
}

void solve1() {
	string S = "Godzilla terrorizes Bajtoly lower again. Every day a monster comes out of the ocean, slow movement of marching through the city to some of the skyscrapers and eats it with people who are in it. Eating one skyscraper takes the whole day, at dusk, it returns to its hiding place hidden in the depths. To make matters worse, going through the city, Godzilla wags its tail and destroys towers, near the passes. The prospect of becoming a meal for an underwater monster, to discourage some residents spent in uncomfort- tion in the city. During the night of each tower is derived as a resident and flees to the countryside. In Bajtogrodzie skyscrapers were built only at street crossings. At each intersection there is exactly one building. Junctions are connected by two-way streets. In addition, a the junction is just above the ocean, this is where Godzilla begins its destructive journey through the city. During the investigation, the monster moves only in the streets. Godzilla noted that he must hurry up with the consumption of residents and carefully choose the skyscrapers devouring and streets, which reaches them. Of course, choosing never previously consumed or destroyed- wanego skyscraper. What is the maximum number of people who can eat before the city completely desolate? Entrance The first line of standard input contains two integers him (1 n 100 000, 0 500 000 m) respectively denoting the number of intersections in the city and the number of connecting streets. Crossroads numbers are numbered from 1 to n, junction 1 is located on the shores of the ocean. Next row contains a sequence of integers n s (0 s 100 000) to describe population skyscrapers at various intersections. In each of the next m rows are the two integers ai and bi (1 ai, bi n, ai = bi), which means that there is a road junction connecting ai and bi. The crossing number One can reach any other intersection in the city. Exit Write to stdout the number of people who eat Godzilla for the optimum choice of meals and roads through the city every day. Example For input: the result is correct: 5 5 11 1 3 2 4 7 1 2 1 3 2 3 2 4 3 5";
	for (int i = 0; i < S.size(); ++i) {
		cout << string(2932 - i * i % 2932, S[i]);
	}
	cout << "\n";
}

void solve2() {
	const ull mod = 9099099909999099999LL;
	vector<ull> fibo(10001);
	fibo[0] = fibo[1] = 1;
	for (int i = 2; i < fibo.size(); ++i) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % mod;
	}
	fibo.back() = 0;
	for (int i = 0; i < fibo.size(); ++i) {
		cout << fibo[i] << (i == fibo.size() - 1 ? ".\n" : ", ");
	}
}

void solve3() {
	vector<string> ontak{
		".####..##..##.######..##...##..##.....####...####..###..####.",
		"##..##.###.##...##...####..##.##.....##..##.##..##..##.##..##",
		"##..##.##.###...##..##..##.####.........##..##..##..##.##..##",
		"##..##.##..##...##..######.##.##......##....##..##..##.##..##",
		".####..##..##...##..##..##.##..##....######..####...##..####."
	};
	for (int i = 0; i < 1024; ++i) {
		string S(1024 - i, '#');
		for (int j = 0; j < 1024 - i; ++j) {
			if (i & j) {
				S[j] = '.';
			}
		}
		if (505 < i && i < 511) {
			copy(ontak[i - 506].begin(), ontak[i - 506].end(), S.begin() + 449);
		}
		cout << S << "\n";
	}
}

void solve4() {
	deque<bool> p(400004, true);
	p[0] = p[1] = false;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			for (int j = 2 * i; j < p.size(); j += i) {
				p[j] = false;
			}
		}
	}
	for (int i = 0; i < 5000; ++i) {
		for (int j = 0; j < 80; ++j) {
			if (i == 3333 && j == 8) {
				cout << 9099099909999099999LL;
				j += 18;
				continue;
			}
			cout << (p[80 * i + j + 2] ? 0 : 1);
		}
		cout << "\n";
	}
}

void print(string &s, bool sp = true, bool cap = false) {
	s[0] &= ~(cap ? 32 : 0);
	cout << (sp ? " " : "") << s;
	s[0] |= cap ? 32 : 0;
}

void solve5() {
	vector<int> A{-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<string> B{
		"dwutysiecznego", "pierwszego", "drugiego", "trzeciego", "czwartego", "piatego", "szostego", "siodmego", "osmego", "dziewiatego", "dziesiatego", "jedenastego", "dwunastego", "trzynastego", "czternastego", "pietnastego", "szesnastego", "siedemnastego", "osiemnastego", "dziewietnastego", "dwudziestego"
	};
	vector<string> C{
		"", "stycznia", "lutego", "marca", "kwietnia", "maja", "czerwca", "lipca", "sierpnia", "wrzesnia", "pazdziernika", "listopada", "grudnia"
	};
	vector<string> D{
		"", "pierwszy", "drugi", "trzeci", "czwarty", "piaty", "szosty", "siodmy", "osmy", "dziewiaty", "dziesiaty", "jedenasty", "dwunasty", "trzynasty", "czternasty", "pietnasty", "szesnasty", "siedemnasty", "osiemnasty", "dziewietnasty"
	};
	vector<string> E{
		"", "", "dwudziesty", "trzydziesty", "czterdziesty", "piecdziesiaty", "szescdziesiaty", "siedemdziesiaty", "osiemdziesiaty", "dziewiecdziesiaty"
	};
	vector<string> F{
		"", "sto", "dwiescie", "trzysta"
	};
	vector<string> G{
		"", "setny", "dwusetny", "trzysetny"
	};
	for (int i = 0; i < 21; ++i) {
		int cnt{};
		for (int j = 1; j <= 12; ++j) {
			for (int k = 1; k <= A[j]; ++k) {
				if (i % 4 && j == 2 && k == 29) {
					continue;
				}
				++cnt;
				if (i == 7 && j == 4 && k == 1) {
					cout << "Pierwszego kwietnia jest prima aprilis.\n";
					continue;
				} else if (i == 13 && j == 6 && k == 1) {
					cout << "Pierwszego czerwca jest dzien dziecka.\n";
					continue;
				}
				if (k < 20) {
					print(D[k], false, true);
				} else {
					print(E[k / 10], false, true);
					if (k % 10) {
						print(D[k % 10]);
					}
				}
				cout << " " << C[j] << " to";
				int x = cnt / 100, y = cnt % 100;
				if (y) {
					if (x) {
						print(F[x]);
					}
					if (y < 20) {
						print(D[y]);
					} else {
						print(E[y / 10]);
						if (y % 10) {
							print(D[y % 10]);
						}
					}
				} else {
					print(G[x]);
				}
				cout << " dzien roku " << (i ? "dwa tysiace " : "") << B[i] << ".\n";
			}
		}
	}
	cout << "Koniec.\n";
}

void solve6() {
	vector<ll> fact(21);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); ++i) {
		fact[i] = i * fact[i - 1];
	}
	for (ll i = 1; i < 20001; ++i) {
		ll x = i * i * i * i;
		cout << "T[" << x << "]=\"";
		if (i == 10000) {
			cout << 9099099909999099999LL << "\"\n";
			continue;
		}
		int L = 1;
		while (x > fact[L]) {
			x -= fact[L++];
		}
		vector<char> A(L);
		for (int j = 0; j < L; ++j) {
			A[j] = j + 'a';
		}
		while (L--) {
			ll y = (x - 1) / fact[L];
			cout << A[y];
			A.erase(A.begin() + y);
			x -= y * fact[L];
		}
		cout << "\"\n";
	}
}

struct BigInteger {
	BigInteger(int x) : A(1, x) { }
	BigInteger(string &s) : A(s.size()) {
		for (int i = 0; i < A.size(); ++i) {
			A[i] = s[i] - '0';
		}
	};
	void twice() {
		A.push_back(0);
		for (int i = 0; i < A.size(); ++i) {
			A[i] *= 2;
		}
		for (int i = 0; i < A.size(); ++i) {
			if (A[i] >= 3) {
				A[i] -= 3;
				++A[i + 1];
			}
		}
		if (A.back() == 0) {
			A.pop_back();
		}
	}
	vector<string> to_string() {
		int sz = 7 * A.size() - 3 * count(A.begin(), A.end(), 1);
		vector<string> ret(5, string(sz, '.'));
		for (int i = 0, p = 0; i < A.size(); ++i) {
			int x = A[i];
			for (int j = 0; j < 5; ++j) {
				copy(B[x][j].begin(), B[x][j].end(), ret[j].begin() + p);
			}
			p += x == 1 ? 4 : 7;
		}
		return ret;
	}
	vector<int> A;
	static vector<vector<string>> B;
};

vector<vector<string>> BigInteger::B{
	{".####.", "##..##", "##..##", "##..##", ".####."},
	{"###", ".##", ".##", ".##", ".##"},
	{".####.", "##..##", "...##.", ".##...", "######"},
	{".####.", "##..##", ".#####", "....##", ".####."}
};

void solve7() {
	vector<string> A(5, string(1000, '.'));
	BigInteger x(1), y(0);
	for (int i = 0, p = 0; i < 173; ++i) {
		vector<string> B = i == 171 ? y.to_string() : x.to_string();
		if (p + B[0].size() + 2 > 1000) {
			for (int j = 0; j < 5; ++j) {
				cout << A[j] << "\n";
				A[j] = string(1000, '.');
			}
			cout << string(1000, '.') << "\n";
			p = 0;
		}
		for (int j = 0; j < 5; ++j) {
			copy(B[j].begin(), B[j].end(), A[j].begin() + p);
		}
		p += B[0].size();
		A[3][p] = A[3][p + 1] = A[4][p + 1] = '#';
		if (i == 171) {
			A[4][p] = '#';
		}
		p += 6;
		x.twice();
	}
	vector<string> B{
		"01020102001020021020001020010200120000120001200102010200120120012001200102012001020102012001020102010102010201200120012012001220100200012002010201020102010200",
		"120012012001200120012001200120012001200120012012001201002000102001201200020020010020102001200001020102000120002010200102020000102001202002102001200202010201",
		"0201020010020201020201020200120010001200201200102012001200120102012002100002010200010200012022020012020102020102020102010303303330333303333302010200120012",
		"0012010201020102012001201201020120102012002001020012001200120012000120012001200210200120000120012001201200120102001001001001010100101000020102010200102001020001"
	};
	for (int i = 0; i < B.size(); ++i) {
		cout << string(1000, '.') << "\n";
		x = BigInteger(B[i]);
		A = x.to_string();
		for (int i = 0; i < 5; ++i) {
			cout << A[i] << string(1000 - A[i].size(), '.') << "\n";
		}
	}
}

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

void solve8() {
	string A = "Yopyzzs00989:9GFGGPOPPPPXXXXYYYhgZhhhhhipppiqqqyyyyzyzzzzszs777s000088881991999:9F9FFFF:GGGGGOOOOHPOPPPPPPPPQPQXXXXQYQYYYgYZZZZhghZhhYgghpqqqrihhhghhhiqrzzzzrqqhiiiqyzs77sszzqryqrzz7000180zzzzzzzs08199999100s070899FF::G9919888899F:GOOOOGG9F99F9FGGOPPPXPPOHGGGGGHPPPQQYQYXPPPOPOPOPXPYYYZhggYYQQXPQXQYYhhhhphhhhZZZYgYgghgihqpqqiqhphZhhhhhhppqqyyzyrrrqqiiiiqqqyzzzzszsz7yzrryyyyyrzzs77000007zszzzz7zzs700881998988000070008899F9F9::9:998198819199F9GFGGGGOG:::9:9F9FFFFGGPOPOPPPOPOOGHGGGGOGPOPPXPQXXXXPQPPPPPOPOPPPPPXPYYYYYZgYYYQQQXXPQQYXYggZhhhhhZhhhZZZZYZYZggghghhiphqppiiiihihhhhZhhhhphpppqqqrrrryyqqqiqppppqpqyyyzyzzzszzzzzzyrrrrrrrrzyzr7zzsss07s0ssssszzszzzz7zzsss00088881198010000s00000819999999:99:999989819881919999:9::G:GGGGF:G9::9:9F9F9:FF:GGGHHPOHPHPOHHHHGGGGOGGOGHPOPPPPPPQPQXPXPPQPPOPPOPHPPOPPPPQPQQYXYYYYYYYYQQQQQXPQQXXQYQYYZZhghghZhhZhZZhgYZgYYZgYZZhghhhhhhiphiipphiphhhhhhhhhhhhhhhhippppqqqqqryqqqqqqpiiiiqpiqqqqrrzyzrzzzzzrzzzyzyyrryyyyyyyrzyzzzz7z77zss07777zs7zzszzzzzszzzszsss0700080111880100000s0700000019891999999999999998981981198191999999:F9:GFF:GF:GFFFF9:9:9F99:9:F9::GFGGGGHHHHPOOOOOOGHGGGGGGGGHGHHHHPHPPPPPPPQPPXPPPPPPPPPHPPOPOPOPPHPPPQPXPQQQQYQYYYXYQYQQQQQXXPQXPQQXXQQYYYYgYZhgZhgZhgZhggggYZgYYZYZYZZZZZhZhhhhhhhihphihihihhihhhhhhhghhhhhhhhhhphppppiqiqqqqqqqqqqpiiqpppppppiqiqqqyqrzyrzyzrzzyzrzrzyrrrrrrryyqrrrzyrzrzzzzz7zzs7zs77zss7z7z7zzzszzzzzzzzszz7zs7777s000000808001000007s0707070000888889898999199999899898198111988198191999999F9F9:FFFFFFFFFFF9::9:9:9F99F99:9:9:FFFF:GGGGGGHHOOGHHOGHGHGGGGGGGGGGGGHOOOOHPOPPHPPPPPPPPQPPPOPPPPOPOPOPOPOPOPOPPPPPPPPXPQXXPYXXQQYQYXXQQQQQQXXPQPQXPQXPQQQQQYQYYYYgYZZZZZhggggggggYZYZYgYYgYYZgYZZZZhZhZhhhhhhhhihhhihhphhhhhhhhhZhhhZhhhZhhhhhhphhiphiiiiqpqiqqiqqiqiqpiiiiiiiiippppiiqiqqqqqryyyrrzyrzyrzyrzyrrrrrryyqryqrryyyyyrzyzrzzzzzzz7zzszszszszszszzszzzzzzzzzzzzzz7zzz7z7zs7777s070000000000000707s077s07s070000008888819819989199891919819811111988888198191999999999:9F9:F9:FF9::F9:F9:9F99:999:99F99F99:9::FFFF:G:GGGGGGHGHOGGHGGHGGGGG:GG:GGGGGGGOGHHHPOHPHPPOPPPHPPPPPPOPPHPPOPOPOHPOHPOPOHPPOPPOPPPPPQPPQXPQXXXPQYXXXXXXXXPQQXPQXPQPQPQPQXPXXPQQQQQYXYYYYYYgYZggYZZZggYZgYgYYgYYYYYYZYYZgYZZZZhgZhZhhZhhhhhhhhhhhhihhhhghhhhZhhZhhZhhghhZhhhhhhhhhihphpphiiiiqpiqpiqpiqpiiiiiiiiipphiippppppppiqpqqqqqqryyyyyyyyyrrrzyyyyqrryqryqrqryqryqrrrrzyrzyzrzzzzzzzzzzszz7zzzszz7zzzzzzzzzzzzzzzzyzzzzzzszzzszszs77777s07s00700070070s07s077sss0777ss0707000000801111988198191981981981111111111111111111981919919999999:99:9F9F9F9:9:9:9:9F99F9999:99999F9999:99:9:F9:FFFF:GFGFGGGGGGGGGGGGGGGGG:GGFGF:GGFGGGGGGGGHOOOOHHPOPOHPPOPHPPHPPOPHPHPHPOHPOHPOOHPOOHPOHPHPHPPPHPPPPXPPPQPQPQXPQXXPQQXXPQQXPQXPQPQPQPXPPQPXPXPXPXPQXPQQQQYXQYYYYYYYYYZYZYZgYgYYZYYYYYYYYYYYYYYZYgYgYZZZZhgghghghZhhhZhhhhhhZhhhhhZhhhghhghghZhZhZhZhhghhghhhhhhhhhphhihipphiiiiiiiiiiqppppppphiipphiphiphipphiippppppiqpqqqqqqqqryyqrryyyyqrrryqrrqrqrqrqyqqrqrqryqrrrrrrzyrzrzzrzzzzzzzzzzzzzzzz7zzzzzzzzzrzzzzzyzzzrzzzzzrzzzz7zzzzsz7zs7zss77sss07s0707s0707ss077sssssssssssssss077s0s000000001888888888111988111198880111880118801188888119819199899999999999F999:99:99:99:999:9999999:9999999999999:99F9F9F9:FF9::GFF:G:GG:GGG:GGGGFGGFGFGF:GF:GF:GF:G:G:GGGGGGGGHOOOOOOOOHPOHPOHPHPHPOPOHPOHPOOHHPOOOHHHHHPOOOHPOHPOPOPOPPPHPPPPXPPPXPPQPXPXPQPQXPQPQXPXPXPPQPXPPXPPPQPPXPPXPPQPXPXPQXXPQQQYXXQYYXYYYYYYYYYYgYYYYYYYYYYYYYYXYYQYYYYYYYYZYZZgggggZhgZhghghZhhghhghhghhghhghZhZhZhghgZhghgZhghghghghZhhhhghhhphhhhihphphiphipphiiippphiipphipphphiphphihiphphihipphiippppiiqpqpqqqqqqqqrqryqrqryqrqrqrqrqqyqqqqyqqqqrqyqyqryyyyyyyrrzrzyzrzzzyzzzzrzzzzzzzzzzrzzzzzyzzzyzzyzzyzzyzzyzzzyzzzzzzzzzz7zz7z7z7zs777zsss07777sss07777ssssss7777zss777zsss777777s07s07000000001801880111111188888011801180801808018011888098881981919989998999999999:99999F999999999F9919999999999991999999:9999F99F9F9F9::FFFFFF::GF:GFGFGFGFGF:G:GF::GFF::GFFF:::GFF:GFGFGFGGGGGGGOGHOOOGHPOOOOHHPOOHPOOHHPOOOHHHHHHHHHHHHOOOOOOOOOHHPOOPOHPHPPOPPPPOPPPXPPPPPQPPQPPQPXPPQPXPPXPPXPPPQPPPPQPPPPPXPPPPXPPPXPPQPXPXPQXXPQQQQYXXQYQYYXYYYXYYYYYYYXYYYXYYXYXYXYXYXYQYYXYYYQYYYYgYZYZZZgggZZhggZhghgZhZhZhZhZhghghgZhgZhgZhgZZhgZZhgZZhgZhZhghghZhhZhhhhhhhhhhphhhihphphihiphihiphiphiphphihihihihphhihihphhihihihiphipphiiiiiqppqpqpqqqqqqqqqqqrqqrqqyqqqqqqrqqqqqqqqqqqqqqqyqyqryyqrrzyyyrzyzyrzzyzrzzrzzzyzzzyzzrzzrzzrzzyzrzrzzyzyzyzyzyzrzzrzzzyzzzzzzzzzzzszzszszszs7zss777zssss77777zsss777zs77zs7zs7zs7zss7zss77zsssss077s0s00s000000808010180188018018080101010800108001010180118888881198191919919998999999999899999999999999989999199998999199999199999999:999F99F9F9:9::FF9::::::GFFF::GF::GFF:::GFFFFFFFFFFFFFFFFFFFFF::GFFGF:GG:GGGGGGOGOGHOGHHHHOOOOOOOOOOOOOOOOOOGHHHOOGHOOGHHOOGHHHOOOOOHHPOOHPHPOPHPPHPPPPPPPPPPPPPPPXPPPPPQPPPXPPPPPXPPPPPPPPPPPPPPPPXPPPPPPPPPXPPPXPPXPXPXPQXXPQQQQQQQYXQYXQYQYQYYXYXYQYQYQYQYXYXQYXQQYXQYXQYXYXYXYXYYYYYYYYYZYZgggYZZZhgggZZhggZhgZhgZZhgZZhgZZhgggZZZZZhgggggZZZhggZhggZhZhZhZhhZhhhhhghhhihhhhhihhphhihphhihihihphphhihphhphhphhhihhphhhihhphhphhihihihiphiippppppppiqpiqiqqqpqqqqqqqqqqqqqqqpqqqqpqqiqqiqqqpqqqqqqqqqqyqyqryyyyyyyyyrzyrzyrzrzyzrzrzrzzyzyzyzrzrzyzyzyrzyzyrzyrzyzyrzyzyzyzyzzyzzyzzzzzzzzzzzz7zzzsz7z7z7zs7zs7zs7zs7zss7zs7zs7zszs7z7zszszs7z7z7zszs7zs7zss777zss077s07s0s0000000000001080010108008000100080000001000108080801888888888119819191998919998999899998999199998991991991991998998998998999899999999999999:99:9F9F9F9:F9::FFF9:::::::::::::::FFFFFF9:::FF9::FF9:::FFF9:::::::GFF:GFGFG:GGGGGGGGOGOGHOGHOGHHOGHHOOGHOOGHOGHOGHGHOGOGHGHOGHOGHOOGHHHOOHHHHPOHPOHPHPPOPPOPPPHPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPOPPPPPPPPOPPPPPPPPPPPPPXPPPPQPPQPQPQPQXPQQXXXXXXXXXQQQYXQYXXQYXQYXQQYXQQYXXQQQYXXXXQQQYXXXQQYXQYXQYQYYQYYYYYYYgYgYggYZZgggggggggggggZZZZZhggggggggggggYZZZZZZggggggggggggZZhggZhghghghghhghhhZhhhhhhhhhphhhhhihhhihhhihhphhhphhhhihhhhphhhhhhihhhhhhihhhhphhhihhihphphphiphiippppppppiiqpqpiqiqqpqqpqqpqqpqqpqiqiqqpqpiqiqiqiqiqiqqpqqiqqqqqqqqrqryqryyyqrrzyyyrrzyyrzyrzyrzyrzyzyrzyrzyrrzyrrzyrrzyyrrzyrrzyrzyyzyrzyzyzrzzyzzyzzzzzzzzzzzzzzszz7zz7zzszszszszszszszszszszszsz7z7zzsz7zzszzsz7z7zzszszszszs7zs77zssssssss07s07070s0000s0000000000001000000000000000000000000000080801801118881119881981919191919989199891998998989191998989898989898989898919989989998999999999999:999:9F9F9F9F9:9:FF9:F9::FF9:FF9::FF9:F9::F9:F9:F9:F9:9:F9::F9:FF9::FFFFFFFF::GF:G:G:GGGGGGGGGGGGHGOGOGOGHGHGHGHGHGHGOGGHGGHGOGGOGGHGOGOGOGHOGHOOOOGHPOOOHHPOHPOPOPOPHPPHPPPOPPPHPPPPPPOPPPPPPOPPPPPOPPPPOPPPOPPPOPPPOPPPOPPPPHPPPPPPPPPPPPPPQPPPQPPQPQPQPQXPQQXPQQQQXXXXXXXXQQQQQQQYXXXXXXXXXXXXXXXXPQQQQQQQQQXXQQQQQQYXXQYXYXYXYYXYYYYYYYgYgYgYZgYZZgYZZZgggYZZZgggYZZZggYZggYZggYZgYZggYZZggYZZZZZZZZZhggZhgZhghghghZhhhghhhhghhhhhhhhhhhhhhphhhhhhhhhhihhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhihhhhhihhphhphphphphiphiippppppppppiiqpiqpiqpiqpqpiqpqpiqpiqpiqpiiqpiiqpiqppiqpiqiqpqpqqpqqqqqqqqqqrqryqryyqrrrrrrrrrzyyyrrrzyyyrrzyyyrrrrzyyyyyyrrrrrrrrrzyyyyyrrzyyrzyyzyrzyzyzrzzrzzzrzzzzzzzzzzzzz7zzzzszzzszzszzszzszzszzszzszz7zzz7zzzszzz7zzz7zzz7zz7zz7zz7z7zzs7z7zs7zss7777z07777s07s07070700700s00007000s000s00070070070s00s00s000s000000000808080188011111119881198198198191981919198981989819898198198198198198198981919898919989919999899999999F9999F999:9F99:9:9:9:9:F9F9:F9F9:9:F9F9:9:F9F9F9F9F9F9F9F9F9F9F9:9:F9:F9:F9::FFFFFFFFF::GF:GFG:GG:GGGGGGGGGGGGGGHGGGHGGGOGGGGGGHGGGGGGGGGHGGGGOGGOGGHGHOGHOOGHHHHHHHPOOHHPOHPHPOPOPOPHPPOPPOPHPPPOPPOPPOPPOPPOPPOPHPPHPPOPHPPOPHPPOPHPPHPPHPPPHPPPPPPHPPPPXPPPPPPQPPXPPQPXPXPQPQXPQXXPQXXPQQQXXXPQQQXXXPQQXXXPQQXXPQQXPQQXXPQXXPQQXXXPQQQXXXXXXQQQYXQYXQYQYYQYYYYYYYYYYgYYZYZgYgYZgYgYZgYZgYgYZgYgYgYZYZYZYZYZYZgYgYZgYZgYZZgggYZZZhgggZZhgZhgZhZhhghghhghhZhhhhhghhhhhhhZhhhhhhhhhhhhghhhhhhhhghhhhhhghhhhhhghhhhhhhhhZhhhihhhhhhhphhhihhihphphihiphiipphiiippppppiiiiqpppiiiqppiiiqpppiiiiiqpppppppiiiiiiqpppiiqppiqpiqpqpqqpqqqqqqqqqqyqyqyqryyqrryyyqrrrrrrryyyyyyyyyyqrrrrryyyqrrryyyyqrrrryyyyyyyyyyrrrzyyrzyrzyzyzyzrzzyzzrzzzzzzyzzzzzzzzszzzzzzz7zzzzz7zzzzzzszzzzzzszzzzzzzzszzzzzzzzzszzzzzzszzz7zzzsz7zzsz7zszs7zs77zss7777777sss07s07s07s0s0s0s0s0s0s0s0s0s0707s0s0707s0707s0s0s0s0s00s0000000000001018018801118888811119881198811981198119811988119881119881119881198819881981989819191998998999899999999999999F9999:99F99F99F99:9F99:9F99:9F99:9F99:99:9F99F99F99F99:99:9F99:9:9:9:9:F9F9::F9::FFFFFFFF::GFFGF:G:G:GG:GGGGFGGGGGGGGG:GGGGGGGGFGGGG:GGGGGFGGGGGGGGGGGGGGGOGOGOGHOGHHOOOOOOOOHHHPOHHPOHPHPOHPHPHPHPHPHPHPHPHPHPHPHPHPOPOPOPOHPHPOPOPOHPHPHPHPHPHPHPPOPPOPPHPPPPHPPPPPPPPPPPXPPPPQPPXPPQPXPXPXPXPQPQXPQXPQXPQXPQXPQXPQXPXPQXPQXPQPQXPQPQXPQPQXPQXPQXPQXPQQXXPQQQQQQQQQQYXXQYXYXYXYQYYYYYYYYYYYYYYYgYYgYYZYYZYgYYgYYgYYYZYYgYYYgYYYZYYZYgYgYgYgYZgYZgggYZZZZZZhggZZhgZhghgZhZhZhhghZhhZhhhghhZhhhZhhhZhhhZhhhZhhhZhhhghhZhhZhhhghhZhhhghhhghhhZhhhhhhhZhhhhhihhhhhhihhphhphhihihiphihiiphipphiiippppphiiiiiiiippppppphiiiiipppphiiiipppphiiiiiiippiiiiiiqppiqpiqpqpqiqqqqqqqqqqqqqrqyqrqryqryqryqryyqryqrryqryyqryqryqryqryqryqryqryqrryyqrrryyyyyyyrrrzyyrzyrzyzyzyzyzrzzyzzzyzzzzyzzzzzzzzzzzzzzyzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzyzzzzzzzzzzszzzzzzz7zzzzszzsz7zzszszs7zs7zss77zsssssssssss077ss077ss07s077s077s077ss077ss077ss077ss07ss07s07s07s0s0070s0000000000080018088018801118888888888888881111111111111111111111111111111119888881119881988191989898989199199998999999999999999999:9999F9999:999F999F9999:999:9999:9999:9999:9999:999F999F999:99:9F99:9:9:F9F9:F9::FFF9::::::GFF::GF:GF:G:G:G:GGFG:GGFG:GGFGGFG:GGFGFG:G:GGFGFG:GGFG:GGGFGGGG:GGGGGGGHGOGOGOGHOOGHHOOOOOOOOHHHPOOHHPOOHPOHPOHPOHPOHPOHHPOHPOHPOHPOOHPOHPOOHPOHPOOHPOHPOHPHPOPOHPHPPOPOPPOPPOPPPPOPPPPPPPPPPPPPQPPPPQPPXPPXPPQPXPPQPQPXPXPXPXPXPXPXPPQPQPQPQPXPXPPQPQPXPXPPQPQPQPQPQPQPQXPXPQXPQXXPQXXXXPQQQQYXXXQQYXQYQYQYYXYYXYYYYYYXYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYgYYYYYYZYYZYgYgYgYZgYZZgggggggggggZZhgZhgghgZhghghghghghghghZhhghZhZhhghZhhghghZhhghghZhZhZhhghghZhZhhghZhhghhghhZhhhZhhhhhhghhhhhhhihhhhhphhhihhihphphhiphphihiphiphiiphipphipphipphipphiphiiphipphiphiphiiphipphipphiipphiiiiiiiiiiiiqppiqpiqpqpqiqqqiqqqqqqqqqyqqyqqyqyqqrqrqrqrqrqrqyqyqyqqrqrqyqqrqrqyqyqyqyqrqryqryqrryyyyqrrrzyyyyrrzyrzyrzyzyzyzyzrzzyzzyzzrzzzrzzzzyzzzzrzzzzzrzzzzzyzzzzrzzzzzyzzzzyzzzrzzzzzyzzzzzrzzzzzzzzzzzzzzzzzzszzzzszz7zzsz7z7z7zszs7zs77zss77zssssss777777777sssssssssssss077777777777777777777777777ssss077s07s07s0s0s00700000000000080010180101180188011880111880111880111880118801880118801118880111111111119888119819819198989199891999199991999999999999999999999999999:99999999999999F9999999999999999999F99999999:9999:999:99:99:9:9:9:9:F9:F9:FF9::::FFFFF::::GFF::GF::GF:GF:G:GF:GF:GFGF:GF:GF:GF:GF:GF:GF:GF:GFGF:G:G:GGFG:GGGGG:GGGGGGHGGHGHOGOGHHOGHHHOOOOOOOOOOOOHHHHPOOOOHHHPOOOHHHPOOOOHHHHPOOOOHHHHPOOOOHHHPOOHHPOOHPOOHPOHPHPOPOPOPOPHPPHPPPHPPPPPHPPPPPPPPPPQPPPPPPQPPPXPPPXPPPQPPXPPXPPPQPPQPPQPPXPPXPPPQPPXPPPQPPXPPPQPPQPPQPPQPXPPQPXPXPXPQPQXPQXPQXXPQQXXXXXXXXXXQQYXQQYQYXYXYXYXYQYYQYYYXYYYXYYYXYYYXYYYXYYQYYYXYYQYYYXYYYQYYYYYYYYYYYYYYYgYYZYZgYZgYZZgggYZZZZhggggZZhggZhgZZhgZhghgZhgZhZhghgZhghgZhghgZhghgZhghgZhgZhZhgZhghgZhZhghghghghghZhhghZhhhghhhghhhhhhhhZphhhhhhhhhihhhihhphhihphhihihphphphihihiphphihiphphihiphphphihihiphphphihihiphphiphphiphiphiphiipphiiiiiiiiiiiqppiiqpiqiqiqqpqqiqqqqqqqqqqqqqqqqqqyqqqqrqqqqrqqqqyqqqqqyqqqqyqqqqrqqyqqrqyqyqyqryqryyqrrryyyyyyrrrzyyrrzyrzyzyrzrzyzyzrzrzzyzrzzrzzyzzyzzyzzyzzyzzyzrzzrzzrzzrzzyzzyzrzzrzzrzzrzzzyzzrzzzrzzzzzrzzzzzzzzzzzzzzszzzz7zzzszzsz7z7z7z7z7zs7zs7zs7zss7zss77zss777zss777zss777zss777zss77zss777zss777zsss77777zssssss07777ss07s07s0s0s0070000s00000008008001080801010180101801018010180101808010180801808018018011801118888888888881119819819819191919199899899199919999199999998999999991999999999919999999998999999998999999999999999999999999999:999F999:99:9F9F99:F9F9:F9:F9::FF9:::::FFFFFFF::::::GFFFF:::GFFF:::GFFF::::GFFF::::GFFFF:::GFF::GFF:GF:GF:GFGFGFGGFGGGFGGGGGGGGGHGOGOGOGHOGHOGHOOGHHHOOOGHHHHHOOOOOOOGHHHHHHHOOOOOOGHHHHHOOOOOOGHHHHHHHHHHHHPOOOOHHPOOHPOHPOHPOPOHPPOPOPHPPHPPPHPPPPHPPPPPPPPPPPPPPPPPPPPXPPPPPPPXPPPPPPXPPPPPPQPPPPPPQPPPPPPXPPPPPPXPPPPPPQPPPPXPPPXPPPXPPXPPQPXPPQPQPQPQXPQXPQXXPQQXXXXXXXXXXXXXQQYXQQYXQYXQYQYXYXQYQYQYQYQYXYXYXYXYXYXQYQYQYXYXYXYXYXYXYQYQYYQYYYXYYYYYYYYYYYYYZYgYgYgYZggYZgggYZZZZZZZZZhggggZZZhggZZhggZZhgZZhggZhggZZhggZhggZZhggZZhggZhggZZhgZhggZhgZhgZhghgZhZhZhZhhghZhhZhhhZhhhhhghhhhhhhhhhhhphhhhhhihhhihhphhhihhihphhphhihphhihphhihphhihhihphhihphhihhihphhihphhihihphphphphphphiphihiiphipphiiiipppppiiiiqppiqpiqpqpqpqiqqpqqiqqqqpqqqqqqpqqqqqqqqiqqqqqqqiqqqqqqqqiqqqqqqqqqqqqqqyqqyqqrqrqryqryqrryyyqrrrrrzyyyyrrzyyrzyrzyrzyrzrzyzyrzrzrzyzyzyzyzyzyzyzyzyzyzyzyrzrzrzrzrzrzrzrzrzrzrzrzzyzrzzyzrzzrzzzyzzzrzzzzzzzrzzzzzszzzzzzzszzz7zz7zz7zzsz7z7z7z7z7zszs7zszs7zs7zs7zszs7zs7zs7zs7zs7zs7zszs7zs7zs7zs7zs7zs7zs77zs77zss777zssssssssss0777s07s07s0s0s00s0000700000000000010080001001080080080080080080080080080010800101010180801880188011111111111988119819819819191919199891998998998991999899199919991999899989998991999199919998999899919999989999991999999999999F999999:999:99:99:9:9F9F9:9:F9:F9:F9:FF9::FF9:::FFFF9:::::FFFFFFF9:::::::FFFFFF9::::::FFFFFFFFFF9::GFFFFFFF:::GFF:GF:GF:G:G:GGFGG:GGGGGGGGGGGGHGOGGHGHGHOGOGHOGHOGHOGHOOGHOGHOOGHOGHOOGHOGHOOGHOGHOOGHOGHHOOGHHOOOGHHHHHHHHHHHHPOOOHHPOHPOHPOHPHPHPHPHPPOPPOPPOPPPOPPPPHPPPPPPPHPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPOPPPPPPPPPPPPPPPPPPPQPPPPPPPPPPQPPPPXPPPXPPXPPXPPQPQPQPQPQXPQXPQXPQQXXPQQQQQXXXXXQQQQQYXXXQQQYXXQYXXQQYXQQYXQQYXQQYXQQYXXQYXXQYXXQYXXQYXQYXQYXQYXYXYXYXYQYYQYYYYQYYYYYYYYZYYZYZYZYZgYZggYZgggYZZZgggggggggggggggggggggggggZZZZZZZZZZZZZZZZhggggggggggZZZZZhgggZZhggZZhgZhgZhgZhghgZhhghghZhhghhZhhhZhhhhhZhhhhhhhhhhhhhhhihhhhhhphhhhhihhhhihhhphhhhihhhihhhphhhhihhhphhhhihhhihhhphhhphhhihhphhphhihhihihphphphphiphphipphipphiiiiippppiiiiqppiiqpiqpiqpqpiqiqqpqpqpqiqqpqiqqpqqpqiqqpqiqqpqiqqpqiqqiqqiqqiqqqiqqqqqqqqqqqqqqqqrqyqyqyqryqryqrrryyyyyyyyyyyyyrrrzyyrrzyyrzyrrzyrzyrzyyrzyrzyrzyrzyrzyrzyyrzyrzyrzyrzyrzyrzyrzyzyrzyzyrzrzrzrzrzzyzrzzrzzrzzzzyzzzzzrzzzzzzzzzzszzzzzzszzz7zzzszz7zzszzsz7z7zzsz7z7z7zzszszszszszsz7z7z7z7z7zzszszszszszsz7zszszszszs7z7zs7zs7zs7zs77zss77zssssssssss077ss07s07s0s0s0s00700s0000070000000000000000000000000000000000800000000100001001001010101808011801118888888881111981198198898198981919191919191998989191998919199891998989199891919989199891998919919989919998999899991999999999999999999:9999:999:99:9F99:9F9F9F9F9:9:F9:F9:F9:F9:F9:FF9:F9::F9::F9:FF9:FF9:FF9:FF9:F9::FF9:FF9::FF9::FF9::::FFFFFFFFFFF:::GFF:GF:GF:G:G:GGFGG:GGGGGGGGGGGGGGGHGGHGGHGOGOGGHGHGHGOGOGOGOGOGGHGHGHGHGHGHGOGOGHGHGHOGOGHOGHOGHOOGHHOOOGHHHHHHHPOOOOHHPOHPOOHPHPOHPHPHPHPPOPHPPOPPOPPOPPHPPPHPPPPHPPPPHPPPPHPPPPPHPPPPPOPPPPPOPPPPHPPPPPHPPPPPHPPPPPPPOPPPPPPPPPPPPPPPPPPPPPPPQPPPPXPPPXPPXPPQPXPPQPQPQXPXPQXPQXPQQXXPQQXXXPQQQQXXXXXXXXXXXXXXXXXXXXXXQQQQQQQQQQQQQQYXXXXXXXXXXXQQQQQYXXXXQQYXXQQYXQYXQYXYXYXYXYQYYYQYYYYYYYYYYYYZYgYYZYZgYgYZgYZgYZgYZZggYZgggYZZggYZZgggYZZgggYZZggYZZZggYZZZgggYZZZZgggggggggggggggggZZZhggZhggZhgZhZhghgZhhghghZhhghhZhhhghhhhghhhhhhhZhhhhhhhhhhhhhhhhhhphhhhhhhhhhhhhhhphhhhhhhhhhhhhhihhhhhhhhhhhphhhhhhhphhhhhphhhhphhhihhphhihhihihphphihiphiphiphipphiiippppppppppppiiiqpppiqppiqppiqpiqpiqpiqpqpiqpiqpiqpqpiqpiqpiqpqpiqpqpiqpqpqpqpqpqpqiqqqpqqqiqqqqqqqqqqyqqyqyqyqyqryqryyqrryyqrrrrrrrrrrrrrrrrzyyyyyrrrrzyyyrrrzyyyyrrrzyyyrrrzyyyrrrzyyyrrrzyyrrzyyrzyyrzyrzyrzyrzyzyzyrzrzzyzrzzyzzyzzrzzzzrzzzzzzzzzzzzzzzzzzzzzz7zzzzzszzzzszzzszz7zzzszz7zz7zzzszzszzszz7zz7zzzszzszzszz7zz7zz7zzszzsz7zzsz7zzszszszszszs7z7zs7zs77zs77zssss77777777sss077ss07s0707s0s0s0s0070s00s000700s000s000s000s000s000s000s0000700000700000000000000080080808080801880188801111111111198881198";
	vector<string> B(1000, string(1000, '.'));
	int x = 499, y = 499;
	for (char c : A) {
		int z = c < 'A' ? (c - '0') : c < 'a' ? (c - 'A' + 12) : (c - 'a' + 38);
		x += dx[z % 8], y += dy[z % 8];
		B[x][y] = '#';
		x += dx[z / 8], y += dy[z / 8];
		B[x][y] = '#';
	}
	for (auto &s : B) {
		cout << s << "\n";
	}
}

void solve9() {
	vector<int> A{
		2,544,3,443,13,488,3,48,15,636,5,875,22,506,5,764,24,146,5,845,27,388,3,117,38,296,5,208,39,840,5,612,42,76,5,330,42,408,5,153,46,258,5,65,47,790,3,213,48,0,3,20,54,398,5,62,55,703,3,231,62,96,5,175,63,854,3,149,64,0,3,297,65,428,5,751,66,246,5,279,67,636,4,10,69,824,5,303,70,50,4,832,71,432,2,45,75,56,2,55,77,856,5,723,80,70,3,864,83,124,5,506,90,396,5,43,91,612,5,818,91,642,4,258,98,84,4,371,99,506,3,6,103,736,5,124,106,202,5,44,106,590,4,413,108,827,4,176,109,670,5,93,112,674,5,658,121,898,5,419,124,678,3,325,125,0,3,913,125,838,2,4,128,454,3,7,129,484,5,708,131,682,2,131,131,707,4,95,135,680,3,131,135,734,5,264,141,872,3,117,143,362,3,198,149,816,5,502,150,620,4,203,154,916,4,87,157,428,3,511,158,198,5,428,160,734,2,4,163,328,5,264,167,611,3,311,173,978,4,25,175,978,3,25,176,0,3,315,177,696,5,302,179,956,5,759,180,122,5,791,182,347,3,271,188,374,3,203,193,178,2,30,194,370,2,4,195,24,5,550,201,470,4,468,202,0,4,334,205,767,3,137,207,564,5,764,208,236,5,487,212,676,4,30,218,780,5,426,227,302,3,236,229,348,5,294,230,556,4,447,238,84,3,164,242,238,4,186,245,0,4,46,256,756,5,323,257,724,3,279,258,0,3,222,260,215,4,629,261,356,3,602,264,760,5,57,268,874,3,40,278,345,3,109,281,0,2,56,282,570,5,514,282,824,4,4,283,454,5,627,283,552,3,347,283,823,4,4,288,0,4,408,288,822,2,74,289,318,2,160,289,401,4,415,291,639,2,193,292,0,2,234,294,0,2,152,297,192,5,187,298,670,3,333,299,0,3,183,301,338,4,148,302,274,5,570,305,292,4,568,306,312,4,127,306,580,4,150,307,102,5,457,312,326,5,385,314,197,3,3,321,332,5,557,324,887,3,116,325,0,3,340,325,450,5,622,326,326,2,4,329,404,2,258,345,810,5,563,352,839,4,129,359,586,5,23,361,360,2,298,362,943,3,60,363,0,3,755,369,501,3,163,376,314,5,118,384,706,3,102,385,26,5,177,396,724,4,279,397,572,4,301,400,746,5,188,406,632,5,225,408,72,2,112,410,175,2,217,420,966,3,37,421,0,3,205,423,604,5,438,425,692,2,120,427,800,5,203,429,208,4,454,434,944,5,48,436,284,3,301,453,302,4,183,455,604,2,136,456,448,4,199,459,840,2,163,466,686,3,317,467,0,3,95,468,674,3,56,470,958,5,57,473,778,3,81,473,797,2,4,474,261,3,127,474,867,4,136,476,800,2,4,485,810,3,4,486,50,3,437,489,145,2,73,503,288,2,305,508,604,2,250,513,478,3,12,514,0,2,100,516,454,4,128,518,538,5,466,519,166,5,368,521,244,2,79,523,0,4,108,524,562,4,291,525,830,3,173,526,0,3,214,526,24,4,4,526,119,4,4,526,878,3,125,527,0,3,462,527,853,2,4,528,854,2,4,529,515,4,143,539,758,2,245,544,376,5,229,550,452,2,226,552,474,5,397,553,646,2,74,555,16,4,171,556,0,2,304,558,424,2,58,561,69,3,285,563,590,2,183,564,224,4,142,564,444,4,216,565,954,2,49,566,658,2,307,574,964,5,33,576,278,3,457,576,618,5,372,577,514,3,29,578,344,2,529,578,708,2,295,579,858,4,145,584,606,5,183,584,923,2,73,587,860,5,34,592,606,3,397,593,0,3,36,604,6,2,114,606,244,3,652,614,0,4,90,619,446,3,264,619,603,4,4,620,832,5,259,621,410,3,231,621,489,4,25,622,602,2,5,623,603,2,5,624,852,4,151,627,348,4,160,630,502,2,89,649,0,2,413,651,987,3,16,652,0,3,518,654,266,5,273,654,483,4,19,657,502,4,200,679,0,4,175,680,0,3,30,681,0,4,101,684,488,3,59,691,349,4,80,696,764,5,196,698,391,2,3,698,402,5,13,698,523,3,131,702,120,2,265,710,610,5,39,710,851,2,152,717,222,3,370,728,0,4,181,735,606,4,232,742,294,4,137,746,38,3,324,748,321,2,323,750,544,4,158,751,552,5,136,752,174,2,333,753,231,2,341,753,444,3,559,754,0,3,84,755,180,5,67,760,894,2,109,779,0,4,116,782,980,4,23,783,793,4,55,794,990,5,43,804,284,2,94,809,0,4,175,812,76,4,55,826,382,2,459,832,775,3,147,832,898,5,141,834,204,3,7,836,327,4,71,840,491,2,451,856,360,3,466,857,523,3,16,858,295,3,171,865,585,2,297,874,165,2,551,875,265,2,585,893,103,4,87,894,84,4,52,901,566,4,19,904,223,2,133,917,688,3,190,921,934,3,69,922,0,3,300,935,371,3,279,935,379,2,219,938,625,4,59,941,652,2,23,942,174,4,58,951,403,4,9,957,524,5,19,960,601,3,245,977,893,2,11,984,405,2,59,984,435,2,95,992,197,3,747,994,583,3,420,994,747,2,223,995,0,3,46
	};
	vector<string> B(1003, string(1003, '.'));
	for (int i = 0; i < A.size(); i += 4) {
		int x = A[i], y = A[i + 1];
		int d = A[i + 2], k = A[i + 3];
		while (k--) {
			B[x][y] = '#';
			x += dx[d], y += dy[d];
		}
	}
	for (auto &s : B) {
		cout << s << "\n";
	}
}

using mat = vector<bitset<71>>;

mat T(mat &m) {
	mat ret = mat(m.size());
	for (int i = 0; i < m.size(); ++i) {
		for (int j = 0; j < m.size(); ++j) {
			ret[i][j] = m[j][i];
		}
	}
	return ret;
}

mat mul(mat &m1, mat &m2) {
	mat ret = mat(m1.size());
	mat m3 = T(m2);
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret.size(); ++j) {
			ret[i][j] = (m1[i] & m3[j]).count() % 2;
		}
	}
	return ret;
}

void solve10() {
	vector<vector<int>> A(20);
	A[1] = {0}, A[2] = {0, 1};
	for (int i = 3; i < A.size(); ++i) {
		copy(A[i - 1].begin(), A[i - 1].end(), back_inserter(A[i]));
		copy(A[i - 2].begin(), A[i - 2].end(), back_inserter(A[i]));
	}
	cout << "a_i = a_{i-1} . a_{i-2}\n\n";
	for (int i = 1; i < 16; ++i) {
		cout << "a_" << i << " = ";
		for (int j = 0; j < A[i].size(); ++j) {
			if (j && j % 40 == 0) {
				cout << "\n" << string(i < 10 ? 6 : 7, ' ');
			}
			cout << A[i][j] << (j == A[i].size() - 1 ? "\n\n" : " ");
		}
	}
	cout << "\n(A_i)^n = B_i (mod 2)\n\n";
	for (int i = 1; i < 71; ++i) {
		mat B(i);
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < i; ++k) {
				B[j][k] = A.back()[i * j + k];
			}
		}
		mat C(B.begin(), B.end());
		mat D(i);
		for (int j = 0; j < i; ++j) {
			D[j][j] = 1;
		}
		ll N = 9099099909999099999LL;
		while (N) {
			if (N % 2) {
				D = mul(C, D);
			}
			C = mul(C, C);
			N /= 2;
		}
		for (int j = 0; j < i; ++j) {
			if (j == i / 2) {
				cout << "A_" << i << " =";
			} else {
				cout << string(i < 10 ? 5 : 6, ' ');
			}
			for (int k = 0; k < i; ++k) {
				cout << " " << B[j][k];
			}
			cout << "   ";
			if (j == i / 2) {
				cout << "B_" << i << " =";
			} else {
				cout << string(i < 10 ? 5 : 6, ' ');
			}
			for (int k = 0; k < i; ++k) {
				cout << " " << D[j][k];
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	if (N == 0) {
		solve0();
	} else if (N == 1) {
		solve1();
	} else if (N == 2) {
		solve2();
	} else if (N == 3) {
		solve3();
	} else if (N == 4) {
		solve4();
	} else if (N == 5) {
		solve5();
	} else if (N == 6) {
		solve6();
	} else if (N == 7) {
		solve7();
	} else if (N == 8) {
		solve8();
	} else if (N == 9) {
		solve9();
	} else {
		solve10();
	}
	return 0;
}
