import java.util.Scanner;

/**
 * @author LuxXx
 * https://github.com/LuxXx
 */
public class ValidPasswordCheck {
	public static void main(String[] args) {
		String password;
		if (args.length > 0) {
			password = args[0];
		} else {
			System.out.println("Enter your password:");
			Scanner s = new Scanner(System.in);
			password = s.nextLine();
			s.close();
		}
		System.out.println("Your password is " + (sum(password) == 866 ? "valid" : "invalid"));
	}
	static int sum(String s) {
		int sum = 0;
		for (int i = 1; i < 9; i++) {
			if (s.length() <= i) continue;
			sum += s.charAt(i);
		}
		return sum;
	}
}
