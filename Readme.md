# Short info
## Conway's Game of Life

---

The Game of Life, also known simply as Life,
is a cellular automaton devised by the British
mathematician John Horton Conway in 1970.
It is a zero-player game, meaning that its evolution 
is determined by its initial state, requiring no further 
input. One interacts with the Game of Life by creating an
initial configuration and observing how it evolves. 
It is Turing complete and can simulate a universal 
constructor or any other Turing machine. (https://en.wikipedia.org/wiki/Conway's_Game_of_Life) 

### Rules
The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead, (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

* Any live cell with fewer than two live neighbours dies, as if by underpopulation.
* Any live cell with two or three live neighbours lives on to the next generation.
* Any live cell with more than three live neighbours dies, as if by overpopulation.
* Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

These rules, which compare the behavior of the automaton to real life, can be condensed into the following:

* Any live cell with two or three live neighbours survives.
* Any dead cell with three live neighbours becomes a live cell.
* All other live cells die in the next generation. Similarly, all other dead cells stay dead.

The initial pattern constitutes the seed of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed, live or dead; births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick. Each generation is a pure function of the preceding one. The rules continue to be applied repeatedly to create further generations. 

---

## Description

I`m implement this by Qt framework.
At the beginning its initialized with field width and height equal 10 by default, but user can set it by input fields in right dock panel
For tagging cell, user should click on it. For start/stop game, user should click on buttons start/stop in right dock panel.

![Game representation](https://s9.gifyu.com/images/game5e3845f1e83a58d6.md.gif)

## UML Datagram

---

Below you can see project class diagram

![Datagram](https://i.ibb.co/KFS1P3G/LifeGame.png)