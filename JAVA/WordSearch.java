public class WordSearch {

    public static void main(String[] args) {
        char[][] board = new char[][] {
                { 'A', 'B', 'C', 'E' },
                { 'S', 'F', 'C', 'S' },
                { 'A', 'D', 'E', 'E' }
        };

        String word = "EESE";
        char[] ch = word.toCharArray();

        System.out.println(isSafe(0, 0, board, ch, 0));

    }

    static boolean isSafe(int r, int c, char[][] board, char[] ch, int k) {

        for (int i = 0; i < board.length; i++) { // row
            for (int j = 0; j < board[0].length; j++) { // col
                if (board[i][j] == ch[0]) {
                    if (search(i, j, board, ch, 0))
                        return true;
                }

            }
        }
        return false;
    }

    static boolean search(int r, int c, char[][] board, char[] ch, int k) {

        if (k == ch.length)
            return true;

        if (r == board.length || c == board[0].length || r < 0 || c < 0 || board[r][c] != ch[k])
            return false;

        board[r][c] = '#';
        int[] x = { 0, 1, 0, -1 };
        int[] y = { 1, 0, -1, 0 };              // (Bade kaam ka hun mm ! huhh)
        boolean temp = false;

        for (int idx = 0; idx < 4; idx++) {
            temp = temp || search(r + x[idx], c + y[idx], board, ch, k + 1);
        }
        board[r][c] = ch[k];

        return temp;
    }

}