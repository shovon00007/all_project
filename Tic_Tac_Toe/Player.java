
package tictactoe;

public class Player {
    public enum PlayerType {
        X, O
    }

    private PlayerType playerType;

    public Player(PlayerType playerType) {
        this.playerType = playerType;
    }

    public PlayerType getPlayerType() {
        return playerType;
    }
}