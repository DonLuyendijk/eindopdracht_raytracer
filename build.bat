@echo off

if not exist build ( mkdir build )
if not exist binaries ( mkdir binaries )

echo compiling main.cpp
g++ source/main.cpp ^
    -o build/main.o ^
    -I dependencies/headers ^
    -c ^
    -Wall
if errorlevel 1 (
    echo failed to compile main.cpp
    exit
)

echo linking
g++ build/main.o ^
    -o binaries/main.exe ^
    -L dependencies/libraries/SDL2 ^
    -mconsole ^
    -lmingw32 ^
    -lSDL2main ^
    -lSDL2
if errorlevel 1 (
    echo failed to link
    exit
)

echo done!