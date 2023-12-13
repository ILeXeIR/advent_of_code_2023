def get_pattern(file):
    pattern = []
    line = file.readline().rstrip("\n")
    while line:
        pattern.append(line)
        line = file.readline().rstrip("\n")
    return pattern


def compare_lines(line1, line2, smudges):
    dif = 0
    for i in range(len(line1)):
        if line1[i] != line2[i]:
            dif += 1
            if dif > 1:
                return 0
    smudges[0] += dif
    return 1


def check_horizontal(pattern):
    for i in range(len(pattern) - 1):
        a, b = i, i + 1
        smudges = [0]
        while compare_lines(pattern[a], pattern[b], smudges):
            if smudges[0] > 1:
                break
            if a == 0 or b == len(pattern) - 1:
                if smudges[0] == 1:
                    return i + 1
                break
            a -= 1
            b += 1
    return 0


def find_reflection(pattern):
    num = check_horizontal(pattern)
    if num != 0:
        return num * 100
    rotated_pattern = [[row[i] for row in pattern] for i in range(len(pattern[0]))]
    num = check_horizontal(rotated_pattern)
    if num == 0:
        print("Can't find.")
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
