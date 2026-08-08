#pragma once

#include <core/Scene.h>
#include <graphics/Renderer.h>

namespace mw {

class Game : public pixelroot32::core::Scene {
public:
    void init() override;
    void update(unsigned long deltaTime) override;
    void draw(pixelroot32::graphics::Renderer& renderer) override;

private:
    float playerX = 20.0f;
    float playerY = 20.0f;

    static constexpr int PLAYER_WIDTH = 16;
    static constexpr int PLAYER_HEIGHT = 16;

    static constexpr float PLAYER_SPEED = 100.0f;

    static constexpr uint8_t INPUT_UP    = 0;
    static constexpr uint8_t INPUT_DOWN  = 1;
    static constexpr uint8_t INPUT_LEFT  = 2;
    static constexpr uint8_t INPUT_RIGHT = 3;
};

} // namespace mw
