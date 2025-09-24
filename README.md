# mouse-crawler
A small Windows utility that moves the mouse cursor around the screen like an old TV screensaver: the cursor bounces off the edges.
The program stops as soon as the user presses any button.

## Features
- Works only on Windows.
- Runs without a console (executable).
- Terminates on real user mouse movement.

## Build
Requires CMake ≥ 3.15 and a C++17 compiler (MSVC or MinGW).

Build steps:
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```

## License
MIT.
