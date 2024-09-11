
#include "stdTypes.h"
#include "errorStates.h"
#include "DIO_int.h"
#include "Switch_config.h"
#include "Switch_int.h"
#include <util\delay.h>

extern SW_t Switch_ArrayStrSwitchStates[SW_NUM];


int main()
{

	DIO_enumInt();
	Switch_enumInt(Switch_ArrayStrSwitchStates);       // pass adress array
	u8 PinState;
	DIO_enumSetPinDirection(DIO_u8PORTA ,DIO_u8PIN0 , DIO_u8OUTPUT);
	while(1)
	{
		Switch_enumGetState(&Switch_ArrayStrSwitchStates[1] ,&PinState);       //switch on portD , pin3 , pullup::pressed is 0
		if(PinState==0)        //presssed
		{
			DIO_enumSetPinValue(DIO_u8PORTA ,DIO_u8PIN0 , DIO_u8HIGH);
			_delay_ms(200);

		}
		else
			DIO_enumSetPinValue(DIO_u8PORTA ,DIO_u8PIN0 , DIO_u8LOW);


	}


}
