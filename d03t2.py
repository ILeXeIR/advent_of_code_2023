def parse_num(line: str, i: int) -> int:
    start, end = i, i
    while start > 0 and line[start - 1].isdigit():
        start -= 1
    while end < len(line) - 1 and line[end + 1].isdigit():
        end += 1
    return int(line[start:end+1])


def count_nums(line: str, i: int) -> int:
    n = 0
    if line[i].isdigit():
        return 1
    if (i + 1) < len(line) and line[i + 1].isdigit():
        n += 1
    if (i - 1) >= 0 and line[i - 1].isdigit():
        n += 1
    return n


def get_num(line: str, i: int) -> int:
    n = 1
    if line[i].isdigit():
        return parse_num(line, i)
    if (i + 1) < len(line) and line[i + 1].isdigit():
        n *= parse_num(line, i + 1)
    if (i - 1) >= 0 and line[i - 1].isdigit():
        n *= parse_num(line, i - 1)
    return n


def get_gear_ratio(lines: list[str], i: int) -> int:
    n = 0
    gear_ratio = 1
    for line in lines:
        n += count_nums(line, i)
        gear_ratio *= get_num(line, i)
    if n == 2:
        return gear_ratio
    else:
        return 0


def parse_lines(lines: list[str]) -> int:
    sum_line = 0
    for i, ch in enumerate(lines[1]):
        if ch == "*":
            sum_line += get_gear_ratio(lines, i)
    return sum_line


def solve_task():
    with open("files/D03_task1.txt", "r") as file:
        lines = ["", file.readline().rstrip("\n"), file.readline().rstrip("\n")]
        res = 0
        while lines[1]:
            res += parse_lines(lines)
            lines.pop(0)
            lines.append(file.readline().rstrip("\n"))
        print(res)


solve_task()
