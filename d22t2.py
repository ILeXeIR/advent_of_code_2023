def find_connection(brick1, brick2):
    if (
        brick1[0][0] > brick2[1][0]
        or brick1[1][0] < brick2[0][0]
        or brick1[0][1] > brick2[1][1]
        or brick1[1][1] < brick2[0][1]
    ):
        return False
    return True


def get_bricks_above(n, bricks):
    indexes = set()
    for i in range(n + 1, len(bricks)):
        if bricks[i][0][2] < bricks[n][1][2] + 1:
            continue
        if bricks[i][0][2] > bricks[n][1][2] + 1:
            break
        if find_connection(bricks[i], bricks[n]):
            indexes.add(i)
    return indexes


def check_fallen_bricks(bricks_to_check, fallen_bricks, bricks_under_indexes):
    for i in bricks_to_check:
        if not bricks_under_indexes[i]:
            continue
        is_fallen = True
        for j in bricks_under_indexes[i]:
            if j not in fallen_bricks:
                is_fallen = False
                break
        if is_fallen:
            fallen_bricks.add(i)


def can_disintegrate(bricks):
    res = 0
    bricks_under_indexes, bricks_ranged_top = {}, {}
    bricks_fall = {}
    for i, brick in enumerate(bricks):
        top = brick[1][2]
        if top in bricks_ranged_top:
            bricks_ranged_top[top].append(i)
        else:
            bricks_ranged_top[top] = [i]
    for i, brick in enumerate(bricks):
        bricks_under = set()
        bricks_to_check = bricks_ranged_top.get(brick[0][2] - 1, [])
        for brick_num in bricks_to_check:
            if find_connection(brick, bricks[brick_num]):
                bricks_under.add(brick_num)
        bricks_under_indexes[i] = bricks_under
    bricks_above_indexes = {}
    for i in range(len(bricks))[::-1]:
        bricks_above_indexes[i] = get_bricks_above(i, bricks)
        bricks_fall[i] = set()
        for j in bricks_above_indexes[i]:
            if len(bricks_under_indexes[j]) > 1:
                continue
            bricks_fall[i].add(j)
            bricks_fall[i].update(bricks_fall[j])
        temp = 0
        while temp < len(bricks_fall[i]):
            temp = len(bricks_fall[i])
            bricks_to_check = set(range(i + 1, len(bricks))) - bricks_fall[i]
            check_fallen_bricks(bricks_to_check, bricks_fall[i],
                                bricks_under_indexes)
        res += len(bricks_fall[i])
    return res


def find_bottom(main_brick, bricks):
    z_max = 0
    for brick in bricks:
        if find_connection(main_brick, brick) and brick[1][2] > z_max:
            z_max = brick[1][2]
    return z_max + 1


def put_bricks(bricks):
    for i, brick in enumerate(bricks):
        if brick[0][2] == 1:
            continue
        bottom = find_bottom(brick, bricks[:i])
        brick[1][2] -= (brick[0][2] - bottom)
        brick[0][2] = bottom
    bricks.sort(key=lambda x: x[0][2])


def parse_snapshot(file):
    snapshot = []
    line = file.readline().rstrip("\n")
    while line:
        start, end = line.split("~")
        start = [int(x) for x in start.split(",")]
        end = [int(x) for x in end.split(",")]
        snapshot.append([start, end])
        line = file.readline().rstrip("\n")
    snapshot.sort(key=lambda x: x[0][2])
    return snapshot


def solve_task():
    with open("files/D22.txt", "r") as file:
        bricks = parse_snapshot(file)
    put_bricks(bricks)
    res = can_disintegrate(bricks)
    print(res)


solve_task()
