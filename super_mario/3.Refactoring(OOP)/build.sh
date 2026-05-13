FILES_TO_COMPILE="main.cpp brick.cpp gameObject.cpp level.cpp renderer.cpp player.cpp enemy.cpp game.cpp keyboard.cpp"
FILE_NAME="out"
DIRECTORY="bin"

FULL_PATH="$DIRECTORY/$FILE_NAME"

mkdir -p "$DIRECTORY"

g++ $FILES_TO_COMPILE -o "$FULL_PATH" -lncurses
