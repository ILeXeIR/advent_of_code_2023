def make_step(garden, positions, sign):
    width, length = len(garden[0]), len(garden)
    new_positions = set()
    new_plots = 0
    for x, y in positions:
        check_for_step = [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]
        for i, j in check_for_step:
        #     if i == -1:
        #         i += width
        #     elif i == width:
        #         i = 0
        #     if j == -1:
        #         j += length
        #     elif j == length:
        #         j = 0
            if 0 <= i < width and 0 <= j < length and garden[j][i] in ".S":
                if sign == "x":
                    new_plots += 1
                garden[j][i] = sign
                new_positions.add((i, j))
    print(new_plots, end=" ")
    return new_positions, new_plots


def walk_in_garden(garden, steps):
    x, y = len(garden[0]) // 2, len(garden) // 2
    if garden[y][x] != "S":
        print("Error in finding start")
    garden[y][x] = "O"
    positions = {(x, y), }
    res = 0
    for i in range(steps):
        if i % 11 == 0:
            print()
        sign = "xO"[i % 2]
        positions, new_plots = make_step(garden, positions, sign)
        res += new_plots
    return res


def get_map(file):
    garden = []
    line = file.readline().rstrip("\n")
    while line:
        line = line * 5
        garden.append([x for x in line])
        line = file.readline().rstrip("\n")
    for i in range(4 * len(garden)):
        garden.append(garden[i].copy())
    return garden


def count_plots(garden):
    res = 0
    for row in garden:
        for plot in row:
            if plot == "O":
                res += 1
    return res


def solve_task():
    with open("files/D21test.txt", "r") as file:
        garden = get_map(file)
    steps = 31
    res = walk_in_garden(garden, steps)
    for row in garden:
        print(row)
    # res = count_plots(garden)
    print(res)


solve_task()
