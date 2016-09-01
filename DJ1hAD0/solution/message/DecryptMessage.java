/**
 * @author LuxXx
 * https://github.com/LuxXx
 */
public class DecryptMessage {
	public static void main(String[] args) {
		String msg = "W{zsfu`axu`}{zg54M{a4c{z84Papq54Dxqugq84gqzp4m{af4g{xa`}{z:4OP^%|UP$I";
		System.out.println(decrypt(msg));
	}
	public static String decrypt(String s) {
		char[] msg = new char[s.length()];
		for (int i = 0; i < s.length(); i++) {
			msg[i] = (char) (s.charAt(i) ^ 20);
		}
		return new String(msg);
	}
}