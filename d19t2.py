def split_sample(rule, sample):
    sample1 = sample.copy()
    sample2 = sample.copy()
    label, num = rule[0], int(rule[2:])
    if rule[1] == ">":
        sample1[label] = (num + 1, sample1[label][1])
        sample2[label] = (sample2[label][0], num)
    elif rule[1] == "<":
        sample1[label] = (sample1[label][0], num - 1)
        sample2[label] = (num, sample2[label][1])
    return sample1, sample2


def get_mode(sample, rule):
    label, num = rule[0], int(rule[2:])
    num_min, num_max = sample[label]
    if (rule[1] == ">" and num_max <= num) \
            or (rule[1] == "<" and num_min >= num):
        return 0
    if (rule[1] == ">" and num_min > num) \
            or (rule[1] == "<" and num_max < num):
        return 1
    return 2


def recursive_solution(flow, sample, workflows):
    if flow == "R":
        return 0
    if flow == "A":
        res = 1
        for x in [value[1] - value[0] + 1 for value in sample.values()]:
            res *= x
        return res
    res = 0
    rules = workflows[flow]
    for rule in rules:
        if len(rule) == 1:
            res += recursive_solution(rule[0], sample.copy(), workflows)
            continue
        mode = get_mode(sample, rule[0])
        if mode == 0:
            continue
        elif mode == 1:
            res += recursive_solution(rule[1], sample.copy(), workflows)
            break
        sample_new, sample = split_sample(rule[0], sample)
        res += recursive_solution(rule[1], sample_new, workflows)
    return res


def get_workflows(file):
    workflows = {}
    line = file.readline().rstrip("}\n")
    while line:
        title, data = line.split("{")
        rules = data.split(",")
        workflows[title] = []
        for rule in rules:
            rule = tuple(rule.split(":"))
            workflows[title].append(rule)
        line = file.readline().rstrip("}\n")
    return workflows


def solve_task():
    with open("files/D19.txt", "r") as file:
        workflows = get_workflows(file)
    sample = {"x": (1, 4000), "m": (1, 4000), "a": (1, 4000), "s": (1, 4000)}
    res = recursive_solution("in", sample, workflows)
    print(res)


solve_task()
