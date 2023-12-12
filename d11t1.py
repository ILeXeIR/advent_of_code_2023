def add_columns(sky_map):
    i = 0
    while i < len(sky_map[0]):
        column = [row[i] for row in sky_map]
        if set(column) == {"."}:
            for j, row in enumerate(sky_map):
                sky_map[j] = row[:i] + "." + row[i:]
            i += 1
        i += 1


def get_map() -> list[str]:
    with open("files/D11.txt", "r") as file:
        sky_map = []
        line = file.readline().rstrip("\n")
        while line:
            sky_map.append(line)
            if set(line) == {"."}:
                sky_map.append(line)
            line = file.readline().rstrip("\n")
    add_columns(sky_map)
    return sky_map


def find_galaxies(sky_map):
    galaxies = []
    for y in range(len(sky_map)):
        for x, dot in enumerate(sky_map[y]):
            if dot == "#":
                galaxies.append((x, y))
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
    sky_map = get_map()
    galaxies = find_galaxies(sky_map)
    paths_sum = count_paths(galaxies)
    print(paths_sum)


solve_task()
