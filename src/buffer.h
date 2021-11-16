/*!
	\file buffer.h
	\brief Файл, обеспечивающий работу буфера хранения данных
	\author Gorin Alexey
*/

#ifndef _BUFFER
#define  BUFFER_EXTLBL 					extern
#else
#define  BUFFER_EXTLBL 
#endif



/*!
	\brief Функция инициализации состояния буфера
*/
BUFFER_EXTLBL void buffer_Init (void);

/*!
	\brief Функция добавления байта в буффер
	\param[in] data Байт данных для добавления
	\return Признак готовности блока данных к передаче. 
		-1 - блок не сформирован, 
		n - индекс первого элемента в блоке.
*/
BUFFER_EXTLBL int buffer_push (uint8_t);


BUFFER_EXTLBL uint8_t 	buffer [256]; 	//!< Массив для хранения данных
BUFFER_EXTLBL int 		buffer_len; 	//!< Количество байт в буфере
BUFFER_EXTLBL int 		buffer_ind; 	//!< Индекс первого элемента в незавершённом блоке данных
