MOUSEKEY_ENABLE = no
AUDIO_ENABLE = no
DEBUG_ENABLE = no

MAC_KEYCODES = no
ifeq ($(MAC_KEYCODES),yes)
    OPT_DEFS += -DCB_MAC_KEYCODES
endif

SRC += src/backlin.c src/macro.c src/magnet.c src/secret.c
