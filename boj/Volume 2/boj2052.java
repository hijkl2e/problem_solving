import java.math.BigDecimal;
import java.util.Scanner;

public class boj2052 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		BigDecimal two = BigDecimal.valueOf(2);
		System.out.println(BigDecimal.ONE.divide(two.pow(N)).toPlainString());
		sc.close();
	}
}
