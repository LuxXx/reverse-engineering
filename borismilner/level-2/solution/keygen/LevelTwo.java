import java.util.Scanner;


public class LevelTwo {
	public static void main(String[] args) {
		long userId = 0;
		if (args.length > 0) {
			userId = Long.parseLong(args[0]);
		} else {
			Scanner s = new Scanner(System.in);
			System.out.println("Enter userId:");
			userId = s.nextLong();
			s.close();
		}
		String pw = generatePassword(userId);
		System.out.println("Password: " + pw);
	}
	/**
	 * generates a password from a given userId for level 2
	 * @param userId this is the long that you see on your console as User Id, it is randomly generated
	 * @return
	 */
	private static String generatePassword(long userId) {
		
		char[] pw = new char[32];
		
		// fill with Os
		for (int i = 0; i < pw.length; i++) {
			pw[i] = 'O';
		}
		
		// bittest check
		pw[0] = (userId % 2 == 0 ? 'O': '*' );
		
		// TODO: manage SETP, not implemented yet, but SETP is actually almost always true
		pw[2] = '*';
		
		// simple hardcoded condition
		pw[1] = (userId <= 2976579765l ? '*': 'O' );
		
		// iterate through last characters
		for (int i = 3; i < pw.length-1; i++) {
			// the bitshift is essentially an integer division by 2
			userId /= 2;
			// the character is the userId mod 26, add alternately an uppercase or a lowercase char
			pw[i] = (char) (userId % 26 + (i % 2 == 0 ? 65 : 97));
		}
		return new String(pw);
	}
}
