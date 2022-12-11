#pragma once
#include "backlin.h"
#include <stdlib.h>
#include <string.h>

void reverse_diacritic(uint16_t modcode, uint16_t keycode);

void tmux_command(uint16_t mods, uint16_t keycode);
void tmux_new_session(void);
void enter_tmux_copy_mode(void);

enum flag_state {Unchanged, None, Record, Update, RecordUpdate};

void jetbrains_reset(void);
void jetbrains_pressed(uint16_t keycode);
void jetbrains_released(uint16_t keycode);
void jetbrains_run(bool new_test, bool debug);

void process_macro(uint16_t keycode, bool pressed);

#ifdef CB_BOXDRAW_ENABLE
void send_unicode(uint16_t k1, uint16_t k2, uint16_t k3, uint16_t k4);
#endif
