import java.util.Scanner;

/**
 * @author LuxXx
 * https://github.com/LuxXx
 */
public class Toad {
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
		if (username.length() < 8) {
			System.out.println("Please enter a username that contains at least 8 character");
		} else {
			System.out.println("Key: " + generateKey(username));
		}
	}
	private static String generateKey(String username) {
		
		if (username.length() < 8) return null;
		
		// the keygen is buggy, it requires 9 chars as username, but is only using 8
		// we also want to be able to generate keys for usernames with length 8
		// this is a simple workaround
		if (username.length() == 8) {
			char[] newUsername = new char[9];
			for (int i = 0; i < newUsername.length - 1; i++) {
				newUsername[i] = username.charAt(i);
			}
			newUsername[8] = 0;
			username = new String(newUsername);
		}
		
		char[] key = new char[9];
		int j = username.charAt(1) / 3;
		for (int i = 0; i <= 8; i++) {
			int tmp = ((j ^ username.charAt(i)) & 60);
			key[i] = (char) (tmp + 48);
			j = 3 * tmp;
		}
		
		return new String(key);
	}
}
