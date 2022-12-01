#include <gb\gb.h>
#include <stdio.h>

void print_32(char* p) {
  p = p + 3;
  for (uint8_t i = 4; i > 0; i--) {
    printf("%hx", (void *)*p);
    p--;
  }
}