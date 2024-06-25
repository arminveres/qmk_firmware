# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
TAP_DANCE_ENABLE = yes

SRC += \
	tap_dance.c
	# WARN(aver): rgb does not have the stuff it need to be compiled anymore
	# rgb.c \
