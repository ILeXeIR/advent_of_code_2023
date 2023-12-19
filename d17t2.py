def check_west(x, y, route_map, city_map) -> int:
    flag, min_loss, loses = 0, -1, 0
    for i in range(1, 11):
        if x - i < 0:
            break
        loses += int(city_map[y][x - i])
        if i < 4:
            continue
        point = route_map[y][x - i]
        for direction in "ns":
            if point[direction][0] >= 0 and \
                    (flag == 0 or point[direction][0] + loses < min_loss):
                min_loss = point[direction][0] + loses
                steps = i
                flag = 1
    if flag == 1:
        route_map[y][x]["w"] = (min_loss, steps)
    return flag


def check_east(x, y, route_map, city_map) -> int:
    flag, min_loss, loses = 0, -1, 0
    for i in range(1, 11):
        if x + i >= len(route_map[0]):
            break
        loses += int(city_map[y][x + i])
        if i < 4:
            continue
        point = route_map[y][x + i]
        for direction in "ns":
            if point[direction][0] >= 0 and \
                    (flag == 0 or point[direction][0] + loses < min_loss):
                min_loss = point[direction][0] + loses
                steps = i
                flag = 1
    if flag == 1:
        route_map[y][x]["e"] = (min_loss, steps)
    return flag


def check_nord(x, y, route_map, city_map) -> int:
    flag, min_loss, loses = 0, -1, 0
    for i in range(1, 11):
        if y - i < 0:
            break
        loses += int(city_map[y - i][x])
        if i < 4:
            continue
        point = route_map[y - i][x]
        for direction in "we":
            if point[direction][0] >= 0 and \
                    (flag == 0 or point[direction][0] + loses < min_loss):
                min_loss = point[direction][0] + loses
                steps = i
                flag = 1
    if flag == 1:
        route_map[y][x]["n"] = (min_loss, steps)
    return flag


def check_south(x, y, route_map, city_map) -> int:
    flag, min_loss, loses = 0, -1, 0
    for i in range(1, 11):
        if y + i >= len(route_map):
            break
        loses += int(city_map[y + i][x])
        if i < 4:
            continue
        point = route_map[y + i][x]
        for direction in "we":
            if point[direction][0] >= 0 and \
                    (flag == 0 or point[direction][0] + loses < min_loss):
                min_loss = point[direction][0] + loses
                steps = i
                flag = 1
    if flag == 1:
        route_map[y][x]["s"] = (min_loss, steps)
    return flag


def get_heat_loss(x, y, route_map, city_map) -> int:
    if x == 0 and y == 0:
        return 0
    flag = 0
    flag += check_west(x, y, route_map, city_map)
    flag += check_east(x, y, route_map, city_map)
    flag += check_nord(x, y, route_map, city_map)
    flag += check_south(x, y, route_map, city_map)
    return min(1, flag)


def count_loss(city_map, route_map) -> int:
    width = len(city_map[0])
    height = len(city_map)
    changes = 0
    for x in range(width):
        for y in range(height):
            changes += get_heat_loss(x, y, route_map, city_map)
    for x in range(width)[::-1]:
        for y in range(height)[::-1]:
            changes += get_heat_loss(x, y, route_map, city_map)
    return changes


def get_map() -> list[str]:
    with open("files/D17.txt", "r") as file:
        city_map = []
        line = file.readline().rstrip("\n")
        while line:
            city_map.append(line)
            line = file.readline().rstrip("\n")
        return city_map


def draw_route(route_map):
    width = len(route_map[0])
    height = len(route_map)
    new_map = [["." for _ in range(width)] for _ in range(height)]
    x, y = width - 1, height - 1
    options = "nw"
    while x > 0 or y > 0:
        point = route_map[y][x]
        flag, min_loss = 0, -1
        for direction in options:
            if point[direction][0] >= 0 and \
                    (flag == 0 or point[direction][0] < min_loss):
                min_loss = point[direction][0]
                target = direction
                flag = 1
        if target in "ns":
            options = "we"
        else:
            options = "ns"
        for _ in range(point[target][1]):
            new_map[y][x] = "#"
            if target == "e":
                x += 1
            elif target == "w":
                x -= 1
            elif target == "s":
                y += 1
            elif target == "n":
                y -= 1
    new_map[0][0] = "#"
    # for line in new_map:
    #     print(*line)
    return new_map


def count_res(new_map, city_map):
    width = len(city_map[0])
    height = len(city_map)
    res = -int(city_map[0][0])
    for y in range(height):
        for x in range(width):
            if new_map[y][x] == "#":
                res += int(city_map[y][x])
    return res


def solve_task():
    city_map = get_map()
    width = len(city_map[0])
    height = len(city_map)
    dict_sample = {"n": (-1, 0), "s": (-1, 0), "w": (-1, 0), "e": (-1, 0)}
    route_map = [[dict_sample.copy() for _ in range(width)] for _ in range(height)]
    route_map[0][0]["n"] = (0, 0)
    route_map[0][0]["w"] = (0, 0)
    for _ in range(5):
        count_loss(city_map, route_map)
    new_map = draw_route(route_map)
    res = count_res(new_map, city_map)
    print(res)


solve_task()
