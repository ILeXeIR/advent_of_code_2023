def is_satisfied(rating, rule):
    label, num = rule[0], int(rule[2:])
    if rule[1] == ">" and rating[label] > num:
        return 1
    if rule[1] == "<" and rating[label] < num:
        return 1
    return 0


def get_new_flow(rating, rules):
    for rule in rules:
        if len(rule) == 1:
            return rule[0]
        if is_satisfied(rating, rule[0]) == 1:
            return rule[1]


def check_rating(rating, workflows):
    flow = "in"
    while flow != "A" and flow != "R":
        rules = workflows[flow]
        flow = get_new_flow(rating, rules)
    return flow


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


def parse_line(line):
    data = line.split(",")
    rating = {x[0]: int(x[2:]) for x in data}
    return rating


def solve_task():
    res = 0
    with open("files/D19.txt", "r") as file:
        workflows = get_workflows(file)
        line = file.readline().strip("{}\n")
        while line:
            rating = parse_line(line)
            answer = check_rating(rating, workflows)
            if answer == "A":
                res += sum(rating.values())
            elif answer != "R":
                print("Error", rating)
            line = file.readline().strip("{}\n")
    print(res)


solve_task()
