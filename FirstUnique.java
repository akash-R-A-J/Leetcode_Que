public class FirstUnique {

    // brute force
    public static int firstUniqChar(String s) {

        // outer loop
        for (int i = 0; i < s.length(); i++) {

            int flag = 1;
            int count = 0;
            char index[] = new char[s.length()];

            // inner loop-1 (checks forward repeated character)
            for (int j = i + 1; j < s.length(); j++) {

                if (s.charAt(i) == s.charAt(j)) {
                    System.out.println("A");
                    flag = 0;
                    index[count] = s.charAt(j);
                    count++;
                    break;
                }
            }
            for (int j = 0; j < count; j++) {
                System.out.print(index[j] + " : indexarr ");
            }
            System.out.println();

            // inner loop-2 (checks backward repeated character if forward not found)
            if (flag == 1) {
                for (int j = 0; j < count; j++) {
                    System.out.print(index[j] + " : indexarr ");
                    System.out.println("B" + s.charAt(i) + " repeated: " + index[j]);
                    if (s.charAt(i) == index[j]) {
                        System.out.println("c");
                        flag = 0;
                        break;
                    }
                }
            }

            // display element stored in index array
            // for (int j = 0; j < count; j++) {
            //     System.out.print(index[j] + " ");
            // }
            // System.out.println();

            if (flag == 1) {
                return i;
            }

        }
        return -1;
    }

    public static void main(String args[]) {
        String s = "aabb";
        System.out.println(firstUniqChar(s));
    }

}