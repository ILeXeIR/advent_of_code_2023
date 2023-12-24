def check_intersections(stone1, stone2, hailstones_dict, borders):
    k1, b1 = hailstones_dict[stone1]
    k2, b2 = hailstones_dict[stone2]
    if k1 == k2:
        return 0
    x = (b1 - b2) / (k2 - k1)
    y = k1 * x + b1
    if x < borders[0] or x > borders[1]:
        return 0
    if y < borders[0] or y > borders[1]:
        return 0
    if ((stone1[2] > 0 and x >= stone1[0] or stone1[2] < 0 and x <= stone1[0])
            and (stone2[2] > 0 and x >= stone2[0]
                 or stone2[2] < 0 and x <= stone2[0])):
        return 1
    return 0


def get_coefficients(stone):
    px, py, vx, vy = stone
    k = vy / vx
    b = py - k * px
    return k, b


def parse_input(file):
    hailstones, hailstones_dict = [], {}
    line = file.readline().rstrip("\n")
    while line:
        data = [s.rstrip(",") for s in line.split()]
        px, py, vx, vy = int(data[0]), int(data[1]), int(data[4]), int(data[5])
        stone = (px, py, vx, vy)
        hailstones.append(stone)
        hailstones_dict[stone] = get_coefficients(stone)
        line = file.readline().rstrip("\n")
    return hailstones, hailstones_dict


def solve_task():
    with open("files/D24.txt", "r") as file:
        hailstones, hailstones_dict = parse_input(file)
    res = 0
    borders = (200000000000000, 400000000000000)
    for i in range(len(hailstones) - 1):
        for j in range(i + 1, len(hailstones)):
            res += check_intersections(hailstones[i], hailstones[j],
                                       hailstones_dict, borders)
    print(res)


solve_task()
