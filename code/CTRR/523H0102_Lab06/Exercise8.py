from math import floor
def Dec2Hex(num):
    Hexcimal = []
    # hexlist = [10, 11, 12, 13, 14, 15]
    hextable = {
        10: 'A',
        11: 'B',
        12: 'C',
        13: 'D',
        14: 'E',
        15: 'F'}

    while(int(floor(num)) != 0):
        re = int(floor(num)) % 16
        
        if re in hextable:
            re = hextable[re]
        # print(re)
        Hexcimal.append(str(re))
        num /= 16
    return "".join(item for item in reversed(Hexcimal))
    
print(Dec2Hex(1228))
        