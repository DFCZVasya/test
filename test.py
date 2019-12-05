
"""
import csv
import os
from PIL import Image
DIR ="D:/dataset/train_image/"
SAVE_DIR = "D:/dataset/crops2/"

def crop(image_path, coords, saved_location):
    image_obj = Image.open(image_path)
    cropped_image = image_obj.crop(coords)
    cropped_image.save(saved_location)

count = 57579

#image = DIR + "000001.jpg"
#crop(image, (100, 210, 710,380 ), 'cropped.jpg')

with open('full-gt.csv', newline='') as csvfile:
    reader = csv.DictReader(csvfile, delimiter=',')
    #lastfilename = ''
    #filenames = []
    #c = 0
    classes = ["2_1", "2_4", "3_1", "3_24_n10", "3_24_n20", "3_24_n30", "3_24_n40",
               "3_24_n5", "3_24_n50", "3_24_n60", "3_24_n70", "3_24_n80", "3_27",
               "4_1_1", "4_1_2", "4_1_2_1", "4_1_2_2", "4_1_3", "4_1_4", "4_1_5",
               "4_1_6", "4_2_1", "4_2_2", "4_2_3", "5_19_1", "5_20", "8_22"]
    for line in reader:
        if line["sign_class"] in classes:
            continue

            if line["sign_class"] == '2_1':
                cl = '2_1'
            if line["sign_class"] == '2_4':
                cl = '2_4'
            if line["sign_class"] == '3_1':
                cl = '3_1'
            if line["sign_class"] == '3_24_n10' or line["sign_class"] == '3_24_n20' or line["sign_class"] == '3_24_n30' or line["sign_class"] == '3_24_n40' or line["sign_class"] == '3_24_n5' or line["sign_class"] == '3_24_n50' or line["sign_class"] == '3_24_n60' or line["sign_class"] == '3_24_n70' or line["sign_class"] == '3_24_n80':
                cl = '3_24'
            if line["sign_class"] == '3_27':
                cl = '3_27'
            if line["sign_class"] == '4_1_1' or line["sign_class"] == '4_1_2' or line["sign_class"] == '4_1_2_1' or line["sign_class"] == '4_1_2_2' or line["sign_class"] == '4_1_3' or line["sign_class"] == '4_1_4' or line["sign_class"] == '4_1_5' or line["sign_class"] == '4_1_6':
                cl = '4_1'
            if line["sign_class"] == '4_2_1' or line["sign_class"] == '4_2_2' or line["sign_class"] == '4_2_3':
                cl = '4_2'
            if line["sign_class"] == '5_19_1':
                cl = '5_19'
            if line["sign_class"] == '5_20':
                cl = '5_20'
            if line["sign_class"] == '8_22':
                cl = '8_22'

        else:
            cl = 0
            count += 1
            crop(DIR + line["filename"],
                (int(line["x_from"]), int(line["y_from"]), int(line["x_from"]) + int(line["width"]), int(line["y_from"]) + int(line["height"])),
                SAVE_DIR + str(count) + '-' + str(cl) +'-0' + '.jpg')
            print("crop for " + (line["filename"]))

"""

"""
for filename in os.listdir('D:/dataset/rtsd-public/fullframes/rtsd-frames'):
    if filename in filenames:
        continue
    else:
        os.remove('D:/dataset/rtsd-public/fullframes/rtsd-frames/' + filename)
        print(filename + ' was deleted')
"""

from PIL import Image
import os
DIR ="D:/dataset/crops2/"
SAVE_DIR = "D:/dataset/crops_/"

# open an image file (.bmp,.jpg,.png,.gif) you have in the working folder
def read_file(path):
    im1 = Image.open(path)
    # adjust width and height to your needs
    width = 32  #640
    height = 32 #480
    im = im1.resize((width, height), Image.ANTIALIAS)    # best down-sizing filter
    im.save(SAVE_DIR+filename[:-4] + '-0' + '.jpg')
    print("resize for " + filename)

for filename in os.listdir(DIR):
        if filename.endswith('.jpg'):
            read_file(DIR+filename)

