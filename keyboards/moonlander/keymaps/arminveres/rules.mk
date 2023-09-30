# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
TAP_DANCE_ENABLE = yes

SRC += \
	rgb.c \
	tap_dance.c
