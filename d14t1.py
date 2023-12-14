def get_platform():
    platform = []
    with open("files/D14.txt", "r") as file:
        line = file.readline().rstrip("\n")
        while line:
            platform.append(line)
            line = file.readline().rstrip("\n")
    reversed_platform = [[row[i] for row in platform] for i in range(len(platform[0]))]
    return reversed_platform


def count_load(line, length):
    sum_load = 0
    rock_load = length
    for i, dot in enumerate(line):
        if dot == "O":
            sum_load += rock_load
            rock_load -= 1
        elif dot == "#":
            rock_load = length - i - 1
    return sum_load


def solve_task():
    res = 0
    platform = get_platform()
    length = len(platform[0])
    for line in platform:
        res += count_load(line, length)
    print(res)


solve_task()
