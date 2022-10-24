#pragma once
#include "backlin.h"

void reverse_diacritic(uint16_t modcode, uint16_t keycode);
void tmux_command(uint8_t mods, uint16_t keycode);
void macro_pressed(uint16_t keycode);
void enter_tmux_copy_mode(void);
