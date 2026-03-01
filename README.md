# C-Theatre-Project

A console-based **Movie Theatre** system in C++ with ticketing and concessions.

## Features

- **Ticketing**: Choose from 5 movies, select adult/child/senior, pick seats from a visual chart (rows A–C, 10 seats each).
- **Concessions**: Combos, beverages, and popcorn with quantity and running total.
- **Receipt**: Running total, sales tax (7%), and final receipt printed to `final_tickets.txt`.

## Project structure

```
AI-IMAXSystemProject2Mohamed-1/AI-IMAXSystemProject2Mohamed/
├── AI-IMAXSystemProject2Mohamed.cpp   # Main entry
├── Common.h                           # Constants, structs, shared helpers
├── Ticketing.h                        # Movie selection, seating, tickets
├── Concessions.h                      # Concessions menus and items
├── AI-IMAXSystemProject2Mohamed.sln   # Visual Studio solution
└── AI-IMAXSystemProject2Mohamed.vcxproj
```

## Build and run

### Visual Studio (Windows)

1. Open `AI-IMAXSystemProject2Mohamed-1/AI-IMAXSystemProject2Mohamed/AI-IMAXSystemProject2Mohamed.sln`.
2. Build (e.g. **Build → Build Solution**).
3. Run the executable from the solution (e.g. **Debug → Start Without Debugging**).

### Command line (g++)

From the folder containing the `.cpp` and `.h` files:

```bash
cd AI-IMAXSystemProject2Mohamed-1/AI-IMAXSystemProject2Mohamed
g++ -std=c++11 -o Theatre AI-IMAXSystemProject2Mohamed.cpp
./Theatre     # Linux/macOS
Theatre.exe   # Windows
```

## GitHub Pages

Documentation and project overview are published on **GitHub Pages**:

**https://\<your-username\>.github.io/C-Theatre-Project/**

To enable:

1. In the repo: **Settings → Pages**.
2. Set **Source** to **Deploy from a branch**.
3. Branch: **main** (or **master**), folder: **/docs**.
4. Save; the site will be built from the `docs/` folder.

## License

This project is for educational use.
