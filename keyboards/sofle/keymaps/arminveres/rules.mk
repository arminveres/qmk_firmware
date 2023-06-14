OLED_ENABLE = yes
OLED_DRIVER = SSD1306
ENCODER_ENABLE = yes
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes
BOOTLOADER = rp2040
PROCESSOR = cortex-m0plus
CONVERT_TO = rp2040_ce

SRC += \
	oled.c \
	encoder.c \
	features/achordion.c
