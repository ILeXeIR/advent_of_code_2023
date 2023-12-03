def is_symbol(ch: str) -> bool:
    if ch != "." and not ch.isdigit():
        return True
    return False


def find_symbol(lines: list[str], start: int, end: int) -> bool:
    start = max(start - 1, 0)
    end = min(end + 1, len(lines[1]) - 1)
    if is_symbol(lines[1][start]) or is_symbol(lines[1][end]):
        return True
    for i in range(start, end + 1):
        if lines[0] and is_symbol(lines[0][i]):
            return True
        if lines[2] and is_symbol(lines[2][i]):
            return True
    return False


def parse_lines(lines: list[str]) -> int:
    sum_line = 0
    start = -1
    for i, ch in enumerate(lines[1]):
        if ch.isdigit():
            if start == -1:
                start, end = i, i
            else:
                end += 1
        elif start >= 0:
            if find_symbol(lines, start, end):
                sum_line += int(lines[1][start:end+1])
            start = -1
    if start >= 0 and find_symbol(lines, start, end):
        sum_line += int(lines[1][start:end+1])
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
