def hash_alg(string: str) -> int:
    res = 0
    for ch in string:
        res = (res + ord(ch)) * 17 % 256
    return res


def solve_task():
    res = 0
    with open("files/D15.txt", "r") as file:
        line = file.readline().rstrip("\n")
        sequence = line.split(",")
    for string in sequence:
        res += hash_alg(string)
    print(res)


solve_task()
