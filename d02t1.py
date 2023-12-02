def parse_line(line: str):
    game, grabs = line.split(': ')
    game_num = int(game[5:])
    for grab in grabs.split('; '):
        for cubes in grab.split(', '):
            amount, color = cubes.split()
            if (
                    color == 'red' and int(amount) > 12 or
                    color == 'green' and int(amount) > 13 or
                    color == 'blue' and int(amount) > 14
            ):
                return 0
    return game_num


def solve_task():
    with open("files/D02_task1.txt", "r") as file:
        line = file.readline()
        res = 0
        while line:
            res += parse_line(line)
            line = file.readline()
        print(res)


solve_task()
