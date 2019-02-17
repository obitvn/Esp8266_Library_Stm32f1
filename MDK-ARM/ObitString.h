#ifndef OBITSTRING_H_
#define OBITSTRING_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "stm32f1xx_hal.h"


void obit_split_string(uint8_t *str_in, uint8_t size_str_in,uint8_t char_begin, uint8_t frequency_char_begin, uint8_t char_end, uint8_t frequency_char_end, uint8_t *str_out, uint8_t size_str_out);

int obit_strcmp(uint8_t *str_expected,uint8_t size_str_expected, uint8_t *str_real, uint8_t size_str_real);


#endif