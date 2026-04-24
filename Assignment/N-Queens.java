import java.util.*;
public class NQueens {
    static int count=0;
    public static void solveNQueens(int n){
        char[][] board=new char[n][n];
        for(char[] row : board){
            Arrays.fill(row,'.');
        }
        boolean[] cols=new boolean[n];
        boolean[] diag1=new boolean[2*n-1]; 
        boolean[] diag2=new boolean[2*n-1];
        backtrack(0,board,cols,diag1,diag2,n);
        System.out.println("Total solutions: "+count);
    }
    private static void backtrack(int row,char[][] board,
                                  boolean[] cols,
                                  boolean[] diag1,
                                  boolean[] diag2,
                                  int n){

        if(row == n){
            count++;
            printBoard(board);
            System.out.println();
            return;
        }
        for(int col=0;col<n;col++){
            int d1=row-col+n-1;
            int d2=row+col;
            if(cols[col] || diag1[d1] || diag2[d2]) continue;
            board[row][col]='Q';
            cols[col]=diag1[d1]=diag2[d2] = true;
            backtrack(row+1,board,cols,diag1,diag2,n);
            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
    private static void printBoard(char[][] board) {
        for (char[] row : board) {
            System.out.println(new String(row));
        }
    }
    public static void main(String[] args) {
        int n = 4;
        solveNQueens(n);
    }
}
