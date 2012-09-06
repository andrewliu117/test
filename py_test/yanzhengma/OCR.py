#encoding=utf-8
import pytesser
from PIL import Image

def OCR(img):
    print img
    im = Image.open(img)  #.convert()
    textcode = pytesser.image_to_string(im)
    return textcode
