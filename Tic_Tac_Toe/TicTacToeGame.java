
package tictactoe;

import javax.swing.*;

public class TicTacToeGame {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            TicTacToeGUI gameGUI = new TicTacToeGUI();
            gameGUI.createAndShowGUI();
        });
    }
}
