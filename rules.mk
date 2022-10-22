SRC += muse.c

ifneq ($(strip $(NO_SECRETS)), yes)
    # NOTE needs to be in users for below line to work
    # ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
    ifneq ("$(wildcard keyboards/planck/keymaps/atanasj/secrets.c)","")
        SRC += secrets.c
    endif
endif

COMMAND_ENABLE = no
CONSOLE_ENABLE = no
LTO_ENABLE = yes				# reduces files size dramatically
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
