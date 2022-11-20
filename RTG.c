/*
 * RTG.c
 *
 *
 *
 */
#include "RTG.h"

// printf
int __io_putchar(int ch) {
	HAL_UART_Transmit(UART_1, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}

int _write(int file, char *ptr, int len) {
	HAL_UART_Transmit(UART_1, (uint8_t*) ptr, len, 0xFFFF);
	return len;
}

// scanf
int _read(int file, char *ptr, int len) {
	int ch = 0;
	HAL_UART_Receive(UART_1, (uint8_t*) &ch, 1, HAL_MAX_DELAY);
	HAL_UART_Transmit(UART_1, (uint8_t*) &ch, 1, HAL_MAX_DELAY);
	if (ch == 13) {
		ch = 10;
		HAL_UART_Transmit(UART_1, (uint8_t*) &ch, 1, HAL_MAX_DELAY);
	} else if (ch == 8) {
		ch = 0x30;
		HAL_UART_Transmit(UART_1, (uint8_t*) &ch, 1, HAL_MAX_DELAY);
	}
	*ptr = ch;
	return 1;
}

void rtg_main() {
	printf("Hello World\r\n");
	for (;;) {

		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);

	}

}

