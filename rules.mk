SRC += muse.c

LTO_ENABLE = yes				# reduces files size dramatically
BOOTMAGIC_ENABLE = lite
# keep path to combos local to my keymap

VPATH  +=  keyboards/kprepublic/bm40hsrgb/keymaps/atanasj/combos/

COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes
EXTRAKEY_ENABLE = yes # Audio control and System control
UNICODEMAP_ENABLE = no
MIDI_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes
