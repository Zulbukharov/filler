# [Azulbukh][FILLER]

# Filler

Filler is a game, where two players / algorithm are fighting on a map. 

A virtual machine organizes the game :
- calls the players alternatively
- give each a random piece

On each turn, the current player have to put his piece on the map, and try to bother the ennemy. 
To put a piece, the player have to write its coordinates in the "Y X\n" format on the standard input (stdin). 

The game appears on the standard input. 

The aim of the game is to put more pieces on the map than the ennemy. 

## Bonus

On big maps it's difficult to see what is really happening.

A visualizer made with the SDL2 helps us to understand what's happening. 

## Example

![Alt Text](https://github.com/Zulbukharov/filler/blob/master/img/image.png)

## Prerequisites

`brew install SDL2`

`brew install SDL2_ttf`

If brew isn't installed, compile the project with the sources (don't forget to change the Makefile).

## Installation

`make`

## Run

Standard mode : 

`./filler_vm -f [map] -p1 [player1] -p2 [player2]`

Visualizer mode :

`./filler_vm -f [map] -p1 [player1] -p2 [player2] | ./visual/visual`

Example from the root folder : 
`resources/./filler_vm -f resources/maps/map02 -p1 ./azulbukh.filler -p2 resources/players/superjeannot.filler | ./visual/visual`

## Final Mark

`125/100`

<p align="center">
  <img src="https://i.pinimg.com/originals/72/a3/6b/72a36b11250e85d449343c2b844fb7b6.gif">
</p>

