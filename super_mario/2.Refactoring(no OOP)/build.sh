FILES_TO_COMPILE="main.cpp object.cpp utils.cpp level.cpp physics.cpp render.cpp"
FILE_NAME="out"
DIRECTORY="bin"

FULL_PATH="$DIRECTORY/$FILE_NAME"

mkdir -p "$DIRECTORY"

g++ $FILES_TO_COMPILE -o "$FULL_PATH" -lncurses
