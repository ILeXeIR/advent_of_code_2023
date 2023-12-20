import math


def update_signal(signal, dst, src, moduls):
    if dst == "rx":
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


def launch_chain(moduls, key_inputs, i):
    signals = [(0, "broadcaster", "")]
    while signals:
        signal, dst, src = signals.pop(0)
        if dst == "cl" and signal == 1:
            if key_inputs[src] == 0:
                key_inputs[src] = i
        signal = update_signal(signal, dst, src, moduls)
        if signal == 2:
            return 1
        if signal >= 0:
            signals.extend([(signal, modul, dst) for modul in moduls[dst]["outputs"]])


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


def solve_task():
    with open("files/D20.txt", "r") as file:
        moduls = get_moduls(file)
    key_inputs = {key: 0 for key in moduls["cl"]["inputs"]}
    amount = 100000
    for i in range(1, amount):
        launch_chain(moduls, key_inputs, i)
        if 0 not in key_inputs.values():
            break
    print(math.lcm(*key_inputs.values()))


solve_task()
