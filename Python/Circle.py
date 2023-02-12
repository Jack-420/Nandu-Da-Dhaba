from random import triangular
from turtle import *

from numpy import square

bgcolor('black')
speed(0)
hideturtle()
for i in range(120):
    color('blue')
    circle(i)
    color('red')
    circle(i*0.8)
    color('white')
    circle(i*0.6)
    right(3)
    forward(3)
done()
