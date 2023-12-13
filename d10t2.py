def get_map() -> list[str]:
    with open("files/D10.txt", "r") as file:
        pipes_map = []
        line = file.readline().rstrip("\n")
        while line:
            pipes_map.append(line)
            line = file.readline().rstrip("\n")
        return pipes_map


def find_start(pipes_map):
    for y, pipe in enumerate(pipes_map):
        index = [x for x, ch in enumerate(pipe) if ch == "S"]
        if index:
            return index[0], y
    return -1, -1


def attack(x, y, new_map):
    if (
        0 <= x < len(new_map[0]) and
        0 <= y < len(new_map) and
        new_map[y][x] == "."
    ):
        new_map[y][x] = "o"
        return 1
    return 0


def capture(pipes_map, new_map, x, y, direction):
    if pipes_map[y][x] == "S":
        return
    capture_dict = {
        "|": {"n": "w", "s": "e"},
        "-": {"w": "s", "e": "n"},
        "L": {"n": "ws", "e": ""},
        "J": {"n": "", "w": "se"},
        "7": {"w": "", "s": "en"},
        "F": {"s": "", "e": "nw"}
    }  # hardcode for my puzzle (checked right side of line, can be left in other cases)
    to_capture = capture_dict[pipes_map[y][x]][direction]
    for target in to_capture:
        if target == "n":
            attack(x, y - 1, new_map)
        elif target == "s":
            attack(x, y + 1, new_map)
        elif target == "w":
            attack(x - 1, y, new_map)
        elif target == "e":
            attack(x + 1, y, new_map)


def move(pipes_map, x, y, direction, new_map):
    ways = {
        "|": {"s": "s", "n": "n"},
        "-": {"e": "e", "w": "w"},
        "L": {"s": "e", "w": "n"},
        "J": {"s": "w", "e": "n"},
        "7": {"e": "s", "n": "w"},
        "F": {"n": "e", "w": "s"},
        "S": {}
    }
    new_map[y][x] = "X"
    capture(pipes_map, new_map, x, y, direction)
    if direction == "n":
        y -= 1
    elif direction == "s":
        y += 1
    elif direction == "w":
        x -= 1
    elif direction == "e":
        x += 1
    dot = pipes_map[y][x]
    direction = ways[dot].get(direction, None)
    return x, y, direction


def check_neighbours(new_map):
    n = 0
    for y in range(len(new_map)):
        for x in range(len(new_map[0])):
            if new_map[y][x] == "o":
                n += attack(x, y - 1, new_map)
                n += attack(x, y + 1, new_map)
                n += attack(x - 1, y, new_map)
                n += attack(x + 1, y, new_map)
    if n > 0:
        return 1
    return 0


def count_res(new_map):
    res = 0
    for line in new_map:
        for dot in line:
            if dot == "o":
                res += 1
    return res


def solve_task():
    pipes_map = get_map()
    new_map = [["."] * len(pipes_map[0]) for _ in range(len(pipes_map))]
    x, y = find_start(pipes_map)
    direction = "s"
    while direction is not None:
        x, y, direction = move(pipes_map, x, y, direction, new_map)
        if pipes_map[y][x] == "S":
            break
    flag = 1
    while flag == 1:
        flag = check_neighbours(new_map)
    print(count_res(new_map))


solve_task()
