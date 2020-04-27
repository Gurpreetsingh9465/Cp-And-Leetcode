import turtle
i = turtle.Turtle()
bg = turtle.Screen()
bg.bgcolor("red")
i.color("yellow")
x = 0
i.shape("turtle")
while 1:
    i.speed(20)
    i.forward(100)
    i.left(90)
    x += 1
    if x%4 ==0:
        i.left(10)
    if x/4 == 10:
        break
i.left(170)
i.forward(200)
while 1:
    i.penup()
    i.pendown()
