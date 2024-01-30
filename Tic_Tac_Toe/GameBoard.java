
package tictactoe;

public class GameBoard {
    private Player[][] board;
    private int boardSize;

    public GameBoard(int boardSize) {
        this.boardSize = boardSize;
        board = new Player[boardSize][boardSize];
    }

    public boolean placePiece(Player player, int row, int col) {
        if (board[row][col] == null) {
            board[row][col] = player;
            return true;
        }
        return false;
    }

    public Player checkWinner() {
        
        for (int i = 0; i < boardSize; i++) {
            if (checkLine(board[i][0], board[i]) || checkLine(board[0][i], getColumn(i))) {
                return board[i][0];
            }
        }

        Player[] diagonal1 = new Player[boardSize];
        Player[] diagonal2 = new Player[boardSize];
        for (int i = 0; i < boardSize; i++) {
            diagonal1[i] = board[i][i];
            diagonal2[i] = board[i][boardSize - 1 - i];
        }

        if (checkLine(diagonal1[0], diagonal1) || checkLine(diagonal2[0], diagonal2)) {
            return diagonal1[0];
        }

        return null;
    }

    private boolean checkLine(Player first, Player[] line) {
        if (first == null) {
            return false;
        }

        for (Player player : line) {
            if (player == null || player.getPlayerType() != first.getPlayerType()) {
                return false;
            }
        }

        return true;
    }

    private Player[] getColumn(int col) {
        Player[] column = new Player[boardSize];
        for (int i = 0; i < boardSize; i++) {
            column[i] = board[i][col];
        }
        return column;
    }

    public boolean isFull() {
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if (board[i][j] == null) {
                    return false;
                }
            }
        }
        return true;
    }

    public Player getPlayerAt(int row, int col) {
        return board[row][col];
    }

    public int getBoardSize() {
        return boardSize;
    }
}