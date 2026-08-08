#include "Game.h"
#include <core/Engine.h>

namespace pr32 = pixelroot32;

extern pr32::core::Engine engine;

namespace mw {

void Game::init() {
    playerX = 20;
    playerY = 20;
}

void Game::update(unsigned long deltaTime) {
    auto& input = engine.getInputManager();
    const float movement = PLAYER_SPEED * deltaTime / 1000.0f;

    if (input.isButtonDown(INPUT_UP))    playerY -= movement;
    if (input.isButtonDown(INPUT_DOWN))  playerY += movement;
    if (input.isButtonDown(INPUT_LEFT))  playerX -= movement;
    if (input.isButtonDown(INPUT_RIGHT)) playerX += movement;

    const float maxX = LOGICAL_WIDTH  - PLAYER_WIDTH;
    const float maxY = LOGICAL_HEIGHT - PLAYER_HEIGHT;

    if (playerX < 0)    playerX = 0;
    if (playerY < 0)    playerY = 0;
    if (playerX > maxX) playerX = maxX;
    if (playerY > maxY) playerY = maxY;
}

void Game::draw(pr32::graphics::Renderer& renderer) {
    renderer.drawFilledRectangle(
        0, 0,
        renderer.getLogicalWidth(),
        renderer.getLogicalHeight(),
        pr32::graphics::Color::Black
    );

    renderer.drawFilledRectangle(
        playerX, playerY,
        PLAYER_WIDTH, PLAYER_HEIGHT,
        pr32::graphics::Color::Red
    );
}

} // namespace mw
