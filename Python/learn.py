import cv2
import numpy as np

path = "G:/Codes/Python/4k.jpg"

img = cv2.imread(path)

mask = cv2.imread()



'''
font = cv2.FONT_HERSHEY_COMPLEX

img  = cv2.imread(path,cv2.IMREAD_COLOR)
img1 = cv2.imread(path,cv2.IMREAD_GRAYSCALE)

l, threshold = cv2.threshold(img1, 110, 255, cv2.THRESH_BINARY)

contours, l = cv2.findContours(threshold, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
for cnt in contours:
    approx = cv2.approxPolyDP(cnt, 0.009* cv2.arcLength(cnt, True), True)
    cv2.drawContours(img, [approx], 0, (0, 0, 255), 5)
    n = approx.ravel()
    i = 0
    for j in n:
        if(i%2 == 0):
            x = n[i]
            y = n[i+1]
            string = str(x) + " " + str(y)
            if( i == 0):
                cv2.putText(img, "Arrow", (x,y), font, 0.5, (0, 255, 0))
            else:
                cv2.putText(img, string, (x,y), font, 0.5, (0, 255, 0))
        i = i + 1
    
cv2.imshow("img",img)

if cv2.waitKey(0) & 0xFF == ord('q'):
    cv2.destroyAllWindows()


window_name = 'Img'
start_pt = (1,1)
end_pt = (350,350)
color = (0,0,0)
thickness  = -1
img = cv2.rectangle(img,start_pt,end_pt,color,thickness)
cv2.imshow(window_name,img )
cv2.waitKey(0)
'''