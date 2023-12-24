def count_area(coord_list, perimetr):
    area = perimetr
    for i in range(len(coord_list)):
        x = coord_list[i - 1][0]
        y = coord_list[i][1]
        area += (x * y)
        x = coord_list[i][0]
        y = coord_list[i - 1][1]
        area -= (x * y)
    return abs(area) // 2 + 1


def get_coordinates(x, y, perimetr, direction, length):
    perimetr += length
    if direction == "R":
        x += length
    elif direction == "L":
        x -= length
    elif direction == "D":
        y += length
    elif direction == "U":
        y -= length
    return x, y, perimetr


def decrypt_data(data):
    direction = "RDLU"[int(data[-1])]
    length = 0
    for x in data[:5]:
        n = "0123456789abcdef".index(x)
        length = length * 16 + n
    return direction, length


def parse_instructions(file):
    coord_list = []
    x, y, perimetr = 0, 0, 0
    line = file.readline().rstrip("\n")
    while line:
        data = line.split()[2][2:8]
        direction, length = decrypt_data(data)
        x, y, perimetr = get_coordinates(x, y, perimetr, direction, length)
        coord_list.append((x, y))
        line = file.readline().rstrip("\n")
    return coord_list, perimetr


def solve_task():
    with open("files/D18.txt", "r") as file:
        coord_list, perimetr = parse_instructions(file)
    res = count_area(coord_list, perimetr)
    print(res)


solve_task()
