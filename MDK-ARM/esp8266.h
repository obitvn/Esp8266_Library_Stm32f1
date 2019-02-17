#ifndef ESP8266_H_
#define ESP8266_H_


#include <stdbool.h>
#include "stm32f1xx_hal.h"
//#include "stm32f1xx_hal_uart.h"

#include "ObitString.h"

//////////////////////////////////////////////


#define ESP8266_UART                    huart1
#define ESP8266_UART_BUFFER_MAX_SIZE     512

#define DISABLE 0
#define ENABLE 1

enum ESP8266_RESPONSE_STATUS{
	ESP8266_RESPONSE_WAITING,
	ESP8266_RESPONSE_FINISHED,
	ESP8266_RESPONSE_TIMEOUT,
	ESP8266_RESPONSE_BUFFER_FULL,
	ESP8266_RESPONSE_STARTING,
	ESP8266_RESPONSE_ERROR
};

enum ESP8266_CONNECT_STATUS {
	ESP8266_CONNECTED_TO_AP,
	ESP8266_CREATED_TRANSMISSION,
	ESP8266_TRANSMISSION_DISCONNECTED,
	ESP8266_NOT_CONNECTED_TO_AP,
	ESP8266_CONNECT_UNKNOWN_ERROR
};

enum ESP8266_JOINAP_STATUS {
	ESP8266_WIFI_CONNECTED,
	ESP8266_CONNECTION_TIMEOUT,
	ESP8266_WRONG_PASSWORD,
	ESP8266_NOT_FOUND_TARGET_AP,
	ESP8266_CONNECTION_FAILED,
	ESP8266_JOIN_UNKNOWN_ERROR
};






//////////



extern UART_HandleTypeDef ESP8266_UART;
////////////////////////////////////
void ESP8266_Restart();
void ESP8266_Echo(uint8_t value);
uint8_t ESP8266_Init();
uint8_t ESP8266_JoinAccessPoint(const char* _SSID, const char* _PASSWORD);

///////////////////////////////////////////////
void ESP8266_USART_IRQHandler(void);
bool Esp8266_SendAtCommand(uint8_t* AtCommand, uint8_t AtLength, uint32_t Time_out, uint8_t* answer, uint8_t AnsLength, uint8_t clear_buffer);
void Esp8266_SendAtNotWaitResponse(uint8_t *str, uint16_t str_len);
uint8_t Esp8266_WaitForStringInTimeOut( uint8_t *str, uint16_t str_len, uint16_t time_out);
void Esp8266_WaitForString( uint8_t *str, uint16_t str_len);




/////////////////////////////////////////////
#endif