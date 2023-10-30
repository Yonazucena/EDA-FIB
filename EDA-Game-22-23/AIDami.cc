#include "Player.hh"

/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Dami


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

    int rows = board_rows();
    int columns = board_cols();

  //si esta dentro de la board o no
  bool isValid(int i, int j) {
    if (i < 0 || i > board_rows()-1 || j < 0 || j > board_cols()-1) return false;
    return true;
  }

  //devuelve -1 si es waste, devuelve numero max si puedes pasar y 0 si es comida, un enemigo o un zombie
  int isWall(int i, int j) {
    Cell copyCell = cell(i, j);
    if (copyCell.type == Waste) return -1;
    else if (copyCell.food) return 0;
    if (copyCell.id != -1) {
        Unit copyUnit = unit(copyCell.id);
        if (copyUnit.type == Dead) return -1;
        else if (copyUnit.type == Alive and copyCell.owner != me()) return 0;
        else if (copyUnit.type == Alive) return -1;
        else if (copyUnit.type == Zombie) return 0;
    }
    return MAX();
  }

  //returns cell next to source cell
  Pos leftCell(Pos position) {
    Pos res(position.i, position.j-1);
    return res;
  }
  Pos rightCell(Pos position) {
    Pos res(position.i, position.j+1);
    return res;
  }
  Pos upCell(Pos position) {
    Pos res(position.i-1, position.j);
    return res;
  }
  Pos downCell(Pos position) {
    Pos res(position.i+1, position.j);
    return res;
  }

  vector<Pos> findAdj (Pos position) {
    vector<Pos> adj;
    adj.push_back(leftCell(position));
    adj.push_back(rightCell(position));
    adj.push_back(downCell(position));
    adj.push_back(upCell(position));
    return adj;
  }

  Pos reconstructPath(const vector<vector<Pos> >& prev, const Pos& pInicial, const Pos& pFinal) {
    vector<Pos> path;
    Pos at = pFinal;
    while (at != pInicial) {
      path.push_back(at);
      at = prev[at.i][at.j];
    }
    if (path.size() >= 1) {
      return path[path.size()-1];
    }
    return Pos(-1, -1);
  }

  Dir findPath (vector<vector<int> >&map, Pos src, bool& mueve) {
    vector<vector<Pos> > pred(board_rows(), vector<Pos>(board_cols()));
    queue<Pos> q;
    vector<Pos> adj;
    vector<vector<bool> > visited(board_rows(), vector<bool>(board_cols(), false));
    
    q.push(src);
    visited[src.i][src.j] = true;

    while(!q.empty()) {
      Pos last = q.front();
      //cerr << "miramos pos " << last.i << " " << last.j << endl;
      q.pop();

      //cerr << "entra findAdj" << endl;
      adj = findAdj(last);
      //cerr << "sale findAdj" << endl;
      for(int i = 0; i < adj.size(); ++i) {
        if (pos_ok(adj[i].i, adj[i].j) and map[adj[i].i][adj[i].j] != -1) {
          if (visited[adj[i].i][adj[i].j] == false) {
            visited[adj[i].i][adj[i].j] = true;
            pred[adj[i].i][adj[i].j] = last;
            q.push(adj[i]);
          }

          if (map[adj[i].i][adj[i].j] == 0) {
            //cerr << "entra reconstructPath" << endl;
            Pos pDir = reconstructPath(pred, src, adj[i]);
            //cerr << "sale reconstructPath" << endl;
            if (pDir == leftCell(src)) {
              mueve = true;
              //cerr << "nearest cell to " << src.i << " " << src.j << " is " << adj[i].i << " " << adj[i].j << endl;
              return Left;
            }
            if (pDir == upCell(src)) {
              //cerr << "nearest cell to " << src.i << " " << src.j << " is " << adj[i].i << " " << adj[i].j << endl;
              mueve = true;
              return Up;
            }
            if (pDir == downCell(src)) {
              //cerr << "nearest cell to " << src.i << " " << src.j << " is " << adj[i].i << " " << adj[i].j << endl;
              mueve = true;
              return Down;
            }
            if (pDir == rightCell(src)) {
              //cerr << "nearest cell to " << src.i << " " << src.j << " is " << adj[i].i << " " << adj[i].j << endl;
              mueve = true;
              return Right;
            }
          }
        }
        
      }
    }
    //cerr << src.i << " " << src.j << "no se mueve" << endl;
    //while(1);
    //para devolver algo
    return Up;
  }

  vector<vector<int> > readMap () {
    int rows = board_rows();
    int columns = board_cols();
    vector<vector<int> > M(rows, vector<int> (columns, 0));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j){
        M[i][j] = isWall(i, j);
      }
    }
    return M;
  }

  //mover unidad a la cosa mas cercana
  void moverUd(int idUd, vector<vector<int> > M) {
    bool mueve = false;
    //cerr << "entra findPath" << endl;
    Dir direccion = findPath(M, unit(idUd).pos, mueve);
    //cerr << "sale findPath" << endl;
    if (mueve) {
      if (direccion == Left || direccion == Right || direccion == Up || direccion == Down) {
        move(idUd, direccion);
      }
    }
    else {
      int ran = random(0, 3);
      int x = unit(idUd).pos.i;
      int y = unit(idUd).pos.j;
      if (ran == 0 && isValid(x, y+1)) move(idUd, Right);
      if (ran == 1 && isValid(x, y-1)) move(idUd, Left);
      if (ran == 2 && isValid(x-1, y)) move(idUd, Up);
      if (ran == 3 && isValid(x+1, y)) move(idUd, Down);
    }
  }

  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {

    int miJugador = me();
    vector<int> udVivas = alive_units(miJugador);
    //cerr << "entra readMap" << endl;
    vector<vector<int> > M = readMap();
    //cerr << "sale readMap" << endl;

    // Write debugging info about my units
    cerr << "At round " << round() << " player " << me() << " has " << udVivas.size() << " alive units: ";
    for (auto id : udVivas) {
      cerr << id << " at pos " << unit(id).pos << "; ";
    }
    cerr << endl;

    //detectar comida cercana y mover jugador
    for (uint i = 0; i < udVivas.size(); ++i) {
      moverUd(udVivas[i], M);
    }
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
