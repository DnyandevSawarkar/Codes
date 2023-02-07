#include "NS_Task_1_Sandbox.h"

/*
*
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
*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until black line is encountered
* Example Call: left_turn_wls(); //Turns right until black line is encountered
*
*/
void left_turn_wls(void)
{

}

/*
*
* Function Name: right_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn right until black line is encountered
* Example Call: right_turn_wls(); //Turns right until black line is encountered
*/
void right_turn_wls(void)
{
	

}

/*
*
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
		
		//_delay_ms(1500);
		
	}
}

void linedetect(void)
{ 
	unsigned char l= !ADC_Conversion(0);
	unsigned char m= ADC_Conversion(1);
	unsigned char r= ADC_Conversion(2);
	left();
	_delay_ms(40);
	forward();
	_delay_ms(1000);
	

	/*velocity(30, 30);
	forward();*/
	//_delay_ms(100);
	if (l > 200 || m > 200 || r > 200)
	{
		stop();
		_delay_ms(5000);
	}

	while (1)
	{
		
		/*velocity(30, 30);
		forward();
		_delay_ms(100);*/

		printf("Here");
		unsigned char l = !ADC_Conversion(0);
		unsigned char m = ADC_Conversion(1);
		 unsigned char r = ADC_Conversion(2);
		printf("%d %d %d \n",l,m,r);
		while (l == 0 && m == 0 && r == 0)
		{
			unsigned char l = ADC_Conversion(0);
			unsigned char m = ADC_Conversion(1);
			unsigned char r = ADC_Conversion(2);
			printf("Moving forward");
			velocity(30, 30);
			forward();
			_delay_ms(100);}

			if (l > 200 || m > 200 || r > 200)
			{
				int l = !ADC_Conversion(0);
				int m = ADC_Conversion(1);
				int r = ADC_Conversion(2);
				stop();
				_delay_ms(5000);

			}
			
	}
}

void linefollow(void)
{
	unsigned char l = !ADC_Conversion(0);
	unsigned char m = ADC_Conversion(1);
	unsigned char r = ADC_Conversion(2);
	/*left();
	_delay_ms(50);*/
	forward();
	_delay_ms(500);

	while (1)
	{
		printf("Here");
		unsigned char l = !ADC_Conversion(0);
		unsigned char m = ADC_Conversion(1);
		unsigned char r = ADC_Conversion(2);
		printf("%d %d %d \n", l, m, r);

		if (l > 250 || m > 250 || r > 250)
		{
			int l = !ADC_Conversion(0);
			int m = ADC_Conversion(1);
			int r = ADC_Conversion(2);
			stop();
			_delay_ms(1000);
			
		}
	
	}
}

void right_90(void)
{
	velocity(20, 20);
	forward();
	_delay_ms(30);
	velocity(70 ,20);
	right();
	_delay_ms(385);
	printf("Right \n");
}

void left_90(void)
{
	velocity(20, 20);
	forward();
	_delay_ms(30);
	velocity(20, 70);
	left();
	_delay_ms(385);
	printf("Left \n");
}

void straight(void)
{
	velocity(20, 20);
	forward();

	_delay_ms(150);
	printf("Straight \n");
}

void linefollow_1(void)
{
	unsigned char l = ADC_Conversion(1);
	unsigned char m = ADC_Conversion(2);
	unsigned char r = ADC_Conversion(3);
	unsigned char count = 0;
	velocity(20,20);
	forward();
	_delay_ms(75);
	while(1)
	{
		velocity(20, 20);
		forward();
		_delay_ms(50);
		printf("Value: ");
		unsigned char l = ADC_Conversion(1);
		unsigned char m = ADC_Conversion(2);
		unsigned char r = ADC_Conversion(3);
		printf(" % d % d % d \n", l, m, r);
		
		if (l == 0 && m == 255 && r == 0)
		{
			velocity(15, 15);
			forward();
			_delay_ms(50);	
		}
		else if(l == 255 && m == 255 && r == 255) //case 1
		{
			stop();
			_delay_ms(3000);

			count++; 
			printf("count: %d \n", count);
			if (count == 1 || count == 8)
			{
				
				left_90();
			}
			else if (count == 2 || count == 4 || count == 5 || count == 7)
			{
				
				straight();
			}
			else if (count == 3 || count == 6)
			{
			
				right_90();
			}
			

			//forward();
			//_delay_ms(5);
			
			/*velocity(50, 25);
			right();
			_delay_ms(420);*/
		
			
		}
		else if (l==255 && m == 0 && r == 0) //Case2
		{
			velocity(20,70);
			left();
			_delay_ms(90);
			
		} 
		else if (l == 0 && m == 0 && r==255) //case 3
		{
			 velocity(70, 20);
			 right();
			 _delay_ms(90);
			
		}
		
	}
}

/*
*
* Function Name: Task_1_1
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.1 logic
* Example Call: Task_1_1();
*/
void Task_1_1(void)
{
	
}

/*
*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.2 logic
* Example Call: Task_1_2();
*/
void Task_1_2(void)
{
	unsigned char l = ADC_Conversion(0);
	unsigned char m = !ADC_Conversion(1);
	unsigned char r = ADC_Conversion(2);
	unsigned char count = 0;
	velocity(20, 20);
	forward();
	_delay_ms(70);
	while (1)
	{
		velocity(20, 20);
		forward();
		_delay_ms(70);
		printf("Value: ");
		unsigned char l = ADC_Conversion(0);
		unsigned char m = !ADC_Conversion(1);
		unsigned char r = ADC_Conversion(2);
		printf("%d %d %d \n", l, m, r);
		if (l == 0 && m == 255 && r == 0)
		{
			velocity(20, 20);
			forward();
			_delay_ms(75);
		}
		else if (l == 255 && m == 255 && r == 255)
		{
			stop();
			_delay_ms(2000);
			/*count++;
			if (count == 1 || count == 2 || count == 4)
			{
				straight();
			}
			else if (count == 3)
			{
				left_90();
			}*/
		}

	}
}
