# Snake Game

Recreating the classic Nokia Snake game in C, playable right in your terminal.

>Currently in development

## Demo
<!-- Add a GIF here after you finish the game -->

## Built With
- C
- ncurses library

## Installation

### Prerequisites
- Linux or WSL (Windows Subsystem for Linux)
- gcc
- ncurses library

```bash
sudo apt install gcc libncurses5-dev
```

### Run the game

```bash
git clone https://github.com/RaodeoH324/Snake-Game.git
cd Snake-Game
make
./snake
```

## Controls

| Key | Action |
|-----|--------|
| w | Move Up |
| s | Move Down |
| a | Move Left |
| d | Move Right |
| `q` | Quit game |

## Features
- [x] Game border drawn ✅
- [ ] Snake movement
- [ ] Food spawning
- [ ] Score tracking
- [ ] Collision detection
- [ ] Game over screen

## 📁 Project Structure
Snake-Game/
├── src/
│   ├── main.c
│   ├── game.c
│   ├── snake.c
│   └── render.c
├── include/
│   ├── game.h
│   ├── snake.h
│   └── render.h
├── Makefile
└── README.md

## License
This project is licensed under the MIT License.