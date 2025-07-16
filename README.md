# So Long

![42 Badge](https://img.shields.io/badge/42-So_Long-brightgreen)
![C Badge](https://img.shields.io/badge/Language-C-blue)
![Status Badge](https://img.shields.io/badge/Status-Completed-success)
![Score Badge](https://img.shields.io/badge/Score-120%2F100-gold)

## Project Details

For full project requirements, see the [Subject File](./subject.md).

## What I Learned

Through this 2D game development project at 42 School, I developed key graphics programming and game development skills:

- **Graphics library mastery** - Gained proficiency with MiniLibX for window management, image rendering, and event handling
- **2D game architecture** - Designed modular game systems with clear separation between graphics, logic, and input handling
- **Event-driven programming** - Implemented responsive keyboard input and window management with proper event loops
- **Texture and sprite management** - Learned efficient loading, storing, and rendering of game assets
- **Map parsing and validation** - Built robust file parsing with comprehensive error handling for various edge cases
- **Pathfinding algorithms** - Implemented flood-fill algorithm to validate map accessibility and game completion
- **Memory management in graphics** - Proper cleanup of images, windows, and allocated resources to prevent leaks
- **Game state management** - Tracked player position, collectibles, movement count, and win/lose conditions
- **User experience design** - Created smooth gameplay with visual feedback and intuitive controls
- **Animation systems** - Implemented sprite animation for enhanced visual appeal (bonus feature)

This project reinforced my problem-solving abilities, attention to detail, and understanding of real-time graphics programming concepts essential for game development.

## About the Project

So Long is a 2D top-down game where the player navigates through a map to collect items and reach the exit. The game features:

- **Objective**: Collect all items (collectibles) and escape through the exit
- **Controls**: WASD movement with collision detection
- **Graphics**: Custom sprites and textures using MiniLibX
- **Map System**: .ber file format with validation and pathfinding
- **Visual Feedback**: Movement counter and smooth animations

## Implementation Details

The game consists of several core systems working together:

### Game Engine Components

| Core Systems | Graphics Management | Input Handling |
|--------------|-------------------|----------------|
| Map parser & validator | Texture loading | Keyboard events |
| Pathfinding algorithm | Sprite rendering | Window management |
| Game state tracking | Animation system | Clean exit handling |
| Collision detection | Movement counter display | ESC key support |

### Map System

The game uses a structured map format with specific rules:

```
Map Characters:
- '0' = Empty space (walkable)
- '1' = Wall (collision)
- 'C' = Collectible (must collect all)
- 'E' = Exit (goal after collecting all items)
- 'P' = Player starting position (exactly one)
```

**Map Requirements:**
- Rectangular shape with wall boundaries
- Valid path from start to all collectibles and exit
- At least one collectible and exactly one player/exit
- Proper .ber file extension

### Graphics Pipeline

**Asset Management:**
- XPM texture loading and storage
- Sprite animation frame cycling
- Efficient memory cleanup
- Real-time rendering updates

**Visual Elements:**
- Player character with directional sprites
- Animated collectibles and interactive elements
- Movement counter display (bonus: on-screen rendering)
- Smooth window operations and responsiveness

### Bonus Features Implemented

- ✅ **Sprite Animation** - Dynamic animated sprites for enhanced visual appeal
- ✅ **On-screen Movement Counter** - Real-time display instead of shell output
- ❌ **Enemy Patrols** - Not implemented (would add lose condition on contact)

## Usage

```bash
# Compile the game
make

# Compile with bonus features
make bonus

# Run the game
./so_long maps/valid/map.ber

# Clean object files
make clean

# Remove all generated files
make fclean

# Rebuild everything
make re
```

## Map Example

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

This simple map demonstrates:
- Wall boundaries (1)
- Player start position (P)
- Collectible item (C)
- Exit point (E)
- Walkable spaces (0)

## Technical Challenges Overcome

- **Memory management with graphics** - Proper cleanup of MLX images, windows, and textures to prevent leaks
- **Event handling architecture** - Creating responsive input system while maintaining smooth gameplay
- **Map validation algorithms** - Implementing flood-fill pathfinding to ensure all objectives are reachable
- **Cross-platform compatibility** - Working with MiniLibX library constraints and platform-specific behaviors
- **Animation timing** - Implementing smooth sprite animations without blocking game logic
- **Error handling robustness** - Comprehensive validation for malformed maps, missing files, and invalid inputs
- **Modular code design** - Separating graphics, game logic, and input systems for maintainability
- **Resource optimization** - Efficient texture loading and rendering for smooth performance

## Game Features

### Core Gameplay
- **Movement**: Smooth WASD controls with immediate visual feedback
- **Objectives**: Clear goal progression (collect all items → reach exit)
- **Collision**: Proper wall collision preventing invalid movement
- **Tracking**: Real-time movement counter for score tracking

### Visual Polish
- **Custom Assets**: Themed sprites and textures for immersive experience
- **Animations**: Dynamic visual elements bringing the game world to life
- **UI Elements**: Clean movement counter display and game state indicators
- **Window Management**: Proper handling of minimize, resize, and close operations

---

*This project was completed as part of the 42 School curriculum, demonstrating my proficiency in C programming, graphics programming with MiniLibX, game development fundamentals, and software architecture design.*

---

## License

This project is licensed under the [MIT License](./LICENSE).
