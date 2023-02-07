
# No other modules apart from 'argparse' need to be imported
# as they aren't required to solve the assignment

# Import required module/s
import argparse


def raise_power_of_N():
	"""Computes square of positional argument (N) and cube as well if optional argument 'c' or 'cube' is passed.

	Example
	-------
	$ python3 assignment1.py -h
	
	usage: assignment1.py [-h] [-c] N
	
	Calculate square and/or cube of N

	positional arguments:
		N           input the number

	optional arguments:
		-h, --help  show this help message and exit
		-c, --cube  calculate cube of N as well
	
	Week-5 Assignment-1

	=======

	$ python3 assignment1.py 5

	Square of N: 25

	=======

	$ python3 assignment1.py 5 -c
	OR
	$ python3 assignment1.py 5 --cube

	Square of N: 25
	Cube of N: 125
	"""

	##############	ADD YOUR CODE HERE	##############
	parser = argparse.ArgumentParser(description='Calculate square and/or cube of N',epilog='Week-5 Assignment-1',prefix_chars='-')
	parser.add_argument("N",type=int,help="input the number")
	parser.add_argument("-c","--cube",type=int,help="calculate cube of N as well")
	args = parser.parse_args()
	
	#args.accumulate(args.N)
	#args.N==args.cube
	#sq=args.N**2
	#cu=args.cube**3
	if args.N == 2:
    		print("Square of N:",args.N**2)
	elif args.cube== 3:
    		print("Cube of N:",args.cube**3)
	#else:
		#print("Square of N:",args.N**2)
		#print("Cube of N:",args.cube**3)
	
	##################################################
'''parser = argparse.ArgumentParser(prog='assignment1',usage='%(prog)s [-h] [-c] N ',description='Calculate square and/or cube of 		N',epilog='Week-5 Assignment-1',prefix_chars='-')
	parser.add_argument("N", help="input the number",type=int)
	parser.add_argument("-c", action="store", type=int, required=True,help="calculate cube of N as well")
	#parser.add_argument('--cube',action='store_true',required=True,help='calculate cube of N as well')
	args = parser.parse_args()
	a=(args.N**2)
	
	#parser.add_argument('-c',action='store_true',required=True,help='calculate cube of N as well')
	
	b=(args.c**3)'''
	
                                  
                                    

if __name__ == "__main__":
	"""Main function, code begins here
	"""
	raise_power_of_N()
