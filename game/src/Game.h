#pragma once

#include <core/Scene.h>
#include <graphics/Renderer.h>

namespace mw {

class Game : public pixelroot32::core::Scene {
public:
    void init() override;
    void update(unsigned long deltaTime) override;
    void draw(pixelroot32::graphics::Renderer& renderer) override;
};

} // namespace mw
