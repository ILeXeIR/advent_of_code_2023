def hash_alg(string: str) -> int:
    res = 0
    for ch in string:
        res = (res + ord(ch)) * 17 % 256
    return res


def find_lens(box: list, label: str) -> int:
    for i, lens in enumerate(box):
        if lens[0] == label:
            return i
    return -1


def box_operation(string: str, boxes: dict):
    if string[-1] == "-":
        label = string[:-1]
    else:
        label = string[:-2]
        focus = int(string[-1])
    box_num = hash_alg(label)
    lens_index = find_lens(boxes[box_num], label)
    if string[-1] == "-":
        if lens_index >= 0:
            boxes[box_num].pop(lens_index)
    elif lens_index == -1:
        boxes[box_num].append([label, focus])
    else:
        boxes[box_num][lens_index][1] = focus


def count_fpower(num: int, box: list) -> int:
    res = 0
    for i, lens in enumerate(box):
        res += ((num + 1) * (i + 1) * lens[1])
    return res


def solve_task():
    res = 0
    boxes = {x: [] for x in range(256)}
    with open("files/D15.txt", "r") as file:
        line = file.readline().rstrip("\n")
        sequence = line.split(",")
    for string in sequence:
        box_operation(string, boxes)
    for num, box in boxes.items():
        res += count_fpower(num, box)
    print(res)


solve_task()
