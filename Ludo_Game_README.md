# Console-Based 2-Player Ludo Game

A feature-rich, interactive Ludo game built in **C++** for Windows Console with dynamic board rendering, real-time token animation, and immersive gameplay experience.

## Overview

This is a **Programming Fundamentals Final Project** that brings the classic Ludo board game to life in the Windows Console. Featuring dynamic board rendering with colored tokens, smooth animations, collision detection, and game persistence. This project demonstrates professional software development practices in C++.

**Built with passion for learning and attention to detail.**

**✨ Key Features**

### 🎮 Gameplay & Mechanics

- ✅ **2-Player Turn-Based Gameplay** - Takes turns rolling dice and moving tokens
- ✅ **Complete Ludo Rules Implementation** - Token movement, safe zones, home column, and winning conditions
- ✅ **Collision Detection** - Opponent tokens sent back to base on capture
- ✅ **Dice Roll Simulation** - Realistic dice mechanics with proper logic
- ✅ **Win Condition Detection** - First player to get both tokens home wins!

### 🎨 Visual Experience

- ✅ **Dynamic Board Rendering** - Full Ludo board rendered in Windows Console
- ✅ **Colored Token Display** - 🟡 Yellow & 🔴 Red tokens easily distinguishable
- ✅ **Token Animation** - Smooth, visual movement across the board with step-by-step progression
- ✅ **Real-Time Board Updates** - Console screen updates dynamically with every move
- ✅ **Intuitive UI** - Clear display of game status, current player, and available moves

### Game Management

- ✅ **Save & Load Functionality** - Resume games across sessions
- ✅ **File I/O Implementation** - Persistent game state storage
- ✅ **Game Session Tracking** - Keep track of player progress and moves

### Audio & Immersion

- ✅ **Sound Effects** - Using Windows Console API for audio feedback
- ✅ **Audio Cues** - Different sounds for dice rolls, token captures, and victories

### Code Architecture

- ✅ **Modular Design** - Clean separation across multiple .cpp and .h files
- ✅ **Reusable Components** - Well-structured functions for different game aspects
- ✅ **Professional Standards** - Comments, proper naming conventions, and logical organization

**🎯 Technical Highlights**

### Technologies Used

- **Language:** C++ (Standard C++)
- **Platform:** Windows Console API
- **Compilation:** Visual Studio / g++ with Windows headers
- **Features:** 2D Arrays, File I/O, Console Manipulation, Game Logic

### Core Algorithms

- **Token Movement Calculation** - Tracks position around the board
- **Collision Detection** - Identifies when tokens occupy the same space
- **Safe Zone Logic** - Protects tokens from capture
- **State Management** - Maintains game state for save/load functionality

## Getting Started

### Prerequisites

- **Windows OS** (7 or later)
- **C++ Compiler** (Visual Studio 2015+ OR g++ with MinGW)
- **Console window** with Unicode/ANSI support

\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_**\_\_\_

### Installation

#### Option 1: Using Visual Studio

\# Clone the repository  
git clone <https://github.com/yourusername/ludo-game-cpp.git>  
cd ludo-game-cpp  
<br/>\# Open in Visual Studio  
\# File → Open → Project/Solution → Select .sln file  
\# Build → Build Solution  
\# Debug → Start Without Debugging

#### Option 2: Command Line Compilation

\# Clone the repository  
git clone <https://github.com/yourusername/ludo-game-cpp.git>  
cd ludo-game-cpp  
<br/>\# Compile (ensure Windows.h is available)  
g++ -std=c++11 -o Ludo \*.cpp  
<br/>\# Run the game  
Ludo.exe

### Running the Game

Ludo.exe

**Gameplay Flow:**

1\. See the colorful Ludo board rendered in console

2\. Player 1 (Yellow 🟡) rolls the dice

3\. Select which token to move

4\. Watch the animation as your token moves!

5\. Player 2 (Red 🔴) takes their turn

6\. Capture opponent tokens by landing on them

7\. First to get both tokens home wins!

## How to Play

### Game Objective

Get both your tokens from the starting position to your home column before your opponent does.

### Turn Flow

1\. **Roll Dice** - Press key to roll (generates 1-6)

2\. **Select Token** - Choose which token to move

3\. **Watch Animation** - Token slides across the board

4\. **Capture** - If you land on opponent's token, they go back to start

