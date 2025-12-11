FILES="menuFunctions.cpp menuItems.cpp main.cpp"
DIST="bin/example"

mkdir -p bin

g++ $FILES -o $DIST

./$DIST
