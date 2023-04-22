import java.math.BigInteger;
import java.util.Scanner;

public class boj6571 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger[] fibo = new BigInteger[480];
		fibo[0] = fibo[1] = BigInteger.ONE;
		for (int i = 2; i < fibo.length; ++i) {
			fibo[i] = fibo[i - 1].add(fibo[i - 2]);
		}
		while (true) {
			BigInteger a = new BigInteger(sc.next());
			BigInteger b = new BigInteger(sc.next());
			if (b.equals(BigInteger.ZERO)) {
				break;
			}
			int ans = 0;
			for (int i = 1; i < fibo.length; ++i) {
				if (a.compareTo(fibo[i]) <= 0 && fibo[i].compareTo(b) <= 0) {
					++ans;
				}
			}
			System.out.println(ans);
		}
		sc.close();
	}
}
