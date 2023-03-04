'''
*****************************************************************************************
*
*        		===============================================
*           		Berryminator (BM) Theme (eYRC 2021-22)
*        		===============================================
*
*  This script is to implement Task 1A of Berryminator(BM) Theme (eYRC 2021-22).
*
*  This software is made available on an "AS IS WHERE IS BASIS".
*  Licensee/end user indemnifies and will keep e-Yantra indemnified from
*  any and all claim(s) that emanate from the use of the Software or
*  breach of the terms of this agreement.
*
*****************************************************************************************
'''

# Team ID:			[ BM_1437 ]
# Author List:		[ Shreyash Sarage, Vaishnavi Panse, Ankit Kriti, Jaison Jose ]
# Filename:			task_1a.py
# Functions:		[ detect_colors, detect_shapes, get_labeled_image ]

####################### IMPORT MODULES #######################
## You are not allowed to make any changes in this section. ##
## You have to implement this task with the three available ##
## modules for this task (numpy, opencv, os)                ##
##############################################################
import cv2
import numpy as np
import os
##############################################################

################# ADD UTILITY FUNCTIONS HERE #################

def detect_colors(color_ls):

	"""
	Purpose:
	---
	This function detects the color of shapes present in an image
	---
	Input Arguments:
	---
	color_ls : [ list ]
			 list of colour value present at the centroid
	---
	Returns:
	---
	color : [ string ]
			name of detected colour

	"""
	if color_ls[0]<100 and color_ls[1]<100 and color_ls[2]>100:
		color= "Red"
	if color_ls[0]<100 and color_ls[1]>100 and color_ls[2]<100:
		color="Green"
	if color_ls[0]>100 and color_ls[1]<100 and color_ls[2]<100:
		color="Blue"
	if color_ls[0]<100 and color_ls[1]>100 and color_ls[2]>100:
		color="Orange"

	return color

##############################################################

def detect_shapes(img):

	"""
	Purpose:
	---
	This function takes the image as an argument and returns a nested list
	containing details of colored (non-white) shapes in that image

	Input Arguments:
	---
	`img` :	[ numpy array ]
			numpy array of image returned by cv2 library

	Returns:
	---
	`detected_shapes` : [ list ]
			nested list containing details of colored (non-white)
			shapes present in image

	Example call:
	---
	shapes = detect_shapes(img)
	"""
	detected_shapes = []

	##############	ADD YOUR CODE HERE	##############
	# Converting BGR image to Grayscale
	gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

	# Thresholding(binarization of an image)
	_, threshold = cv2.threshold(gray, 170, 200, cv2.THRESH_BINARY_INV)

	# Finding contours from threshold image
	contours, _ = cv2.findContours(threshold, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

	# For detecting contours
	for contour in contours:

		# Approximation of polygons
		approx = cv2.approxPolyDP(contour, 0.02 * cv2.arcLength(contour, True), True)

		# For drawing contours
		cv2.drawContours(img, [contour], 0, (155, 155, 155), 5)

		'''
		Image Moments:
		---
		cv2.moments: [ Image Moment is a particular weighted average of image pixel intensities,
		with the help of which we can find some specific properties of an image,
		like radius, area, centroid etc. ]
		'''
		M = cv2.moments(contour)
		if M['m00']:
			x,y=int(M['m10']/M['m00']),int(M['m01']/M['m00'])

		# Get the colour from the centroid of each shape
		color_ls=img[y,x]
		
		# Co-ordinates of centroid
		centroid=(x,y)

		# Conditions for shapes detection
		if len(approx) == 3:
			color=detect_colors(color_ls)
			shape="Triangle"

		if ((len(approx) == 4)):
			(_,_, w, h) = cv2.boundingRect(approx)
			if  abs(w-h)<3:
				color=detect_colors(color_ls)
				shape="Square"
			else:
				color=detect_colors(color_ls)
				shape="Rectangle"

		if len(approx) == 5:
			color=detect_colors(color_ls)
			shape="Pentagon"

		if len(approx) > 5:
			color=detect_colors(color_ls)
			shape="Circle"

		# List containing color, shape and coordinates is appended to detected_shapes
		ls=[color,shape,centroid]
		detected_shapes.append(ls)

	##################################################

	return detected_shapes

def get_labeled_image(img, detected_shapes):
	######### YOU ARE NOT ALLOWED TO MAKE CHANGES TO THIS FUNCTION #########
	"""
	Purpose:
	---
	This function takes the image and the detected shapes list as an argument
	and returns a labelled image

	Input Arguments:
	---
	`img` :	[ numpy array ]
			numpy array of image returned by cv2 library

	`detected_shapes` : [ list ]
			nested list containing details of colored (non-white)
			shapes present in image

	Returns:
	---
	`img` :	[ numpy array ]
			labelled image

	Example call:
	---
	img = get_labeled_image(img, detected_shapes)
	"""
	######### YOU ARE NOT ALLOWED TO MAKE CHANGES TO THIS FUNCTION #########

	for detected in detected_shapes:
		colour = detected[0]
		shape = detected[1]
		coordinates = detected[2]
		cv2.putText(img, str((colour, shape)),coordinates, cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0,0,0), 2)
	return img

if __name__ == '__main__':

	# path directory of images in 'test_images' folder
	img_dir_path = 'G:/Codes/Python/CV/Final_task/test_images/'

	# path to 'test_image_1.png' image file
	file_num = 1
	img_file_path = img_dir_path + 'test_image_' + str(file_num) + '.png'

	# read image using opencv
	img = cv2.imread(img_file_path)

	print('\n============================================')
	print('\nFor test_image_' + str(file_num) + '.png')

	# detect shape properties from image
	detected_shapes = detect_shapes(img)
	print(detected_shapes)

	# display image with labeled shapes
	img = get_labeled_image(img, detected_shapes)
	cv2.imshow("labeled_image", img)
	cv2.waitKey(2000)
	cv2.destroyAllWindows()

	choice = input('\nDo you want to run your script on all test images ? => "y" or "n": ')

	if choice == 'y':

		for file_num in range(1, 16):

			# path to test image file
			img_file_path = img_dir_path + 'test_image_' + str(file_num) + '.png'

			# read image using opencv
			img = cv2.imread(img_file_path)

			print('\n============================================')
			print('\nFor test_image_' + str(file_num) + '.png')

			# detect shape properties from image
			detected_shapes = detect_shapes(img)
			print(detected_shapes)

			# display image with labeled shapes
			img = get_labeled_image(img, detected_shapes)
			cv2.imshow("labeled_image", img)
			cv2.waitKey(2000)
			cv2.destroyAllWindows()


