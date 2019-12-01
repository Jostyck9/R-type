# R-type
A R-type online game. This project is a game compatible on Windows and Linux.

[![CircleCI](https://circleci.com/gh/Jostyck9/R-type/tree/master.svg?style=svg)](https://circleci.com/gh/Jostyck9/R-type/tree/master)
[![Build Status](https://travis-ci.com/Jostyck9/R-type.svg?branch=master)](https://travis-ci.com/Jostyck9/R-type)

# Incomming Features!

    - Multi Room
    - etc...

## Installation

To download the repository, you just need to clone it from Github:

```sh
$ git clone git clone https://github.com/Jostyck9/R-type.git
$ cd R-type/
```

## Compilation
You need to have Conan and Cmake installed on your computer
On windows you can use the compilate.PS1 script to create a visual studio solution
On linux you can use the compilate.sh script to create the binary

To compile on Windows, use powershell :

```sh
$ ./compilate.PS1
```

After that, you need to use Visual Studio to compile in realease mode your r-type-server.sln and your r-type-client.sln.
Once it's done, enjoy !

To compile on Linux, use your terminal (using bash or equivalent)

```sh
$ ./compilate.sh
```

After that, you just need to compile with the generated makefile and launch your game !

```sh
$ make
$ cd ..
$ ./build/bin/r-type-client
```

### Usage

This game is a full keyboard usage. You cannot use your mouse.
To deplace choose your different parameters, use the directional arrows.
You can choose your room and be ready for the space battle.

To win, you have to be the last one alive. You can shoot enemies by pressing space bar and move using directional arrows.
Be careful, each ennemies have differents properties.

### Code documentation

The [UML](https://jostyck9.github.io/R-type/inherits.html) and the [CodeDescription](https://jostyck9.github.io/R-type/) id always up to date with the master branch

You can also find in the folder documentation, a wiki that explains how is working our project

Licence
----
Hugo Berthome, Romane Bézier, Esther Bailloux, Clément Dumaine and Hugo Beaupel
