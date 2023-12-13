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


def move(pipes_map, x, y, direction):
    ways = {
        "|": {"s": "s", "n": "n"},
        "-": {"e": "e", "w": "w"},
        "L": {"s": "e", "w": "n"},
        "J": {"s": "w", "e": "n"},
        "7": {"e": "s", "n": "w"},
        "F": {"n": "e", "w": "s"},
        "S": {}
    }
    if direction == "n":
        y -= 1
    elif direction == "s":
        y += 1
    elif direction == "w":
        x -= 1
    elif direction == "e":
        x += 1
    else:
        print("Error2")
    dot = pipes_map[y][x]
    direction = ways[dot].get(direction, None)
    if direction is None:
        print("Error3")
    return x, y, direction


def solve_task():
    pipes_map = get_map()
    length = 0
    x, y = find_start(pipes_map)
    direction = "s"  # Hardcode for my puzzle
    while direction is not None:
        x, y, direction = move(pipes_map, x, y, direction)
        # print(x, y, direction)
        length += 1
        if pipes_map[y][x] == "S":
            print(length/2 + (length % 2))
            return
    print("Error4")


solve_task()
