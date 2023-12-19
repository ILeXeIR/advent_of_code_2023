def get_alternative(x, y, route_map, city_map, directions, limit) -> (int, str):
    heat_loss, hl, new_dir = 0, 0, ""
    opposite = {"w": "e", "e": "w", "n": "s", "s": "n"}
    if limit == 0:
        directions = directions[1:]
        limit = 3
    for direction in directions:
        if direction == "w" and x > 0:
            alt_dir = "wns"
            i, j = x - 1, y
        elif direction == "e" and x < len(route_map[0]) - 1:
            alt_dir = "ens"
            i, j = x + 1, y
        elif direction == "n" and y > 0:
            alt_dir = "nwe"
            i, j = x, y - 1
        elif direction == "s" and y < len(route_map) - 1:
            alt_dir = "swe"
            i, j = x, y + 1
        else:
            continue
        point = route_map[j][i]
        if point[0] > 0 and point[1][0] == direction and point[2] >= limit:
            hl, alt_dir = get_alternative(i, j, route_map, city_map, alt_dir, limit - 1)
        elif point[0] > 0 and point[1][0] == opposite[direction]:
            limit = 3
            continue
        else:
            hl, alt_dir = route_map[j][i][0], ""
        if hl > 0 and (heat_loss == 0 or hl < heat_loss):
            heat_loss = hl
            new_dir = direction + alt_dir
        limit = 3
    if heat_loss == 0:
        return 0, ""
    return heat_loss + int(city_map[y][x]), new_dir


def set_new_heat_loss(heat_loss, dst_point, src_point, direction) -> int:
    if heat_loss < dst_point[0] or dst_point[0] == 0:
        dst_point[0] = heat_loss
        dst_point[1] = direction
        steps = 0
        for step in direction:
            if step == direction[0]:
                steps += 1
            else:
                break
        if steps == len(direction) and src_point[1][0] == direction[0]:
            steps += src_point[2]
        dst_point[2] = steps
        return 1
    return 0


def check_west(x, y, route_map, city_map) -> int:
    if x == 0 or route_map[y][x - 1][0] == 0:
        return 0
    point = route_map[y][x - 1]
    new_dir = "w"
    if point[1][0] == "w" and point[2] >= 3 or point[1][0] == "e":
        heat_loss, alt_dir = get_alternative(x - 1, y, route_map, city_map, "wns", 2)
        if heat_loss == 0:
            return 0
        heat_loss += int(city_map[y][x])
        new_dir += alt_dir
    else:
        heat_loss = point[0] + int(city_map[y][x])
    return set_new_heat_loss(heat_loss, route_map[y][x], point, new_dir)


def check_east(x, y, route_map, city_map) -> int:
    if x == len(route_map[0]) - 1 or route_map[y][x + 1][0] == 0:
        return 0
    point = route_map[y][x + 1]
    new_dir = "e"
    if point[1][0] == "e" and point[2] >= 3 or point[1][0] == "w":
        heat_loss, alt_dir = get_alternative(x + 1, y, route_map, city_map, "ens", 2)
        if heat_loss == 0:
            return 0
        heat_loss += int(city_map[y][x])
        new_dir += alt_dir
    else:
        heat_loss = point[0] + int(city_map[y][x])
    return set_new_heat_loss(heat_loss, route_map[y][x], point, new_dir)


def check_nord(x, y, route_map, city_map) -> int:
    if y == 0 or route_map[y - 1][x][0] == 0:
        return 0
    point = route_map[y - 1][x]
    new_dir = "n"
    if point[1][0] == "n" and point[2] >= 3 or point[1][0] == "s":
        heat_loss, alt_dir = get_alternative(x, y - 1, route_map, city_map, "nwe", 2)
        if heat_loss == 0:
            return 0
        heat_loss += int(city_map[y][x])
        new_dir += alt_dir
    else:
        heat_loss = point[0] + int(city_map[y][x])
    return set_new_heat_loss(heat_loss, route_map[y][x], point, new_dir)


def check_south(x, y, route_map, city_map) -> int:
    if y == len(route_map) - 1 or route_map[y + 1][x][0] == 0:
        return 0
    point = route_map[y + 1][x]
    new_dir = "s"
    if point[1][0] == "s" and point[2] >= 3 or point[1][0] == "n":
        heat_loss, alt_dir = get_alternative(x, y + 1, route_map, city_map, "swe", 2)
        if heat_loss == 0:
            return 0
        heat_loss += int(city_map[y][x])
        new_dir += alt_dir
    else:
        heat_loss = point[0] + int(city_map[y][x])
    return set_new_heat_loss(heat_loss, route_map[y][x], point, new_dir)


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
    direction = ""
    while x > 0 or y > 0:
        new_map[y][x] = "#"
        if direction == "":
            direction = route_map[y][x][1]
        # print(x, y, direction)
        if direction[0] == "e":
            x += 1
        elif direction[0] == "w":
            x -= 1
        elif direction[0] == "s":
            y += 1
        elif direction[0] == "n":
            y -= 1
        direction = direction[1:]
    new_map[0][0] = "#"
    for line in new_map:
        print(*line)


def solve_task():
    city_map = get_map()
    width = len(city_map[0])
    height = len(city_map)
    route_map = [[[0, "", 0] for _ in range(width)] for _ in range(height)]
    route_map[0][0][0] = int(city_map[0][0])
    route_map[0][0][1] = "."
    changes = 1
    while changes > 0:
        changes = count_loss(city_map, route_map)
    draw_route(route_map)
    # for line in route_map:
    #     print(line)
    # for i in range(119, 129):
    #     print(route_map[i][134], route_map[i][135])
    print(route_map[-1][-1][0] - int(city_map[0][0]))


solve_task()
