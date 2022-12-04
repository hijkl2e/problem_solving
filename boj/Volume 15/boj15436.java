import java.math.BigInteger;
import java.util.Scanner;

public class boj15436 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger N = sc.nextBigInteger();
		BigInteger K = sc.nextBigInteger();
		if (K.compareTo(BigInteger.valueOf(335)) == 1
				|| N.compareTo(BigInteger.TWO.pow(K.intValue())) < 1) {
			System.out.println("Your wish is granted!");
		} else {
			System.out.println("You will become a flying monkey!");
		}
		sc.close();
	}
}
