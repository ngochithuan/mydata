import os
from rembg import remove
from PIL import Image

inp = 'img'
out = 'img'

while True:
    for file in os.listdir(inp):
        if file.split('.')[0][-2:] == "_0":
            inp_path = os.path.join(inp, file)
            out_path = os.path.join(out, file.split('.')[0] +'.png')
            inp_img = Image.open(inp_path)
            out_img = remove(inp_img)
            out_img.save(out_path)
            print("[TH]: Done "+file+".png")
    break