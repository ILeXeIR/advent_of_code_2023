import networkx as nx
import matplotlib.pyplot as plt


def divide_groups(G):
    # G.remove_edge("nvd", "jqt")
    # G.remove_edge("cmg", "bvb")
    # G.remove_edge("pzl", "hfx")
    G.remove_edge("xkf", "rcn")
    G.remove_edge("dht", "xmv")
    G.remove_edge("thk", "cms")
    groups = list(nx.connected_components(G))
    # print(groups)
    return len(groups[0]) * len(groups[1])


def get_components(file):
    lines = []
    line = file.readline().rstrip("\n")
    while line:
        line = line[:3] + line[4:]
        lines.append(line)
        line = file.readline().rstrip("\n")
    G = nx.parse_adjlist(lines)
    return G


def solve_task():
    with open("files/D25.txt", "r") as file:
        G = get_components(file)
    # nx.draw(G, with_labels=True)
    # plt.savefig("graph.png")
    res = divide_groups(G)
    print(res)


solve_task()
