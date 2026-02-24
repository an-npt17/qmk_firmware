/* Seniply Configuration for Sofle V1 */
#pragma once

// One-shot modifier settings
#define ONESHOT_TAP_TOGGLE 2    // Tapping this many times holds the key until tapped again
#define ONESHOT_TIMEOUT 3000    // Time (in ms) before one-shot keys expire

// Tapping term for layer-tap keys
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// Prevent accidental double-taps
#define QUICK_TAP_TERM 0

// Enable Caps Word (auto-disable after space/special chars)
#define CAPS_WORD_IDLE_TIMEOUT 5000

// Encoder resolution
#define ENCODER_RESOLUTION 4

// OLED settings
#ifdef OLED_ENABLE
    #define OLED_TIMEOUT 30000
    #define OLED_BRIGHTNESS 120
#endif

// USB polling rate (1000Hz for responsive input)
#define USB_POLLING_INTERVAL_MS 1
