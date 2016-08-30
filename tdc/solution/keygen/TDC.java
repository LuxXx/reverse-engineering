import java.util.Scanner;

/**
 * @author LuxXx
 * https://github.com/LuxXx
 */
public class TDC {
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
		if (username.length() < 17) {
			System.out.println("Please enter a username that contains at least 17 character");
		} else {
			System.out.println("Key: " + generateKey(username));
		}
	}
	
	private static String generateKey(String username) {
		char[] key = new char[16];
		
		for (int i = 0; i < 16; i++) {
			key[i] = (char) ((c(username,i) ^ c(username,i+1)) + 41);
		}
		
		return new String(key);
	}
	
	private static char c(String s, int i) {
		return (s.length() <= i ? 0 : s.charAt(i));
	}
}
