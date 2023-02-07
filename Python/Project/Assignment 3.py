#Write a code for calculating the angle between hour hand and the minute hand for any given valid input

#The idea is to take 12:00 (h = 12, m = 0) as a reference. Following are detailed steps.
#1) Calculate the angle made by hour hand with respect to 12:00 in h hours and m minutes. 
#2) Calculate the angle made by minute hand with respect to 12:00 in h hours and m minutes. 
#3) The difference between two angles is the angle between two hands.

#How to calculate the two angles with respect to 12:00? 

#The minute hand moves 360 degree in 60 minute(or 6 degree in one minute) and hour hand moves 360 degree in 12 hours(or 0.5 degree in 1 minute).
#In h hours and m minutes, the minute hand would move (h*60 + m)*6 and hour hand would move (h*60 + m)*0.5.


######
#Using Class Inheritance
######
class inputValues:
    hour = int(input("Enter the hour value: "))
    mins = int(input("Enter the minute value: "))

class angle(inputValues):
    def calcAngle(self):    
        if (self.hour < 0 or self.mins < 0 or self.hour > 12 or self.mins > 60):
            print('Wrong input')        

        if (self.hour == 12):
            self.hour = 0
        if (self.mins == 60):
            self.mins = 0
            self.hour += 1;
        if(self.hour>12):
            self.hour = self.hour-12;

        hour_angle = 0.5 * (self.hour * 60 + self.mins)
        minute_angle = 6 * self.mins  

        angle = abs(hour_angle - minute_angle)  

        angle = min(360 - angle, angle)  
        print("Angle for the given input is: {}".format(angle))

p = inputValues()
q = angle()
q.calcAngle()


######
#Without using Class Inheritance
######
class inputValues:
    def __init__(self):
        self.hour = int(input("Enter the hour value: "))
        self.mins = int(input("Enter the minute value: "))

    def calcAngle(self):    
        if (self.hour < 0 or self.mins < 0 or self.hour > 12 or self.mins > 60):
            print('Wrong input')        

        if (self.hour == 12):
            self.hour = 0
        if (self.mins == 60):
            self.mins = 0
            self.hour += 1;
        if(self.hour>12):
            self.hour = self.hour-12;

        hour_angle = 0.5 * (self.hour * 60 + self.mins)
        minute_angle = 6 * self.mins  

        angle = abs(hour_angle - minute_angle)  

        angle = min(360 - angle, angle)  
        print("Angle for the given input is: {}".format(angle))

p = inputValues()
p.calcAngle()
