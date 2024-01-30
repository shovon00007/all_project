
package tictactoe;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TicTacToeGUI {
    private JFrame frame;
    private GameBoard gameBoard;
    private JButton[][] buttons;
    private Player p1, p2;
    private Player currentPlayer;
    private JLabel statusLabel;
    JFrame f;
    public void createAndShowGUI() {
        frame = new JFrame("Tic Tac Toe");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());

        gameBoard = new GameBoard(3);
        p1 = new Player(Player.PlayerType.X);
        p2 = new Player(Player.PlayerType.O);
        currentPlayer = p1;

        buttons = new JButton[3][3];
        JPanel boardPanel = new JPanel(new GridLayout(3, 3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                buttons[i][j] = new JButton();
                buttons[i][j].setFont(new Font("Serif", Font.BOLD, 75));
                buttons[i][j].setFocusable(false);
                buttons[i][j].addActionListener(new ButtonListener(i, j));
                boardPanel.add(buttons[i][j]);
            }
        }
        
        frame.add(boardPanel, BorderLayout.CENTER);
        statusLabel = new JLabel();
        statusLabel.setText("Player X's turn");
        statusLabel.setPreferredSize(new Dimension(100, 100));
        statusLabel.setHorizontalAlignment(JLabel.CENTER);
        statusLabel.setFont(new Font("Serif", Font.BOLD, 50));
        frame.add(statusLabel, BorderLayout.NORTH);

        frame.setSize(700, 600);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

    private class ButtonListener implements ActionListener {
        private int row,col;

        public ButtonListener(int row, int col) {
            this.row = row;
            this.col = col;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            if (gameBoard.placePiece(currentPlayer, row, col)) {
                buttons[row][col].setText(currentPlayer.getPlayerType().toString());
                buttons[row][col].setForeground(currentPlayer.getPlayerType() == Player.PlayerType.X ? Color.RED : Color.BLUE);

                Player winner = gameBoard.checkWinner();
                if (winner != null) {
                    gameOver(winner.getPlayerType().toString());
                } else if (gameBoard.isFull()) {
                    gameDraw();
                } else {
                    switchPlayer();
                }
            }
        }
    }

    private void switchPlayer() {
        currentPlayer = currentPlayer == p1 ? p2 : p1;
        statusLabel.setText("Player " + currentPlayer.getPlayerType().toString() + "'s turn");
    }

    private void gameOver(String s){
        Object[] option={"Restart","Exit"};
        statusLabel.setText("Game Over");
        int n=JOptionPane.showOptionDialog(frame, "Game Over\n"+s+" Wins!!!\nHappy Gaming!! :)","Game Over",JOptionPane.YES_NO_CANCEL_OPTION,JOptionPane.QUESTION_MESSAGE,null,option,option[0]);
        if(n==0){
            restartGame();
        }
        else{
            frame.dispose();
        }
    }
    private void gameDraw(){ 
        f = new JFrame();  
        statusLabel.setText("Match Draw");
        JOptionPane.showMessageDialog(f,"Match Draw\nPlay Again!!!","Game Over",JOptionPane.WARNING_MESSAGE);   
        restartGame();
        }  

    private void restartGame() {
        gameBoard = new GameBoard(3);
        currentPlayer = p1;
        statusLabel.setText("Player X's turn");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                buttons[i][j].setText("");
            }
        }
    }
}