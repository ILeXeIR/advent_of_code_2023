def get_platform():
    platform = []
    with open("files/D14.txt", "r") as file:
        line = [x for x in file.readline().rstrip("\n")]
        while line:
            platform.append(line)
            line = [x for x in file.readline().rstrip("\n")]
    return platform


def rotate_north(platform):
    for x in range(len(platform[0])):
        target_point = 0
        for y in range(len(platform)):
            if platform[y][x] == "#" or \
                    (platform[y][x] == "O" and target_point == y):
                target_point = y + 1
            elif platform[y][x] == "O" and target_point < y:
                platform[y][x] = "."
                platform[target_point][x] = "O"
                target_point += 1


def rotate_west(platform):
    for y in range(len(platform)):
        target_point = 0
        for x in range(len(platform[0])):
            if platform[y][x] == "#" or \
                    (platform[y][x] == "O" and target_point == x):
                target_point = x + 1
            elif platform[y][x] == "O" and target_point < x:
                platform[y][x] = "."
                platform[y][target_point] = "O"
                target_point += 1


def rotate_south(platform):
    for x in range(len(platform[0])):
        target_point = len(platform) - 1
        for y in range(len(platform))[::-1]:
            if platform[y][x] == "#" or \
                    (platform[y][x] == "O" and target_point == y):
                target_point = y - 1
            elif platform[y][x] == "O" and target_point > y:
                platform[y][x] = "."
                platform[target_point][x] = "O"
                target_point -= 1


def rotate_east(platform):
    for y in range(len(platform)):
        target_point = len(platform[0]) - 1
        for x in range(len(platform[0]))[::-1]:
            if platform[y][x] == "#" or \
                    (platform[y][x] == "O" and target_point == x):
                target_point = x - 1
            elif platform[y][x] == "O" and target_point > x:
                platform[y][x] = "."
                platform[y][target_point] = "O"
                target_point -= 1


def rotation_cycle(platform):
    rotate_north(platform)
    rotate_west(platform)
    rotate_south(platform)
    rotate_east(platform)


def count_load(platform):
    sum_load = 0
    length = len(platform)
    for i in range(len(platform[0])):
        line = [row[i] for row in platform]
        sum_load += sum([length - j for j in range(length) if line[j] == "O"])
    return sum_load


def solve_task():
    platform = get_platform()
    loads = []
    cycle_len = 0
    i = 0
    while True:
        rotation_cycle(platform)
        res = count_load(platform)
        if cycle_len == 0 and res in loads:
            start = loads.index(res)
            cycle_len = i - start
        loads.append(res)
        if cycle_len > 0 and i == start + cycle_len*2 - 1:
            if loads[-cycle_len:] == loads[-2*cycle_len:-cycle_len]:
                break
            else:
                cycle_len = 0
        i += 1
    x = (1000000000 - start - 1) % cycle_len
    print(loads[start + x])


solve_task()
