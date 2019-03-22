def aocday4():
    f = open('Day4.txt', 'r', encoding='utf8')
    all_lines = f.readlines()
    f.close()

    all_lines.sort()

    dicio = {}
    dicio_minutos = {}
    dicio_max = {}
    total_hours = 0
    identification = 0
    for linha in all_lines:
        linha = linha.strip('\n')
        timetable, information = linha[1:].split('] ',)

        day, hours = timetable.split(' ')
        # return hours[3:]

        if information[0] == 'f':
            total_hours = -int(hours[3:])
            init = int(hours[3:])
        elif information[0] == 'w':
            total_hours += int(hours[3:])
            final = int(hours[3:])
        elif information[0] == 'G':
            identification = information[6:11]
            total_hours = 0

        if total_hours > 0:
            dicio[identification] = dicio.setdefault(identification, 0) + total_hours
            total_hours = 0
            for minute in range(init, final):
                dicio_minutos[identification] = dicio_minutos.setdefault(identification, []) + [minute]
    minuto = 0
    num_count = 0
    for key, value in dicio_minutos.items():
        for i in range(0, 60):
            if value.count(i) > num_count:
                num_count = value.count(i)
                minuto = i
        dicio_max[key] = (minuto, num_count)

    maximo = 0
    key_max = 0
    for key, value in dicio.items():
        if value > maximo:
            maximo = value
            key_max = key

    max_value = (0, 0)
    max_key = 0
    for key, value in dicio_max.items():
        if value[1] > max_value[1]:
            max_value = value
            max_key = key
    return int(max_key[1:]) * max_value[0]
    # return int(dicio_max[key_max][0])*int(key_max[1:])


print(aocday4())





















