import cv2
import numpy as np
import time

cap = cv2.VideoCapture(0)

for i in range(30):
    ret,background = cap.read()
    print(i)

background = np.flip(background,axis=1)

while(1):
    print("while")
    ret, frame = cap.read()

    img = np.flip(frame,axis=1)
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    blurred = cv2.GaussianBlur(hsv, (35, 35),0)
    
    lower = np.array([155, 50, 50])
    upper = np.array([180, 255, 255])
    mask = cv2.inRange(hsv,lower,upper)

    mask = cv2.erode(mask,np.ones((7,7),np.uint8))
    mask = cv2.dilate(mask,np.ones((19,19),np.uint8))
    
    img[np.where(mask==255)] = background[np.where(mask==255)]

    cv2.imshow('MAGIC',img)
    
    if cv2.waitKey(1) == 27:
        break
        
cv2.destroyAllWindows()
cap.release()

# This was the code for Harry's Invisibility Cloak