#include "game.hpp"

using hatkid::Game;

Game::Game(){
    renderer = Renderer();
    player = Player();
    level = Level();
}

~Game() = default;
