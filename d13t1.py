def get_pattern(file):
    pattern = []
    line = file.readline().rstrip("\n")
    while line:
        pattern.append(line)
        line = file.readline().rstrip("\n")
    return pattern


def check_horizontal(pattern):
    for i in range(len(pattern) - 1):
        a, b = i, i + 1
        while pattern[a] == pattern[b]:
            if a == 0 or b == len(pattern) - 1:
                return i + 1
            a -= 1
            b += 1
    return 0


def find_reflection(pattern):
    num = check_horizontal(pattern)
    if num != 0:
        return num * 100
    rotated_pattern = [[row[i] for row in pattern] for i in range(len(pattern[0]))]
    num = check_horizontal(rotated_pattern)
    return num


def solve_task():
    res = 0
    with open("files/D13.txt", "r") as file:
        while True:
            pattern = get_pattern(file)
            if not pattern:
                break
            res += find_reflection(pattern)
    print(res)


solve_task()
