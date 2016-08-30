import java.util.Scanner;

/**
 * @author LuxXx
 * https://github.com/LuxXx
 */
public class LevelOne {
	public static void main(String[] args) {
		String username;
		if (args.length > 0) {
			username = args[0];
		} else {
			System.out.println("Enter username:");
			Scanner s = new Scanner(System.in);
			username = s.nextLine();
			s.close();
		}
		System.out.println("Key: " + generateKey(username));
	}
	public static int generateKey(String username) {
		int key = 0;
		for (int i = 0; i < username.length(); i++) {
			key += (int) username.charAt(i);
		}
		return key;
	}
}
