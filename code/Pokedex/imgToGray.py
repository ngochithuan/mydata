from PIL import Image
import os
path = "T:\Code24h\Pokedex\img"
dir_list = os.listdir(path)
# print("Files and directories in '", path, "' :")
# print(dir_list)

for image in dir_list:
    img_rgb = Image.open("img/" + image)
    img_gray = img_rgb.convert('L')
    img_gray.save("img/" + image[:-4] + "_0" + ".png")
    print(image)