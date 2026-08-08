#include "Game.h"
#include <graphics/Color.h>

namespace mw {

void Game::init() {
}

void Game::update(unsigned long deltaTime) {
    (void)deltaTime;
}

void Game::draw(pixelroot32::graphics::Renderer& renderer) {
    using pixelroot32::graphics::Color;
    // Hintergrund
    renderer.drawFilledRectangle(
        0,
        0,
        renderer.getLogicalWidth(),
        renderer.getLogicalHeight(),
        Color::Black
    );

    // Linie
    renderer.drawLine(
        10, 10,       // Start: x1, y1
        100, 40,      // Ende:  x2, y2
        Color::White
    );

    // Rechteck als Umriss
    renderer.drawRectangle(
        10, 50,       // x, y
        60, 30,       // Breite, Höhe
        Color::Red
    );

    // Gefülltes Rechteck
    renderer.drawFilledRectangle(
        80, 50,
        60, 30,
        Color::Blue
    );

    // Kreis als Umriss
    renderer.drawCircle(
        40, 120,      // Mittelpunkt x, y
        20,           // Radius
        Color::Green
    );

    // Gefüllter Kreis
    renderer.drawFilledCircle(
        100, 120,
        20,
        Color::Yellow
    );
}

} // namespace mw
