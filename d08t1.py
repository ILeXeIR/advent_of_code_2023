from typing import TextIO


def fill_network(network: dict, file: TextIO):
    line = file.readline().rstrip("\n")
    while line:
        node = line[:3]
        left = line[7:10]
        right = line[12:15]
        network[node] = [left, right]
        line = file.readline().rstrip("\n")


def solve_task():
    with open("files/D08.txt", "r") as file:
        network = {}
        moves = file.readline().rstrip("\n")
        length = len(moves)
        file.readline().rstrip("\n")
        fill_network(network, file)
    steps = 0
    node = "AAA"
    while node != "ZZZ":
        move = moves[steps % length]
        if move == "L":
            node = network[node][0]
        else:
            node = network[node][1]
        steps += 1
    print(steps)


solve_task()
