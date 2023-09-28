# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
EXTRAKEY_ENABLE = yes

SRC += \
	rgb.c \
	tap_dance.c \
	lib/arminveres/achordion.c \
	lib/arminveres/sentence_case.c \
	lib/arminveres/user_caps.c


CFLAGS += -Ilib/arminveres

CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUDIO_ENABLE = no
SPACE_CADET_ENABLE = no
