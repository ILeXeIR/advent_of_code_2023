opposites = {"n": "s", "s": "n", "w": "e", "e": "w"}


def get_directions(position, trail_map):
    x, y, direction = position["x"], position["y"], position["direction"]
    directions = ""
    if y == len(trail_map) - 1:
        return ""
    coordinates = ((x, y - 1), (x, y + 1), (x - 1, y), (x + 1, y))
    for i, d in enumerate("nswe"):
        if d == opposites[direction]:
            continue
        point = trail_map[coordinates[i][1]][coordinates[i][0]]
        if point == "." or (d == "s" and point == "v") or \
                (d == "e" and point == ">"):
            directions += d
    return directions


def make_step(position):
    if position["direction"] == "n":
        position["y"] -= 1
    elif position["direction"] == "s":
        position["y"] += 1
    elif position["direction"] == "w":
        position["x"] -= 1
    elif position["direction"] == "e":
        position["x"] += 1


def find_next_fork(position, trail_map, routes):
    fork = (position["x"], position["y"])
    direction = position["direction"]
    while len(position["direction"]) == 1:
        prev_direction = position["direction"]
        make_step(position)
        position["steps"] += 1
        position["direction"] = get_directions(position, trail_map)
    if len(position["direction"]) == 0 and position["y"] < len(trail_map) - 1:
        position["x"], position["y"] = 0, 0
    position["direction"] = prev_direction
    result = {
        "next_fork": (position["x"], position["y"]),
        "direction": prev_direction,
        "steps": position["steps"]
    }
    if fork in routes:
        routes[fork][direction] = result
    else:
        routes[fork] = {direction: result}


def is_in_routes(position, routes):
    fork = (position["x"], position["y"])
    direction = position["direction"]
    if fork in routes and direction in routes[fork]:
        position["x"], position["y"] = routes[fork][direction]["next_fork"]
        position["direction"] = routes[fork][direction]["direction"]
        position["steps"] = routes[fork][direction]["steps"]
        return True
    return False


def get_position(forks, forks_dict):
    fork = forks[-1]
    position = {
        "x": fork[0],
        "y": fork[1],
        "direction": forks_dict[fork]["directions"][0],
        "steps": 0
    }
    return position


def go_to_next_fork(trail_map, forks, forks_dict, routes):
    position = get_position(forks, forks_dict)
    if not is_in_routes(position, routes):
        find_next_fork(position, trail_map, routes)
    next_fork = (position["x"], position["y"])
    direction, steps = position["direction"], position["steps"]
    if next_fork == (0, 0) or next_fork in forks:
        return 1
    directions = get_directions(position, trail_map)
    forks_dict[next_fork] = {
        "directions": directions,
        "steps": forks_dict[forks[-1]]["steps"] + steps
    }
    forks.append(next_fork)
    if next_fork[1] == len(trail_map) - 1:
        return 2
    return 0


def check_prev_fork(forks, forks_dict):
    while forks:
        fork = forks[-1]
        if len(forks_dict[fork]["directions"]) > 1:
            forks_dict[fork]["directions"] = forks_dict[fork]["directions"][1:]
            break
        del forks_dict[fork]
        del forks[-1]


def find_way(trail_map):
    routes = {}
    forks = [(1, 0)]
    forks_dict = {forks[0]: {"directions": "s", "steps": 0}}
    longest_path = 0
    while forks_dict:
        flag = go_to_next_fork(trail_map, forks, forks_dict, routes)  # 0 - next fork, 1 - dead end, 2 - finish
        if flag == 2:
            longest_path = max(longest_path, forks_dict[forks[-1]]["steps"])
        if flag > 0:
            check_prev_fork(forks, forks_dict)
    return longest_path


def get_map(file):
    trail_map = []
    line = file.readline().rstrip("\n")
    while line:
        trail_map.append(line)
        line = file.readline().rstrip("\n")
    return trail_map


def solve_task():
    with open("files/D23.txt", "r") as file:
        trail_map = get_map(file)
    longest_path = find_way(trail_map)
    print(longest_path)


solve_task()
