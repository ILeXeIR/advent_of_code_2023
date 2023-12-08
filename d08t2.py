import math
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
        file.readline().rstrip("\n")
        fill_network(network, file)
    nodes = [node for node in network.keys() if node[2] == "A"]
    nodes_num = len(nodes)
    steps = [0 for _ in range(nodes_num)]
    length = len(moves)
    for i, node in enumerate(nodes):
        while node[2] != "Z":
            x = 1 if moves[steps[i] % length] == "R" else 0
            node = network[node][x]
            steps[i] += 1
    print(math.lcm(*steps))


solve_task()
