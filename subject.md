# So Long

## 📘 Project Overview

**So Long** is a 2D game project from the 42 curriculum. Its purpose is to make you work with textures, sprites, and basic gameplay elements using the MiniLibX graphics library.

> **Disclaimer:**  
> This document is an unofficial summary written for educational and documentation purposes.  
> It is not affiliated with or endorsed by 42 or its partners.  
> All 42 students are responsible for adhering to the academic integrity policy.  
> You may **not** publish or share any part of the official subject PDF, evaluation scripts, or Moulinette content.

---

## Contents

- [Goals](#goals)
- [General Requirements](#general-requirements)
- [Mandatory Part](#mandatory-part)
  - [Game Rules](#game-rules)
  - [Graphic Management](#graphic-management)
  - [Map Requirements](#map-requirements)
- [Bonus Part](#bonus-part)
- [Submission Guidelines](#submission-guidelines)

---

## Goals

- Create a basic 2D computer graphics game
- Learn window management and event handling
- Work with colors, textures, and sprites
- Use the MiniLibX graphics library
- Implement basic algorithms and game logic
- Improve C programming skills

---

## General Requirements

- Written in **C**, following the **42 Norm**
- No memory leaks or undefined behavior (segfaults, bus errors, double free)
- All heap allocated memory must be properly freed
- Use only allowed external functions
- Compile with `-Wall -Wextra -Werror` using `cc`

### Program Specifications

- **Program name:** `so_long`
- **Turn in files:** `Makefile`, `*.h`, `*.c`, maps, textures
- **Arguments:** A map file in format `*.ber`
- **Libft:** Authorized

### Allowed External Functions

- `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
- All functions of the math library (`-lm` compiler option)
- All functions of the MiniLibX
- `ft_printf` and any equivalent YOU coded

### Makefile Requirements

Must include rules:
- `$(NAME)`, `all`, `clean`, `fclean`, `re`
- `bonus` rule for bonus features
- Must not relink
- Must compile the library using its Makefile if using libft

---

## Mandatory Part

You must create a basic 2D game where a character collects items and escapes. The default theme is a dolphin escaping Earth after eating fish, but you can use any character, collectibles, and setting.

### Game Rules

- **Objective:** Collect every collectible on the map, then escape using the shortest possible route
- **Controls:** Use `W`, `A`, `S`, `D` keys to move (or `ZQSD`/arrow keys)
- **Movement:** 4 directions - up, down, left, right
- **Restrictions:** Player cannot move into walls
- **Display:** Show current number of movements in the shell after each move
- **View:** Use 2D view (top-down or profile)
- **Real-time:** Not required

### Graphic Management

- Display the game in a window
- Window management must remain smooth (window switching, minimizing, etc.)
- **ESC key:** Must close window and quit program cleanly
- **Window close button:** Must close window and quit program cleanly
- **Mandatory:** Use MiniLibX images

### Map Requirements

#### Map Components

The map must be constructed with exactly **3 components:**
1. **Walls**
2. **Collectibles** 
3. **Free space**

#### Valid Characters

The map can only contain these **5 characters:**
- `0` - Empty space
- `1` - Wall
- `C` - Collectible
- `E` - Map exit
- `P` - Player's starting position

#### Map Rules

- **Required elements:**
  - Exactly 1 exit (`E`)
  - At least 1 collectible (`C`)
  - Exactly 1 starting position (`P`)
- **Shape:** Must be rectangular
- **Boundaries:** Must be closed/surrounded by walls
- **Path validation:** Must have a valid path from start to all collectibles and exit
- **Error handling:** Display "Error\n" followed by explicit error message for any misconfiguration

#### Example Maps

**Simple valid map:**
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

**Minimal valid map:**
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

---

## Bonus Part

> **Important:** Bonus will only be evaluated if the mandatory part is **PERFECT**

You can add extra features such as:

- **Enemy patrols:** Player loses when touching enemies
- **Sprite animation:** Add animated sprites
- **On-screen counter:** Display movement count on screen instead of shell

### Bonus Guidelines

- You may use additional functions if justified during evaluation
- Add files/folders as needed for bonuses
- Use `_bonus.{c/h}` naming convention for bonus files
- Mandatory and bonus evaluations are done separately

---

## Asset Resources

For creating your 2D game, you'll need tiles, tilesets, sprites, and sprite sheets. Talented artists share their work on platforms like:
- **itch.io**

> **Remember:** Always respect other people's work and licensing

---

## Submission Guidelines

- Submit to your assigned Git repository
- Only repository contents will be evaluated
- Double-check file names for correctness
- Organize files as desired (no strict structure requirement)
- Evaluation includes peer reviews and possible **Deepthought** automated testing

---

## Testing

- Create test programs for easier debugging and defense preparation
- Test various map configurations and edge cases
- Verify memory management and error handling
- Test window management and event handling

---

## Final Notes

This project introduces you to computer graphics programming and prepares you for more advanced graphics projects later in the curriculum. Focus on:

- Understanding MiniLibX library functions
- Proper memory management
- Event handling and user input
- Map parsing and validation
- Game logic implementation

Don't spend too much time on this project - more interesting graphics projects await you!

---
