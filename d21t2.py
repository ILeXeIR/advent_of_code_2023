from copy import deepcopy


def count_plots(garden):
    res = 0
    for row in garden:
        for plot in row:
            if plot == "O":
                res += 1
    return res


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
    garden[y][x] = "O" if steps % 2 == 0 else "x"
    positions = {(x, y), }
    while steps > 0:
        steps -= 1
        sign = "Ox"[steps % 2]
        positions = make_step(garden, positions, sign)
    return count_plots(garden)


def get_map(file):
    garden = []
    line = file.readline().rstrip("\n")
    while line:
        if "S" in line:
            line = line[:65] + "." + line[66:]
        garden.append([x for x in line])
        line = file.readline().rstrip("\n")
    return garden


def solve_task():
    with open("files/D21.txt", "r") as file:
        garden = get_map(file)
    even_amount = walk_in_garden(deepcopy(garden), 132)
    odd_amount = walk_in_garden(deepcopy(garden), 131)
    half_odd_inverted = odd_amount - walk_in_garden(deepcopy(garden), 65)
    half_even_inverted = even_amount - walk_in_garden(deepcopy(garden), 64)
    key_num = 26501365 // 131
    res = (key_num ** 2) * even_amount + key_num * half_even_inverted \
        + ((key_num + 1) ** 2) * odd_amount - (key_num + 1) * half_odd_inverted
    print(even_amount, odd_amount, half_odd_inverted, half_even_inverted)
    print(res)


solve_task()