5\. **Reach Home** - Move tokens to safe home positions to win

### Special Rules

- 🟡 **Safe Zones** - Tokens in safe zones cannot be captured
- 🏠 **Home Column** - Final destination for tokens
- ⭐ **Double Roll** - Roll again if you get a 6 (optional enhancement)

## Project Structure

ludo-game-cpp/  
├── main.cpp # Entry point & game loop  
├── Game.h / Game.cpp # Core game logic & mechanics  
├── Player.h / Player.cpp # Player data & token management  
├── Board.h / Board.cpp # Board state & rendering  
├── Token.h / Token.cpp # Token properties & movement  
├── Dice.h / Dice.cpp # Dice rolling simulation  
├── Console.h / Console.cpp # Windows Console API wrapper  
├── FileIO.h / FileIO.cpp # Save/Load functionality  
├── .gitignore  
├── LICENSE  
└── README.md

## Concepts Mastered

### Core Programming

✅ **Modular Code Design** - Organized functions with single responsibility  
✅ **2D Arrays** - Managing board state efficiently  
✅ **Control Flow & Logic** - Complex conditionals for game rules

### Advanced Topics

✅ **File I/O Operations** - Reading/writing game saves  
✅ **Windows Console API** - Cursor control, colors, and sound  
✅ **Collision Detection Algorithms** - Detecting token overlaps  
✅ **Animation & Real-Time Updates** - Smooth token movement  
✅ **Memory Management** - Dynamic allocation and deallocation

### Software Development

✅ **Debugging & Testing** - Identifying and fixing complex bugs  
✅ **Code Documentation** - Clear comments and readability  
✅ **Version Control** - Git collaboration with teammates  
✅ **Team Collaboration** - Working effectively with group members

## What Makes This Project Special

💡 **Goes Beyond Textbook Learning** - Combines multiple concepts into one cohesive project  
🎨 **Visual & Interactive** - Engaging console UI with animations  
🤝 **Collaborative Development** - Built as a team with version control  
🔧 **Production-Quality Code** - Modular, documented, and maintainable  
🚀 **Real-World Applicable** - Demonstrates practical software development skills

## Team & Collaboration

**Developed by:** Asad Ali & Abdul Naffey  
**Project Type:** Programming Fundamentals - Final Project  
**Institution:** FAST NUCES CFD Campus

**Key Learnings from Collaboration:**

- Effective code merging and conflict resolution
- Division of responsibilities
- Code review and feedback
- Problem-solving together

### Libraries Used

- &lt;windows.h&gt; - Console API for colors, cursor, and sound
- &lt;iostream&gt; - Standard input/output
- &lt;fstream&gt; - File I/O for save/load
- &lt;ctime&gt; - Random number generation
- &lt;string&gt; - String manipulation
- &lt;vector&gt; - Dynamic arrays for token management

## Educational Value

This project serves as an excellent portfolio piece demonstrating:

- **Software Engineering** - Proper code organization and design patterns
- **Problem Solving** - Breaking complex problems into manageable pieces
- **Collaboration** - Effective teamwork and communication
- **Persistence** - Debugging and improving complex systems

## Contact & Feedback

Have questions or suggestions?

- 🐛 Found a bug? Open an Issue
- 💡 Have an idea? Start a Discussion
- 📧 Email: <asadalix752@gmail.com>
- 🔗 LinkedIn: <https://www.linkedin.com/in/asad-ali-859223310>

## About the Developer

**Passionate programmer** and **AI/ML enthusiast** dedicated to mastering programming fundamentals before diving into advanced topics. Loves building interactive systems and solving real-world problems through code.

**Lahore, Pakistan** | GitHub | LinkedIn

## Resources Used

- C++ Reference
- Windows Console API
- Game Development Patterns
- Ludo Game Rules
- Modern C++ Best Practices

**🎯 Achievements**

✅ Successfully implemented complete Ludo game logic  
✅ Understood Windows Console API for interactive UI  
✅ Created smooth animations and real-time updates  
✅ Implemented file I/O for game persistence  
✅ Debugged complex interactive systems  
✅ Collaborated effectively as a development team  
✅ Delivered a production-quality final project

**"Every bug we squashed made us better developers."**

If you find this project helpful or inspiring, consider giving it a ⭐ **star**!

Happy Gaming!