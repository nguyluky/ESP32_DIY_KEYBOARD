import json


LAYER_FILE_PATH = "./wokwi/keyboard-layout-converted.json"

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
    text = """KC::ESC      , KC::F1    , KC::F2    , KC::F3     , KC::F4  , KC::F5    , KC::F6    , KC::F7    , KC::F8    , KC::F9    , KC::F10   , KC::F11     , KC::F12     , KC::SYSRQ     , KC::SCROLLLOCK
KC::HASHTILDE, KC::N1    , KC::N2    , KC::N3     , KC::N4  , KC::N5    , KC::N6    , KC::N7    , KC::N8    , KC::N9    , KC::N0    , KC::MINUS   , KC::EQUAL   , KC::BACKSPACE , KC::INSERT    
KC::TAB      , KC::Q     , KC::W     , KC::E      , KC::R   , KC::T     , KC::Y     , KC::U     , KC::I     , KC::O     , KC::P     , KC::LBRACE  , KC::RBRACE  , KC::BACKSLASH , KC::DELETE    
KC::CAPSLOCK , KC::A     , KC::S     , KC::D      , KC::F   , KC::G     , KC::H     , KC::J     , KC::K     , KC::L     , KC::SCLN  , KC::QUOT    , KC::ENTER   , KC::PAGEDOWN  , KC::NONE      
KC::LSHIFT   , KC::Z     , KC::X     , KC::C      , KC::V   , KC::B     , KC::N     , KC::M     , KC::COMMA , KC::DOT   , KC::SLASH , KC::RSHIFT  , KC::END     , KC::PAGEUP    , KC::NONE      
KC::LCTRL    , KC::LGUI  , KC::LALT  , KC::SPACE  , KC::RALT, KC::LM(1) , KC::PROPS , KC::RCTRL , KC::LEFT  , KC::DOWN  , KC::RIGHT , KC::UP      , KC::HOME    , KC::PAUSE     , KC::NONE      """
    for line in text.split('\n'):
        for i in line.split(','):
            len_ = len(i)
            i1 = i.strip()
            line = line.replace(i, i1.center(len_))
        
        print("{",line,"},")

if __name__ == "__main__":
    # formatCenterMap()
    makeLedConntent()
    pass