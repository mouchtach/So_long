
# so_long

so_long is a simple 2D maze game developed as part of the 42 School curriculum.  
The player navigates through a map to collect items and reach the exit.

---

## Features

- Loads custom `.ber` maps
- Collect items (`C`) before exiting (`E`)
- Simple controls (arrow keys)
- Uses MLX42 graphics library

---

## Installation & Build Instructions

### 1. Clone the repository

```bash
git clone https://github.com/mouchtach/so_long.git
cd so_long
````

### 2. Clone and build MLX42

MLX42 is the graphics library dependency.

```bash
make mlx
make build
```

* `make mlx` clones the MLX42 repo.
* `make build` compiles MLX42.

### 3. Build so\_long

```bash
make
```

### 4. Run the game

```bash
./so_long maps/map.ber
```

Replace `maps/map.ber` with your chosen map file.

---

## Controls

* Use arrow keys to move the player.
* Collect all collectibles (`C`).
* Reach the exit (`E`) to complete the game.

---

## Screenshots

![Gameplay Screenshot](screenshot.png)

---

## Project Structure

* `check/` — map validation and parsing
* `read/` — reading and utility functions
* `game/` — game logic, movement, rendering
* `so_long.c` — main program entry

---

## Author

Developed by **mouchtach** as part of the 42 School curriculum.

---

## Notes

* Make sure you have `cmake` and required libraries installed (for MLX42).
* Maps must follow `.ber` format and be properly formatted.

---

Feel free to contribute or raise issues for improvements!

```

---

If you want, I can help you customize it further or format for GitHub display with badges or GIFs. Just let me know!
```
