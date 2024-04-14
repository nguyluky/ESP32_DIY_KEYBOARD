import json


LAYER_FILE_PATH = "./py/keyboard-layout-converted.json"

def makeButtonLayout():
    with open(LAYER_FILE_PATH, encoding="UTF-8") as file:
        data = json.load(file)

        print(len(data["keys"]))
        for index,value in enumerate(data['keys']):
            # new_data = {
            # "type": "wokwi-neopixel",
            # "id": f"rgb{index}",
            # "left": (value["x"] + value['width'] / 2) * 20 ,
            # "top": (value['y'] + value['height'] / 2) * 20,
            # "rotate": 180,
            # "attrs": {}
            # }

            new_data = {
                "type": "wokwi-pushbutton",
                "id": f"btn{index}",
                "top": (value['y'] + value['height'] / 2) * 75,
                "left": (value["x"] + value['width'] / 2) * 75,
                "attrs": { "color": "green"}
            }

            print(json.dumps(new_data), ',')
            # print(value["x"] + value['width'] / 2)
            # s[index] = value["x"] + value['width'] / 2


def makeLedLayout():
    with open(LAYER_FILE_PATH, encoding="UTF-8") as file:
        data = json.load(file)

        print(len(data["keys"]))
        for index,value in enumerate(data['keys']):
            new_data = {
            "type": "wokwi-neopixel",
            "id": f"rgb{index}",
            "left": (value["x"] + value['width'] / 2) * 75 + 24.5,
            "top": (value['y'] + value['height'] / 2) * 75 + 40,
            "rotate": 180,
            "attrs": {}
            }

            print(json.dumps(new_data), ',')


def makeLedHub():
    with open(LAYER_FILE_PATH, encoding="UTF-8") as file:
        data = json.load(file)

        print(len(data["keys"]))
        s = list(range(87))
        for index,value in enumerate(data['keys']):

            # print(value["x"] + value['width'] / 2)
            s[index] = value["x"] + value['width'] / 2

        max_ = max(s)
        print("[INFO] max value" ,max_)
        for i in s:
            print(round(i * 255 / max_), ',')


def makeLedConntent():
    for i in range(85):
        connection = [ f"rgb{i}:DOUT", f"rgb{i+1}:DIN", "yellow"]
        print(json.dumps(connection), ',')

def formatCenterMap():
    text = """KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE
KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE
KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE
KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE
KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE
KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::LM(0), KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE, KC::NONE"""
    for line in text.split('\n'):
        lines = []
        for i in line.split(','):
            len_ = 15
            i1 = i.strip()
            i1 = i1.replace('\n', '')
            lines.append(i1.center(len_))
        
        print("{", ','.join(lines) ,"},")


def colorContention():
    with open('./py/diagram-test.json', encoding="UTF-8") as file:
        json_data: list = json.loads(file.read())
        last_name = 'btn76:2.l'
        for i in json_data['connections']:
            # print(i)
            if i[0] == last_name:
                i[2] = 'gray'
                # i[3][1] = 'v44.2'
                last_name = i[1]
                print(i)
        # print(json_data['connections'])
        
        with open('./py/diagram-test1.json', 'w+',encoding="UTF-8") as file:
            file.write(json.dumps(json_data, indent=2))
        

if __name__ == "__main__":
    # formatCenterMap()
    # makeLedConntent()
    colorContention()
    pass