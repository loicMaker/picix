cmake_minimum_required(VERSION 3.13...3.27)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(picix)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project
add_executable(picix
  src/main.c
src/driver/audio.c
src/driver/audio.h
src/driver/clib.c
src/driver/display.c
src/driver/display.h
src/driver/fat32.c
src/driver/fat32.h
src/driver/font-5x10.c
src/driver/font-8x10.c
src/driver/font.h
src/driver/keyboard.c
src/driver/keyboard.h
src/driver/lcd.c
src/driver/lcd.h
src/driver/onboard_led.c
src/driver/onboard_led.h
src/driver/picocalc.c
src/driver/picocalc.h
src/driver/sdcard.c
src/driver/sdcard.h
src/driver/serial.c
src/driver/serial.h
src/driver/southbridge.c
src/driver/southbridge.h
)

add_subdirectory(no-OS-FatFS-SD-SDIO-SPI-RPi-Pico/src build)

pico_generate_pio_header(picix ${CMAKE_CURRENT_LIST_DIR}/src/driver/audio.pio)

target_link_libraries(picix
  no-OS-FatFS-SD-SDIO-SPI-RPi-Pico
  pico_stdlib
  hardware_pio
  hardware_dma
  hardware_spi
  hardware_i2c
  pico_status_led
)

pico_add_extra_outputs(picix)
