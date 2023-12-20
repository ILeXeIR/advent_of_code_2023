def update_signal(signal, dst, src, moduls):
    if dst not in moduls:
        return -1
    if dst == "broadcaster":
        return signal
    modul = moduls[dst]
    if modul["type"] == "%" and signal == 1:
        return -1
    if modul["type"] == "%" and signal == 0:
        modul["on"] = not modul["on"]
        signal = 1 if modul["on"] else 0
        return signal
    if modul["type"] == "&":
        modul["inputs"][src] = bool(signal)
        # print(dst, sum(modul["inputs"].values()), len(modul["inputs"]))
        if sum(modul["inputs"].values()) == len(modul["inputs"]):
            return 0
        return 1


def launch_chain(moduls):
    signals = [(0, "broadcaster", "")]
    sum_signals = [0, 0]
    while signals:
        signal, dst, src = signals.pop(0)
        sum_signals[signal] += 1
        signal = update_signal(signal, dst, src, moduls)
        if signal >= 0:
            signals.extend([(signal, modul, dst) for modul in moduls[dst]["outputs"]])
    return sum_signals


def get_moduls(file):
    moduls = {}
    conjunctions = []
    line = file.readline().rstrip("\n")
    while line:
        data = line.split(" ")
        name = data[0]
        outputs = [s.rstrip(",") for s in data[2:]]
        if name == "broadcaster":
            moduls[name] = {"outputs": outputs}
        elif name[0] == "%":
            moduls[name[1:]] = {"type": "%", "on": False, "outputs": outputs}
        else:
            moduls[name[1:]] = {"type": "&", "inputs": {}, "outputs": outputs}
            conjunctions.append(name[1:])
        line = file.readline().rstrip("\n")
    for modul in moduls:
        outputs = moduls[modul]["outputs"]
        for c_modul in conjunctions:
            if c_modul in outputs:
                moduls[c_modul]["inputs"][modul] = False
    # for modul in conjunctions:
    #     print(moduls[modul]["inputs"])
    return moduls


def is_default_state(moduls):
    for name, modul in moduls.items():
        if name == "broadcaster":
            continue
        if modul["type"] == "%" and modul["on"]:
            return False
        if modul["type"] == "&" and sum(modul["inputs"].values()) > 0:
            return False
    return True


def solve_task():
    with open("files/D20test.txt", "r") as file:
        moduls = get_moduls(file)
    results = []
    amount = 1000
    for i in range(amount):
        res = tuple(launch_chain(moduls))
        results.append(res)
        if is_default_state(moduls):
            break
    sum_low, sum_high = 0, 0
    mult = amount // len(results) + 1
    flag = amount % len(results)
    for i, res in enumerate(results):
        if i == flag:
            mult -= 1
        sum_low += (res[0] * mult)
        sum_high += (res[1] * mult)
    print(sum_low * sum_high)


solve_task()
