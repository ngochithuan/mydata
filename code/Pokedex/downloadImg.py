import csv
import requests

data = []
print(type(data))
with open('pokemondb.csv', mode ='r') as file:
  csvFile = csv.reader(file)
  for lines in csvFile:
        d = lines
        data.append(d)
        
data = data[1:][:]
imgPath = []
for item in data:
    imgPath.append(item[0])
# print(imgPath)
# print(len(imgPath))

for imgURL in imgPath:
    pokemon = imgURL.split("/")
    # name
    #pokemon = (pokemon[-1])[:-4]
    
    pokemon = (pokemon[-1])
    print(pokemon)
    img_data = requests.get(imgURL).content
    with open("img/" + pokemon, 'wb') as handler:
        handler.write(img_data)
    



