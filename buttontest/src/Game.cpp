#include "Game.h"

#include <core/Engine.h>

namespace pr32 = pixelroot32;

extern pr32::core::Engine engine;

namespace mw {

void Game::init() {
    playerX = 20.0f;
    playerY = 20.0f;
}

void Game::update(unsigned long deltaTime) {
    auto& input = engine.getInputManager();

    const float deltaSeconds =
        static_cast<float>(deltaTime) / 1000.0f;

    const float movement =
        PLAYER_SPEED * deltaSeconds;

    // Taste A auf dem Shield
    if (input.isButtonDown(0)) {
        playerY -= movement;
    }

    // Taste C auf dem Shield
    if (input.isButtonDown(1)) {
        playerY += movement;
    }

    // Taste D auf dem Shield
    if (input.isButtonDown(2)) {
        playerX -= movement;
    }

    // Taste B auf dem Shield
    if (input.isButtonDown(3)) {
        playerX += movement;
    }

    const float maxX =
        static_cast<float>(LOGICAL_WIDTH - PLAYER_WIDTH);

    const float maxY =
        static_cast<float>(LOGICAL_HEIGHT - PLAYER_HEIGHT);

    if (playerX < 0.0f) {
        playerX = 0.0f;
    }

    if (playerY < 0.0f) {
        playerY = 0.0f;
    }

    if (playerX > maxX) {
        playerX = maxX;
    }

    if (playerY > maxY) {
        playerY = maxY;
    }
}

void Game::draw(pr32::graphics::Renderer& renderer) {
    renderer.drawFilledRectangle(
        0,
        0,
        renderer.getLogicalWidth(),
        renderer.getLogicalHeight(),
        pr32::graphics::Color::Black
    );

    renderer.drawFilledRectangle(
        static_cast<int>(playerX),
        static_cast<int>(playerY),
        PLAYER_WIDTH,
        PLAYER_HEIGHT,
        pr32::graphics::Color::Red
    );
}

} // namespace mw
