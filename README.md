# EDA-FIB QT 2022-2023
my solutions to lab <a href='https://jutge.org/'>jutge</a> problems

## Slides Table of Contents
1.  **Analisi d’Algorismes**
    - Temps i calcul i espai de memoria
    - Notacio asimptotica
    - Cost dels algorismes
2.  **Algorismes de dividir i vencer**
    - Ordenacio per fusio *(mergesort)*
    - Ordenacio rapida *(quicksort)*
    - Productes i exponents
    - Altres algorismes
        - Torres de Hanoi
        - Mediana
3. **Diccionaris**
    - Taules de dispersio *(hash tables)*
    - Arbres
        - Arbres binaris de cerca (ABC) *(binary search tree)*
        - Arbres AVL (Adelson-Velskii i Landis)
4. **Cues amb prioritats**
    - min-heap/max-heap
    - implementacio recursiva/iterativa
    - heapsort
5. **Grafs**
    - grafs dirigits, etiquetats *(directed, weighted graphs)*
    - cerca en profunditat (dfs)
    - cerca en amplada (bfs)
    - algorisme de Dijkstra
    - ordenacio topologica *(topological sort)*
    - arbres d'expansio minims *(min spanning tree)*
6. **Cerca exhaustiva**
    - Backtracking
    - cadenes amb uns
    - permutacions
    
## Notes
1. To compile a file `f.cc`
   ```sh
   g++ -Wall -std=c++11 -O3 -D_GLIBCXX_DEBUG f.cc -o f
   ```
   `-Wall` reports all warnings
   
   `-std=c+11` allows usage of advanced c++ options included in c++11 or later
   
   `-O3` code optimization level 3, produces very optimized code
   
   `-D_GLIBCXX_DEBUG` along others, checks that you dont go out of bounds in any access to vectors
