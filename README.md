<h1 align="center">
	🧊 Cub3D 🧊
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' cub3D project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/iker-gonzalez/42_cursus"><b>42cursus repo</b></a>.
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/iker-gonzalez/cub3d?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/iker-gonzalez/cub3d?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/iker-gonzalez/cub3d?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/iker-gonzalez/cub3d?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/iker-gonzalez/cub3d?color=brightgreen" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
  <span> · </span>
	<a href="#game">Game</a>
</h3>

---

## 🗣️ About

> Small simulated 3D game inspired by the famous [Wolfenstein 3D game](https://www.youtube.com/watch?v=561sPCk6ByE). We need to create a "realistic" 3D graphical representation of the inside of a maze from a first person perspective, using ray casting principles.

**screenshots from our actual game coming soon**

For detailed information, refer to the [**subject of this project**](https://github.com/iker-gonzalez/42_cursus/blob/main/_PDFs/en.subject_cub3d.pdf)


 ## 🛠️ Usage
Clone the repository in your computer using the following command:

`git clone https://github.com/iker-gonzalez/cub3d.git`
 
Then, you need to run the command `make` on the root directory.

This will compile the executable file `cub3d`

Last, run `./cub3d maps/map_of_your_choice`


## Game
To play this game you can use any map of your choice as long as follows the following rules:

* The extension needs to be `.cub`
* It must be surrounded by walls `1`
* Characters allowed:

|  Character  |          Object                         |
|:-----------:|:---------------------------------------:|
|     *1*     | wall                                    |
|     *0*     | Empty                                   |
|     *N*     | Player starting position (north facing) |
|     *E*     | Player starting position (east facing)  |
|     *S*     | Player starting position (south facing) |
|     *W*     | Player starting position (west facing)  |

### Controls
You can use `AWSD` to move `UP`, `DOWN`, `LEFT`, `RIGHT` respectively.
Use right and left arrows to look right and left in the maze.
For restarting the game press `ESC` or click on the red cross on the upper-left corner of the window.


### Credit

This two-person project was done with my colleague and friend Iñigo [@Z3n42](https://github.com/z3n42).
