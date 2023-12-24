from sympy import symbols, Eq, solve


def parse_input(file):
    hailstones = []
    line = file.readline().rstrip("\n")
    while line:
        data = [s.rstrip(",") for s in line.split()]
        del data[3]
        px, py, pz, vx, vy, vz = (int(x) for x in data)
        stone = (px, py, pz, vx, vy, vz)
        hailstones.append(stone)
        line = file.readline().rstrip("\n")
    return hailstones


def solve_task():
    with open("files/D24.txt", "r") as file:
        hs = parse_input(file)
    px, py, pz, vx, vy, vz = symbols('px py pz vx vy vz')
    equations = []
    for i in range(4):
        eq1 = Eq((px - hs[i][0]) * (hs[i][4] - vy), (py - hs[i][1]) * (hs[i][3] - vx))
        eq2 = Eq((px - hs[i][0]) * (hs[i][5] - vz), (pz - hs[i][2]) * (hs[i][3] - vx))
        equations.append(eq1)
        equations.append(eq2)
    solution = solve(tuple(equations), (px, py, pz, vx, vy, vz))
    res = sum(solution[0][:3])
    print(res)


solve_task()
