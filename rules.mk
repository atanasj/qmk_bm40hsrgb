SRC += muse.c

ifneq ($(strip $(NO_SECRETS)), yes)
    # NOTE needs to be in users for below line to work
    # ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
    ifneq ("$(wildcard keyboards/bm40hsrgb/keymaps/atanas/secrets.c)","")
        SRC += secrets.c
    endif
endif

COMMAND_ENABLE = no
CONSOLE_ENABLE = no
LTO_ENABLE = yes				# yes for bm40rgbhs

VPATH  += keyboards/planck/keymaps/atanasj/combos/

COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = yes
UNICODE_ENABLE = no
NKRO_ENABLE = yes
AUDIO_ENABLE = no				# no for bm40rgbhs
MIDI_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes
