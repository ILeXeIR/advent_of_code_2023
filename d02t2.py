def parse_line(line: str):
    _, grabs = line.split(': ')
    num_red, num_green, num_blue = 0, 0, 0
    for grab in grabs.split('; '):
        for cubes in grab.split(', '):
            amount, color = cubes.split()
            amount = int(amount)
            if color == 'red' and amount > num_red:
                num_red = amount
            elif color == 'green' and amount > num_green:
                num_green = amount
            elif color == 'blue' and amount > num_blue:
                num_blue = amount
    return num_red * num_green * num_blue


def solve_task():
    with open("files/D02_task1.txt", "r") as file:
        line = file.readline()
        res = 0
        while line:
            res += parse_line(line)
            line = file.readline()
        print(res)


solve_task()
