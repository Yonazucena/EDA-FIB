#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Zombie


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

  //devuelve -1 si es waste, devuelve numero max si puedes pasar y 0 si es comida
  int isWall(int i, int j) {
    Cell copyCell = cell(i, j);
    if (copyCell.type == Waste) return -1;
    return MAX();
  }

  Dir direccionComida(Pos position) {
    int rows = board_rows();
    int columns = board_cols();

    queue<Pos> Q;

    vector<vector<int> > M(rows, vector<int> (columns));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j){
        if (isValid(i, j)) {
          M[i][j] = isWall(i, j);
        }
      }
    }

    vector<int> listZombies = zombies();
    for (uint i = 0; i < listZombies.size(); ++i) {
        Unit zmb = unit(listZombies[i]);
        int x = zmb.pos.i;
        int y = zmb.pos.j;
        M[x][y] = 0;
    }

    //mientras no se cambien todas las celdas de la matriz
    int count = 0;
    while (count < MAX()) {
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j){
          int dist = M[i][j]+1;
          if (isValid(i-1, j)) {
            if (dist < M[i-1][j]) M[i-1][j] = dist;
            count++;
          }
          if (isValid(i+1, j)) {
            if (dist < M[i+1][j]) M[i+1][j] = dist;
            count++;
          }
          if (isValid(i, j-1)) {
            if (dist < M[i][j-1]) M[i][j-1] = dist;
            count++;
          }
          if (isValid(i, j+1)) {
            if (dist < M[i][j+1]) M[i][j+1] = dist;
            count++;
          }
        }
      }
    }

    int x = position.i;
    int y = position.j;
    int dist_min = MAX();
    Dir direction;
    if (isValid(x-1,y) && M[x-1][y] < dist_min && M[x-1][y] != -1) {
      dist_min = M[x-1][y];
      direction = Up;
    }
    if (isValid(x+1,y) && M[x+1][y] < dist_min && M[x+1][y] != -1) {
      dist_min = M[x+1][y];
      direction = Down;
    }
    if (isValid(x,y-1) && M[x][y-1] < dist_min && M[x][y-1] != -1) {
      dist_min = M[x][y-1];
      direction = Left;
    }
    if (isValid(x,y+1) && M[x][y+1] < dist_min && M[x][y+1] != -1) {
      dist_min = M[x][y+1];
      direction = Right;
    }
    return direction;
  }

  void moverUd(int idUd) {
    Unit unidad = unit(idUd);
    Dir direccion = direccionComida(unidad.pos);
    if (direccion == Left || direccion == Right || direccion == Up || direccion == Down) {
        move(idUd, direccion);
    }
  }

  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {

    int miJugador = me();
    vector<int> udVivas = alive_units(miJugador);

    // Write debugging info about my units
    cerr << "At round " << round() << " player " << me() << " has " << udVivas.size() << " alive units: ";
    for (auto id : udVivas) {
      cerr << id << " at pos " << unit(id).pos << "; ";
    }
    cerr << endl;

    //detectar comida cercana y mover jugador
    for (uint i = 0; i < udVivas.size(); ++i) {
      moverUd(udVivas[i]);
    }

  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);