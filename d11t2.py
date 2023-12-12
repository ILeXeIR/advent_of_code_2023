from bisect import bisect


def get_map(empty_rows, empty_columns) -> list[str]:
    with open("files/D11.txt", "r") as file:
        sky_map = []
        line = file.readline().rstrip("\n")
        y = 0
        while line:
            sky_map.append(line)
            if set(line) == {"."}:
                empty_rows.append(y)
            line = file.readline().rstrip("\n")
            y += 1
    for x in range(len(sky_map[0])):
        column = [row[x] for row in sky_map]
        if set(column) == {"."}:
            empty_columns.append(x)
    return sky_map


def get_value(x, empty_line):
    index = bisect(empty_line, x)
    x += (index * 999999)
    return x


def find_galaxies(sky_map, empty_rows, empty_columns):
    galaxies = []
    for y in range(len(sky_map)):
        for x, dot in enumerate(sky_map[y]):
            if dot == "#":
                i = get_value(x, empty_columns)
                j = get_value(y, empty_rows)
                galaxies.append((i, j))
    return galaxies


def count_paths(galaxies):
    res = 0
    for i, g1 in enumerate(galaxies):
        for j in range(i + 1, len(galaxies)):
            g2 = galaxies[j]
            path = abs(g2[0] - g1[0]) + abs(g2[1] - g1[1])
            res += path
    return res


def solve_task():
    empty_rows, empty_columns = [], []
    sky_map = get_map(empty_rows, empty_columns)
    galaxies = find_galaxies(sky_map, empty_rows, empty_columns)
    paths_sum = count_paths(galaxies)
    print(paths_sum)


solve_task()
