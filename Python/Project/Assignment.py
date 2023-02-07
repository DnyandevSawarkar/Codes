#Write a code for doing the basic mathematical operations using class and object methods

class operations:
    def __init__(self):
        self.num1 = float(input("Enter a number 1: "))
        self.num2 = float(input("Enter a number 2: "))
    def addition(self):
        self.sum = self.num1+self.num2
        print("Sum: {}".format(self.sum))
    def multiplication(self):
        self.product = self.num1*self.num2
        print("Product: {}".format(self.product))
    def division(self):
        self.remainder = self.num1%self.num2
        print("Remainder: {}".format(self.remainder))
        self.quotient = self.num1/self.num2
        print("Quotient: {}".format(self.quotient))
    def subtraction(self):
        self.sub = self.num1-self.num2
        print("Subtraction: {}".format(self.sub))

p = operations()
p.addition()
p.multiplication()
p.division()
p.subtraction()
