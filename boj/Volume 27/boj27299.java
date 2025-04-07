import java.math.BigInteger;
import java.util.Scanner;

public class boj27299 {
	static final int MOD = 10000000;
	
	public static long pow(long x, long y) {
		long ret = 1;
		while (y > 0) {
			if (y % 2 == 1) {
				ret = ret * x % MOD;
			}
			x = x * x % MOD;
			y /= 2;
		}
		return ret;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while (T-- > 0) {
			long A = sc.nextLong();
			long B = sc.nextLong();
			int k = sc.nextInt();
			BigInteger C = sc.nextBigInteger();
			long ans;
			if (B == 1 || (B == 2 && C.equals(BigInteger.TWO)) || B < 7 && C.equals(BigInteger.ONE)) {
				ans = pow(A % MOD, B == 1 ? 1 : pow(B, C.intValue()));
			} else {
				if (C.compareTo(BigInteger.valueOf(7)) == -1) {
					B = pow(B % MOD, C.intValue());
				} else {
					B = pow(B % MOD, C.mod(BigInteger.valueOf(MOD)).intValue() + MOD);
				}
				ans = pow(A % MOD, B + MOD);
			}
			while (k-- > 0) {
				ans /= 10;
			}
			System.out.println(ans % 10);
		}
		sc.close();
	}
}
