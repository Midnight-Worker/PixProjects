#ifdef PLATFORM_ESP32S3

#include <Arduino.h>
#include <drivers/esp32/TFT_eSPI_Drawer.h>
#include  <core/Engine.h>
#include <platforms/EngineConfig.h>

#include "Game.h"

namespace pr32 = pixelroot32;

// Button Mapping (Arduino ESP32)
// Common mapping for 5-directional pad and A button
const int BTN_UP = 6;
const int BTN_DOWN = 15;
const int BTN_LEFT = 16;
const int BTN_RIGHT = 7;
const int BTN_A = 8;
const int BTN_B = 17;

pr32::graphics::DisplayConfig config(
    pr32::graphics::DisplayType::ST7735, 
    DISPLAY_ROTATION, 
    PHYSICAL_DISPLAY_WIDTH, 
    PHYSICAL_DISPLAY_HEIGHT,
    LOGICAL_WIDTH,
    LOGICAL_HEIGHT,
    X_OFF_SET,
    Y_OFF_SET
);

pr32::input::InputConfig inputConfig(BTN_UP, BTN_DOWN, BTN_LEFT, BTN_RIGHT, BTN_A, BTN_B); // 6 buttons: Up, Down, Left, Right, A, B

pr32::core::Engine engine(config, inputConfig);

mw::Game game;

void setup() {
    engine.init();
    engine.setScene(&game);
}

void loop() {
    engine.run();
}

#endif
