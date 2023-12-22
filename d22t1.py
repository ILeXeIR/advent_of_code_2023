# def check_input(start, end):
#     n = 0
#     s = "xyz"
#     for i in range(3):
#         if start[i] > end[i]:
#             print(f"inverted {s[i]}")
#         if start[i] != end[i]:
#             n += 1
#     if n > 1:
#         print("not stick")

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
    indexes = []
    for i in range(n + 1, len(bricks)):
        if bricks[i][0][2] < bricks[n][1][2] + 1:
            continue
        if bricks[i][0][2] > bricks[n][1][2] + 1:
            break
        if find_connection(bricks[i], bricks[n]):
            indexes.append(i)
    return indexes


def can_disintegrate(bricks):
    res = 0
    num_bricks_under, bricks_ranged_top = {}, {}
    for i, brick in enumerate(bricks):
        top = brick[1][2]
        if top in bricks_ranged_top:
            bricks_ranged_top[top].append(i)
        else:
            bricks_ranged_top[top] = [i]
    for i, brick in enumerate(bricks):
        bricks_under = 0
        bricks_to_check = bricks_ranged_top.get(brick[0][2] - 1, [])
        for brick_num in bricks_to_check:
            if find_connection(brick, bricks[brick_num]):
                bricks_under += 1
        num_bricks_under[i] = bricks_under
    for i in range(len(bricks)):
        bricks_above_indexes = get_bricks_above(i, bricks)
        if len(bricks_above_indexes) == 0:
            res += 1
            continue
        flag = True
        for j in bricks_above_indexes:
            if num_bricks_under[j] == 1:
                flag = False
                break
        if flag:
            res += 1
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
    # for i, brick in enumerate(bricks):
    #     print(i, brick)
    res = can_disintegrate(bricks)
    print(res)


solve_task()
