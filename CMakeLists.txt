cmake_minimum_required(VERSION 3.12)
project(avr-lib LANGUAGES C)

# --- AVR CONFIG ---
set(MCU "atmega328")
set(CLOCK_SPEED "16000000") # in Hz
set(PROGRAMMER "usbasp")
set(AVRDUDE_ARGS -p ${MCU} -c ${PROGRAMMER})

add_compile_options(-mmcu=${MCU})
add_compile_definitions(F_CPU=${CLOCK_SPEED}UL)
add_link_options(-mmcu=${MCU})

add_library(${PROJECT_NAME} STATIC
			src/adc/adc.c
			src/pwm/pwm.c
)

target_include_directories(avr-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# add_library(avr-lib STATIC
#     src/adc/adc.c
# )
#
