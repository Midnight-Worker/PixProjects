#include "Game.h"

namespace mw {

void Game::init() {
}

void Game::update(unsigned long deltaTime) {
    (void)deltaTime;
}

void Game::draw(pixelroot32::graphics::Renderer& renderer) {
    renderer.drawFilledRectangle(
        0,
        0,
        renderer.getLogicalWidth(),
        renderer.getLogicalHeight(),
        pixelroot32::graphics::Color::Red
    );
}

} // namespace mw
