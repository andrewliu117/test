#encoding=utf-8
import pytesser
from PIL import *
#import PIL.Image

def OCR(img):
    print img
    #im = PIL.Image.open(img)  #.convert()
    im = Image.open(img)  #.convert()
    textcode = pytesser.image_to_string(im)
    return textcode
