def make_step(garden, positions, sign):
    width, length = len(garden[0]), len(garden)
    new_positions = set()
    for x, y in positions:
        check_for_step = [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]
        for i, j in check_for_step:
            if 0 <= i < width and 0 <= j < length and garden[j][i] == ".":
                garden[j][i] = sign
                new_positions.add((i, j))
    return new_positions


def walk_in_garden(garden, steps):
    x, y = len(garden[0]) // 2, len(garden) // 2
    if garden[y][x] != "S":
        print("Error in finding start")
    garden[y][x] = "O"
    positions = {(x, y), }
    while steps > 0:
        steps -= 1
        sign = "Ox"[steps % 2]
        positions = make_step(garden, positions, sign)


def get_map(file):
    garden = []
    line = file.readline().rstrip("\n")
    while line:
        garden.append([x for x in line])
        line = file.readline().rstrip("\n")
    return garden


def count_plots(garden):
    res = 0
    for row in garden:
        for plot in row:
            if plot == "O":
                res += 1
    return res


def solve_task():
    with open("files/D21.txt", "r") as file:
        garden = get_map(file)
    steps = 64
    walk_in_garden(garden, steps)
    for row in garden:
        print(row)
    res = count_plots(garden)
    print(res)


solve_task()
