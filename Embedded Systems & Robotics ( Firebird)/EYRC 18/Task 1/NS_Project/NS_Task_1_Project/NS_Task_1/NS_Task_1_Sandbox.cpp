#include "NS_Task_1_Sandbox.h"

/*
* Function Name: forward_wls
* Input: node
* Output: void
* Logic: Uses white line sensors to go forward by the number of nodes specified
* Example Call: forward_wls(2); //Goes forward by two nodes
*
*/
void forward_wls()
{
	
}

/*
* Function Name: linedetect()
* Input: void
* Output: void
* Logic: Uses white line sensors to stop movement when black line is encountered
* Example Call: linedetect(); //stop movement when black line is encountered
*/

void linedetect(void)
{
	
	while (1)
	{
		int ch1 = ADC_Conversion(1); // left white line sensor
		int ch2 = ADC_Conversion(2); // mid white line sensor
		int ch3 = ADC_Conversion(3); // right white line sensor
		printf("\nch1 %d ch2 %d ch3 %d \n", ch1, ch2, ch3);
		_delay_ms(2);
		velocity(10, 10);
		if (ch2==241)
		{
			stop();
			printf("\nSTOP ch1 %d ch2 %d ch3 %d \n", ch1, ch2, ch3);
			
			_delay_ms(500);
			break;
		}
		else
		{
			printf("GO ch1 %d ch2 %d ch3 %d \n", ch1, ch2, ch3);
			forward();
			_delay_ms(1);
		}
	}
}

/*
* Function Name: pathcheck
* Input: void
* Output: void
* Logic: Use this function to make the robot find path on the arena when it get out off path
* Example Call: pathcheck();
*/

void pathcheck(void)
{
	while (1)
	{
		int ch1 = ADC_Conversion(1); // left white line sensor
		int ch2 = ADC_Conversion(2); // mid white line sensor
		int ch3 = ADC_Conversion(3); // right white line sensor
		printf("\nch1 %d ch2 %d ch3 %d \n", ch1, ch2, ch3);

		soft_right();
		_delay_ms(1);
		stop();
		_delay_ms(1);
		printf("\n finding \n");
		if (ch1 != 0 || ch2 != 0 || ch3 != 0)
		{
			printf("\t\t\t\tStop ");
			break;
		}
	}
}

/*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until black line is encountered
* Example Call: left_turn_wls(); //Turns right until black line is encountered
*
*/
void left_turn_wls(void)
{
	printf("\t\t\tLEFT TURN ");
	velocity(5, 5);
	soft_left();
	_delay_ms(1);
}

/*
* Function Name: right_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn right until black line is encountered
* Example Call: right_turn_wls(); //Turns right until black line is encountered
*/
void right_turn_wls(void)
{
	printf("\t\t\tRight TURN ");
	velocity(5, 5);
	soft_right();
	_delay_ms(1);
}


/*
* Function Name: Square
* Input: void
* Output: void
* Logic: Use this function to make the robot trace a square path on the arena
* Example Call: Square();
*/

void Square(void)
{
	while (1)
	{
		for (int s = 2; s < 6; s++)
		{
			s--;
			forward();      // side 1
			printf("\n side %d", s);
			_delay_ms(2000);
			s++;
			left();			// turn to side 2
			_delay_ms(810);
			if(s<=4)
				printf("\n turning to side %d", s);
		}
		stop();
		printf("\n Stoped \n");
		break;
	}
}

/*
* Function Name: linefollow
* Input: void
* Output: void
* Logic: Use this function to make the robot follow line path on the arena
* Example Call: linefollow();
*/

void linefollow(void)
{
	//linedetect();
	//_delay_ms(1);
	while (1)
	{
		int ch1 = ADC_Conversion(1); // left white line sensor
		int ch2 = ADC_Conversion(2); // mid white line sensor
		int ch3 = ADC_Conversion(3); // right white line sensor
		printf("\nch1 %d ch2 %d ch3 %d \n", ch1, ch2, ch3);
		if (ch1 > 0 && ch2 <= 241 && ch3 == 0)
		{
			left_turn_wls();
		}
		else if (ch1 == 0 && ch2 <= 241  && ch3 > 0)
		{
			right_turn_wls();
		}
		else if ( (ch1 == 0 && ch2 == 0 && ch3 == 0) || (ch1 == 241 && ch2 == 241 && ch3 == 241) || (ch1 == 0 && ch2 == 241 && ch3 == 0))
		{
			pathcheck();
		}
	}
}

/*
* Function Name: Task_1_1   
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.1 logic
* Example Call: Task_1_1();
*/
void Task_1_1(void)
{
	int n_count = 0;
	velocity(5, 5);
	while (1)
	{
		int ch1 = ADC_Conversion(1); // left white line sensor
		int ch2 = ADC_Conversion(2); // mid white line sensor
		int ch3 = ADC_Conversion(3); // right white line sensor
		printf("\nch1 %d ch2 %d ch3 %d \n", ch1, ch2, ch3);

		if (ch1 == 0 && ch2 == 255 && ch3 == 0)
		{
			forward();
			_delay_ms(1);
			printf("node counted %d", n_count);
		}

		if (ch1 == 255 && ch2 == 255 && ch3 == 255)
		{
			_delay_ms(1);
			printf("\n\t\t.......Node Identified......\t\t\n");
			n_count++;
		}

		if  ( (ch1 > 0 && ch2 <= 241 && ch3 == 0) && (n_count == 1 || n_count == 8) )
		{
			left_turn_wls();
		}
		
		if ( (ch1 == 0 && ch2 <= 241 && ch3 > 0) && (n_count == 3 || n_count == 6))
		{
			right_turn_wls();
		}
		
	}
}

/*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.2 logic
* Example Call: Task_1_2();
*/
void Task_1_2(void)
{
	
}
