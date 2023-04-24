import time

import cv2
import pytesseract

import serial
import requests

flag_msg = 0
flag_plate = 0
'''
def send_notification():
    url = 'https://maker.ifttt.com/trigger/Automatic_Garage_Door/with/key/hbRa-jg4Om6aLsw1Zqo6yPC715P25SfUEkikQ5PxH15'
    requests.post(url)
'''
def numper_plate():
    # Read the saved number plate from a file
    #saved_number_plate = "MH49R33899"
    saved_number_plate = "MH 49 R 3389"
    '''
    # Capture an image using the camera
    camera = cv2.VideoCapture(0)

    for i in range(30):
        _, image = camera.read()
    camera.release()    
    '''
    image = cv2.imread(r"G:\Codes\Python\Mini_Project\2.jpeg")
    #image = cv2.resize(i_image,(800,600),interpolation = cv2.INTER_AREA)
    # Convert the image to grayscale
    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Apply some image processing techniques to make the number plate more readable
    processed_image = cv2.medianBlur(gray_image, 3)
    processed_image = cv2.threshold(processed_image, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)[1]

    # Read the number plate from the processed image using Tesseract OCR
    number_plate = pytesseract.image_to_string(processed_image)
    number_plate = number_plate.strip()
    #cv2.imshow('1',processed_image)
    print(number_plate)

    # Compare the read number plate with the saved one
    if number_plate == saved_number_plate:
        # Send a signal of 1
        """flag_plate = 1
        if ((flag_plate == 1) & (flag_msg == 0)):
            send_notification()
            flag_msg = 1
            print("Messege Sent")"""

        print("Opening Gate")
        requests.get("http://192.168.4.1/open")
        time.sleep(10)
        print("Closing Gate")
        requests.get("http://192.168.4.1/close")

    else:
        """flag_plate = 0
        if ((flag_plate == 0) & (flag_msg == 1)):
            flag_msg = 0"""

        print("Not Matched")
        
    #cv2.waitKey(0)
    #cv2.destroyAllWindows()
    # Release the camera

ser = serial.Serial('COM9',115200)
threshold = 15

while True:
    distance = int(ser.readline().decode('ascii').rstrip())
    #distance = int(distance)
    print(distance)
    if distance < threshold:
        print("Starting camera")
        numper_plate()

ser.close()