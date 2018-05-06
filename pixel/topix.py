from PIL import Image
import sys

im = Image.open(sys.argv[1])

print("#ifndef _TEST_H")
print("#define _TEST_H")
print("#include <stdint.h>")
print("#define u8 uint8_t")

rgb_im = im.convert('L')

width = rgb_im.width
height = rgb_im.height

print("#define IMAGE_WIDTH %d" % width)
print("#define IMAGE_HEIGHT %d" % height)

print("u8 im[%d][%d]=" % (width, height))

print('{')
for i in range(width):
    print('{', end='')
    for j in range(height):
        print(rgb_im.getpixel((i, j))//255, end='')
        if j < height - 1:
            print(',', end='')
    print('}', end='')
    if i < width - 1:
        print(',')
print('};')

print("#endif")