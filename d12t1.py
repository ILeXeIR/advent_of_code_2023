def is_fit(conditions, num):
    for i in range(num):
        if conditions[i] == ".":
            return 0
    if len(conditions) > num and conditions[num] == "#":
        return 0
    return 1


def count_arrangements(conditions, damaged_lst):
    res = 0
    length = damaged_lst[0]
    min_details = sum(damaged_lst) + len(damaged_lst) - 1
    for i in range(len(conditions) - min_details + 1):
        if conditions[i] == ".":
            continue
        if is_fit(conditions[i:], length):
            if len(damaged_lst) == 1 and "#" not in set(conditions[i+length:]):
                res += 1
            elif len(damaged_lst) > 1:
                res += count_arrangements(conditions[i+length+1:], damaged_lst[1:])
        if conditions[i] == "#":
            break
    return res


def solve_task():
    arrangements = 0
    with open("files/D12.txt", "r") as file:
        line = file.readline().rstrip("\n")
        while line:
            conditions, damaged_str = line.split(" ")
            damaged_lst = [int(x) for x in damaged_str.split(",")]
            arrangements += count_arrangements(conditions, damaged_lst)
            line = file.readline().rstrip("\n")
    print(arrangements)


solve_task()
