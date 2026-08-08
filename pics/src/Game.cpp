#include "Game.h"
#include <graphics/Color.h>

#include "assets/MoonMountainsBitmap.h"


namespace mw {

void Game::init() {
}

void Game::update(unsigned long deltaTime) {
    (void)deltaTime;
}

void Game::draw(pixelroot32::graphics::Renderer& renderer) {
  using pixelroot32::graphics::Color;

    // Schwarzer Hintergrund
    renderer.drawFilledRectangle(
        0,
        0,
        renderer.getLogicalWidth(),
        renderer.getLogicalHeight(),
        Color::Black
    );

    // Weiße 1-bpp-Bitmap darüberzeichnen
    renderer.drawBitmap(
        0,
        0,
        assets::MOON_MOUNTAINS_WIDTH,
        assets::MOON_MOUNTAINS_HEIGHT,
        assets::MOON_MOUNTAINS_BITMAP,
        Color::White
    );
}

} // namespace mw
