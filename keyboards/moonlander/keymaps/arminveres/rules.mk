# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUDIO_ENABLE = no
TAP_DANCE_ENABLE = yes
SPACE_CADET_ENABLE = no
CAPS_WORD_ENABLE = yes

SRC += \
	matrix.c \
	tap_dance.c \
	rgb.c

CFLAGS += -Ilib/arminveres

LIB_SRC += \
	lib/arminveres/achordion.c \
	lib/arminveres/sentence_case.c
