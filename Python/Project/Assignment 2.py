#Write a code for calculating area of a triangle, square and circle using the concept of class inheritance

class inputValues:
        side1 = float(input("Enter side 1: "))
        side2 = float(input("Enter side 2: "))


class square(inputValues):
    def __init__(self):
        self.area = self.side1**2
        print("Area of Square: {}".format(self.area))

class triangle(inputValues):
    def __init__(self):
        self.area = (self.side1*self.side2)/2
        print("Area of Triangle: {}".format(self.area))

class circle(inputValues):
    def __init__(self):
        self.area = 3.14*(self.side1**2)
        print("Area of Circle: {}".format(self.area))

p = inputValues()
q = square()
r = triangle()
s = circle()
