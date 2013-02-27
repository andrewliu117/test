import pytesser
import PIL.Image
import time

f = open('test.jpeg','r')

print f.encoding




num = PIL.Image.open('test.jpg')  #.convert()
textcode = pytesser.image_to_string(num)
print textcode


#fp = open("1.jpeg", "rb")  
#im = PIL.Image.open(fp) 
