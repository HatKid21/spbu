MAIN=main.cpp
APP=bin/example

mkdir -p bin

if [ -f $APP ]; then rm $APP
fi

g++ $MAIN -o $APP

./$APP
