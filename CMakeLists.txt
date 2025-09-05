cmake_minimum_required(VERSION 3.12)
project(adc LANGUAGES C)

add_library(avr-lib OBJECT
    adc/adc.c
)

target_include_directories(avr-lib PUBLIC include/)
