def get_coordinates(x, y, direction, length, limits):
    if direction == "R":
        x += length
        limits[2] = max(limits[2], x)
    elif direction == "L":
        x -= length
        limits[0] = min(limits[0], x)
    elif direction == "D":
        y += length
        limits[3] = max(limits[3], y)
    elif direction == "U":
        y -= length
        limits[1] = min(limits[1], y)
    return x, y


def parse_instructions():
    with open("files/D18.txt", "r") as file:
        x, y = 0, 0
        limits = [0, 0, 0, 0]
        instructions = []
        line = file.readline().rstrip("\n")
        while line:
            data = line.split()
            direction, length, color = data[0], int(data[1]), data[2][2:8]
            x, y = get_coordinates(x, y, direction, length, limits)
            instructions.append([direction, length, color])
            line = file.readline().rstrip("\n")
        return instructions, limits


def fill_inside(tunnel_map):
    to_fill = set()
    for x, dot in enumerate(tunnel_map[0]):
        if dot[0] == "#" and tunnel_map[1][x][0] == ".":
            to_fill.add((x, 1))
            break
    while to_fill:
        x, y = to_fill.pop()
        tunnel_map[y][x][0] = "O"
        for i, j in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
            if tunnel_map[j][i][0] == ".":
                to_fill.add((i, j))


def get_map(instructions, limits):
    width = limits[2] - limits[0] + 1
    height = limits[3] - limits[1] + 1
    x, y = -limits[0], -limits[1]
    tunnel_map = [[[".", ""] for _ in range(width)] for _ in range(height)]
    for point in instructions:
        direction, length, color = point
        while length > 0:
            if direction == "R":
                x += 1
            elif direction == "L":
                x -= 1
            elif direction == "D":
                y += 1
            elif direction == "U":
                y -= 1
            tunnel_map[y][x][0] = "#"
            tunnel_map[y][x][1] = color
            length -= 1
    fill_inside(tunnel_map)
    return tunnel_map


def count_square(tunnel_map):
    res = 0
    for row in tunnel_map:
        for dot in row:
            if dot[0] != ".":
                res += 1
    return res


def solve_task():
    instructions, limits = parse_instructions()
    tunnel_map = get_map(instructions, limits)
    res = count_square(tunnel_map)
    print(res)
    # for y in range(len(tunnel_map)):
    #     for x in range(len(tunnel_map[0])):
    #         print(tunnel_map[y][x][0], end=" ")
    #     print()


solve_task()
