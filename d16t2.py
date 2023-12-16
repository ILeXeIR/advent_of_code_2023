def get_direction(tile, direction) -> str:
    num = "nesw".index(direction)
    if tile == "/":
        return "enws"[num]
    elif tile == "\\":
        return "wsen"[num]
    elif tile == "|" and direction in "ew":
        return "ns"
    elif tile == "-" and direction in "ns":
        return "ew"
    return direction


def new_tile(x, y, direction) -> (int, int):
    if direction == "e":
        x += 1
    elif direction == "w":
        x -= 1
    elif direction == "s":
        y += 1
    elif direction == "n":
        y -= 1
    return x, y


def travel(x, y, direction, contraption, tiles):
    width = len(contraption[0])
    height = len(contraption)
    while 0 <= x < width and 0 <= y < height and direction not in tiles[y][x]:
        tiles[y][x].add(direction)
        direction = get_direction(contraption[y][x], direction)
        x, y = new_tile(x, y, direction[0])
        if len(direction) == 2:
            x2, y2 = new_tile(x, y, direction[1])
            travel(x2, y2, direction[1], contraption, tiles)
        direction = direction[0]


def get_map() -> list[str]:
    with open("files/D16.txt", "r") as file:
        contraption = []
        line = file.readline().rstrip("\n")
        while line:
            contraption.append(line)
            line = file.readline().rstrip("\n")
        return contraption


def count_energized(tiles) -> int:
    res = 0
    for row in tiles:
        res += sum([1 for x in row if x])
    return res


def get_start_options(width, height):
    options = []
    for x in range(width):
        options.append((x, 0, "s"))
        options.append((x, height - 1, "n"))
    for y in range(height):
        options.append((0, y, "e"))
        options.append((width - 1, y, "w"))
    return options


def solve_task():
    contraption = get_map()
    res = 0
    width = len(contraption[0])
    height = len(contraption)
    start_options = get_start_options(width, height)
    for x, y, direction in start_options:
        tiles = [[set() for _ in range(width)] for _ in range(height)]
        travel(x, y, direction, contraption, tiles)
        res = max(res, count_energized(tiles))
    print(res)


solve_task()
