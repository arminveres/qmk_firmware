OLED_ENABLE = yes
OLED_DRIVER = SSD1306
ENCODER_ENABLE = yes
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
WPM_ENABLE = yes
TRI_LAYER_ENABLE = yes
# TAP_DANCE_ENABLE = yes

# Bootloader/ MCU configs
BOOTLOADER = rp2040
PROCESSOR = cortex-m0plus
CONVERT_TO = rp2040_ce

SRC += \
	oled.c \
	encoder.c

CFLAGS += -Ilib/arminveres

LIB_SRC += \
	lib/arminveres/achordion.c \
	lib/arminveres/sentence_case.c

