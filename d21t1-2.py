def make_step(garden, positions, sign):
    width, length = len(garden[0]), len(garden)
    new_positions = set()
    new_plots = 0
    for x, y in positions:
        check_for_step = [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]
        for i, j in check_for_step:
            if i == -1:
                i += width
            elif i == width:
                i = 0
            if j == -1:
                j += length
            elif j == length:
                j = 0
            if 0 <= i < width and 0 <= j < length and garden[j][i] == ".":
                if sign == "O":
                    new_plots += 1
                garden[j][i] = sign
                new_positions.add((i, j))
    return new_positions, new_plots


def walk_in_garden(garden, steps):
    x, y = len(garden[0]) // 2, len(garden) // 2
    if garden[y][x] != "S":
        print("Error in finding start")
    garden[y][x] = "O"
    positions = {(x, y), }
    res = 1
    while steps > 0:
        steps -= 1
        sign = "Ox"[steps % 2]
        positions, new_plots = make_step(garden, positions, sign)
        res += new_plots
    return res


def get_map(file):
    garden = []
    line = file.readline().rstrip("\n")
    while line:
        garden.append([x for x in line])
        line = file.readline().rstrip("\n")
    return garden


def solve_task():
    with open("files/D21.txt", "r") as file:
        garden = get_map(file)
    steps = 64
    res = walk_in_garden(garden, steps)
    print(res)


solve_task()
