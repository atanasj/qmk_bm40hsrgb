SRC += muse.c

LTO_ENABLE = yes				# reduces files size dramatically
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
BOOTMAGIC_ENABLE = yes

VPATH  += keyboards/kprepublic/bm40hsrgb/keymaps/atanasj/combos/

RGB_MATRIX_ENABLE = no
COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes
EXTRAKEY_ENABLE = yes # Audio control and System control
UNICODEMAP_ENABLE = no
MIDI_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes
CAPS_WORD_ENABLE = yes
# KEY_OVERRIDE_ENABLE = yes
