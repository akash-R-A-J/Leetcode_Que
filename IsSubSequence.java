public class IsSubSequence {

    public static boolean isSubSequence(String s, String t) {

        int count = 0;
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < t.length(); i++) {

            if (s.charAt(count) == t.charAt(i)) {
                sb = sb.append(t.charAt(i));
                count++;

                if (s.equals(sb.toString())) {
                    return true;
                }
            }

        }
        return false;
    }

    public static void main(String args[]) {
        String t = "ahbgdc";
        String s = "abc";
        boolean k = isSubSequence(s, t);
        System.out.println(k);
    }
}
