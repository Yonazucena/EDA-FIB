#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Random


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }
  /**
   * Types and attributes for your player can be defined here.
   */

  int MAX() {
    return board_rows()*board_cols();
  }

  bool isValid(int i, int j) {
    if (i < 0 || i > board_rows()-1 || j < 0 || j > board_cols()-1) return false;

    Cell copyCell = cell(i, j);
    if (copyCell.type == Street) return true;
    return false;
  }

  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {

    int miJugador = me();
    vector<int> udVivas = alive_units(miJugador);

    // Write debugging info about my unitsif (ran == 0 && isValid(x, y+1) move(udVivas[i], Up);
    cerr << "At round " << round() << " player " << me() << " has " << udVivas.size() << " alive units: ";
    for (auto id : udVivas) {
      cerr << id << " at pos " << unit(id).pos << "; ";
    }
    cerr << endl;

    //detectar comida cercana y mover jugador
    for (uint i = 0; i < udVivas.size(); ++i) {
        int ran = random(0, 3);
        int x = unit(udVivas[i]).pos.i;
        int y = unit(udVivas[i]).pos.j;
        if (ran == 0 && isValid(x, y+1)) move(udVivas[i], Right);
        if (ran == 1 && isValid(x, y-1)) move(udVivas[i], Left);
        if (ran == 2 && isValid(x-1, y)) move(udVivas[i], Up);
        if (ran == 3 && isValid(x+1, y)) move(udVivas[i], Down);
    }

  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
