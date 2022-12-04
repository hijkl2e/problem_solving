import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class generalizedrecursivefunctions {
	public static BigInteger[][] dp;
	public static List<Integer> A, B;
	public static BigInteger C, D, E;
	
	public static BigInteger f(int x, int y) {
		if (x <= 0 || y <= 0) {
			return D;
		} else if (!dp[x][y].equals(E)) {
			return dp[x][y];
		}
		BigInteger ret = C;
		for (int i = 0; i < A.size(); ++i) {
			ret = ret.add(f(x - A.get(i), y - B.get(i)));
		}
		return dp[x][y] = ret;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder out = new StringBuilder();
		A = new ArrayList<>();
		B = new ArrayList<>();
		dp = new BigInteger[100][100];
		E = BigInteger.valueOf(-1);
		int T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			A.clear();
			B.clear();
			StringTokenizer st = new StringTokenizer(br.readLine());
			while (st.countTokens() > 2) {
				A.add(Integer.parseInt(st.nextToken()));
				B.add(Integer.parseInt(st.nextToken()));
			}
			C = new BigInteger(st.nextToken());
			D = new BigInteger(st.nextToken());
			for (int i = 0; i < 100; ++i) {
				Arrays.fill(dp[i], E);
			}
			st = new StringTokenizer(br.readLine());
			while (st.hasMoreTokens()) {
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				out.append(f(x, y)).append("\n");
			}
			out.append("\n");
		}
		System.out.print(out);
		br.close();
	}
}
