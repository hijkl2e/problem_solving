import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class boj4149 {
	public static Random rand = new Random();
	public static List<Long> A = new ArrayList<>();
	
	public static BigInteger f(BigInteger x, BigInteger b, BigInteger n) {
		return x.multiply(x).mod(n).add(b).mod(n);
	}
	
	public static BigInteger rho(BigInteger n) {
		if (n.mod(BigInteger.TWO).equals(BigInteger.ZERO)) {
			return BigInteger.TWO;
		}
		BigInteger b = new BigInteger(n.bitLength(), rand);
		BigInteger x = new BigInteger(n.bitLength(), rand);
		BigInteger y = x;
		while (true) {
			x = f(x, b, n);
			y = f(f(y, b, n), b, n);
			BigInteger d = x.subtract(y).gcd(n);
			if (d.compareTo(BigInteger.ONE) == 1) {
				return d;
			}
		}
	}
	
	public static void pollard_rho(BigInteger n) {
		if (n.equals(BigInteger.ONE)) {
			return;
		} else if (n.isProbablePrime(10)) {
			A.add(n.longValue());
			return;
		}
		BigInteger d = rho(n);
		pollard_rho(d);
		pollard_rho(n.divide(d));
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger N = sc.nextBigInteger();
		pollard_rho(N);
		Collections.sort(A);
		for (long x : A) {
			System.out.println(x);
		}
		sc.close();
	}
}
