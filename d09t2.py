def get_prediction(numbers: list[int]) -> int:
    if set(numbers) == {0}:
        return 0
    new_numbers = [numbers[i] - numbers[i-1] for i in range(1, len(numbers))]
    return numbers[0] - get_prediction(new_numbers)


def solve_task():
    res = 0
    with open("files/D09.txt", "r") as file:
        line = file.readline().rstrip("\n")
        while line:
            numbers = [int(x) for x in line.split(' ')]
            res += get_prediction(numbers)
            line = file.readline().rstrip("\n")
    print(res)


solve_task()
