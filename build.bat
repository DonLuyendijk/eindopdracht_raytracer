@echo off

if not exist build ( mkdir build )
if not exist binaries ( mkdir binaries )

set "object_file_names="

rem module names
call :compile_module main
call :compile_module shape

echo linking
g++ %object_file_names% ^
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

copy dependencies\libraries\SDL2\SDL2.dll binaries\SDL2.dll

echo done!
exit /b 0

:compile_module
set "object_file_names=%object_file_names% build/%~1.o"
echo compiling %~1.cpp
g++ source/%~1.cpp ^
    -o build/%~1.o ^
    -I dependencies/headers ^
    -c ^
    -Wall
if errorlevel 1 (
    echo failed to compile %~1.cpp
    exit
)
exit /b 0