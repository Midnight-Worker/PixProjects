#pragma once

#ifdef PLATFORM_ESP32S3

#include <Arduino.h>

struct ButtonPin {
    const char* name;
    uint8_t gpio;
};

static constexpr ButtonPin BUTTONS[] = {
    {"A / HOCH",          6},
    {"C / RUNTER",       15},
    {"D / LINKS",        16},
    {"B / RECHTS",        7},
    {"STICK / FEUER",      8},
    {"E / AKTION",        17}
};

static constexpr size_t BUTTON_COUNT =
    sizeof(BUTTONS) / sizeof(BUTTONS[0]);

bool previousStates[BUTTON_COUNT];

void printAllButtonStates() {
    Serial.println();
    Serial.println("Aktuelle Pinzustaende:");

    for (size_t i = 0; i < BUTTON_COUNT; ++i) {
        const bool rawState = digitalRead(BUTTONS[i].gpio);

        Serial.printf(
            "%-16s GPIO %-2u = %s%s\n",
            BUTTONS[i].name,
            BUTTONS[i].gpio,
            rawState ? "HIGH" : "LOW",
            rawState ? "  nicht gedrueckt?" : "  gedrueckt?"
        );
    }

    Serial.println();
}

void setup() {
    Serial.begin(115200);

    delay(1500);

    Serial.println();
    Serial.println("================================");
    Serial.println(" ESP32-S3 Game-Shield Pin-Test");
    Serial.println("================================");

    for (size_t i = 0; i < BUTTON_COUNT; ++i) {
        pinMode(BUTTONS[i].gpio, INPUT_PULLUP);
        previousStates[i] = digitalRead(BUTTONS[i].gpio);

        Serial.printf(
            "%-16s -> GPIO %u, Startzustand: %s\n",
            BUTTONS[i].name,
            BUTTONS[i].gpio,
            previousStates[i] ? "HIGH" : "LOW"
        );
    }

    Serial.println();
    Serial.println("Jetzt die Tasten einzeln druecken.");
    Serial.println("Bei INPUT_PULLUP erwarten wir:");
    Serial.println("losgelassen = HIGH");
    Serial.println("gedrueckt   = LOW");

    printAllButtonStates();
}

void loop() {
    for (size_t i = 0; i < BUTTON_COUNT; ++i) {
        const bool currentState =
            digitalRead(BUTTONS[i].gpio);

        if (currentState != previousStates[i]) {
            delay(20);

            const bool debouncedState =
                digitalRead(BUTTONS[i].gpio);

            if (debouncedState != previousStates[i]) {
                previousStates[i] = debouncedState;

                Serial.printf(
                    "%-16s GPIO %-2u -> %s\n",
                    BUTTONS[i].name,
                    BUTTONS[i].gpio,
                    debouncedState
                        ? "LOSGELASSEN / HIGH"
                        : "GEDRUECKT / LOW"
                );
            }
        }
    }

    delay(1);
}

#endif
