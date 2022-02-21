import re

# Ввод списка клиентов с клавиатуры
def readConsoleText():
    text = []
    text_time = []
    text_duration = []
    flag = 'y'
    while flag == 'y':
        # Ввод имени клиента
        name = input("Enter a name of the client: ")
        # Проверка имени клиента
        name = checkInf(name)

        # Ввод фамилии клиента
        surname = input("Enter a surname of the client: ")
        # Проверка фамилии клиента
        surname = checkInf(surname)

        # Ввод времени клиента
        time = input("Enter a time of the client in the format HH:MM : ")
        # Проверка времени клиента
        time = checkTime(time, text_time, text_duration)
        text_time.append(time)

        # Ввод длительности процедуры
        duration = input("Enter a duration of the procedure in the format HH:MM : ")
        # Проверка длительности
        duration = checkDuration(duration, text_time)
        text_duration.append(duration)

        # Формирование строки
        line = name + ' ' + surname + ', ' + time + ', duration: ' + duration + ';\n'
        text.append(line)

        # Указатель конца ввода списка
        flag = input("\nDo you want to continue typing? [y/n]")
    return text, text_time


# Проверка фамилии/имени клиента
def checkInf(inf):
    # Формирование списка, который содержит цифры в строке
    digits = re.findall('[0-9]', inf)
    # Проверка фамилии/имени клиента
    while len(inf) > 20 or len(inf) <= 1 or len(digits) > 0:
        inf = input("Enter a name/surname again: ")
        digits = re.findall('[0-9]', inf)
    return inf


# Проверка времени клиента
def checkTime(time, text_time, text_duration):
    # Базовая проверка времени на формат
    flag = checkBasic(time)
    flag_time = False
    flag_duration = False
    if not flag:
        # Проверка времени на совпадение с уже существующей записью
        flag_time = checkTimes(time, text_time)
        if not flag_time:
            # Проверка длительности процедуры на наличие времени у мастера
            flag_duration = checkDurations(time, text_time, text_duration)

    # Проверка времени клиента
    while flag or flag_time or flag_duration:
        time = input("Enter a time again: ")
        flag = checkBasic(time)
        if not flag:
            flag_time = checkTimes(time, text_time)
            if not flag_time:
                flag_duration = checkDurations(time, text_time, text_duration)
    return time


# Проверка длительности
def checkDuration(duration, text_time):
    # Базовая проверка длительности на формат
    flag = checkBasic(duration)
    flag_duration = False
    if not flag:
        # Проверка длительности процедуры на наличие этого времени у мастера
        flag_duration = checkDurationDeep(duration, text_time)

    # Проверка длительности
    while flag or flag_duration:
        duration = input("Enter a duration again: ")
        flag = checkBasic(duration)
        if not flag:
            flag_duration = checkDurationDeep(duration, text_time)
    return duration


# Базовая проверка времени на формат
def checkBasic(time):
    if len(time) == 5 and time[2] == ':':
        hours = time[0:2]
        minutes = time[3:5]
        if hours.isnumeric() and minutes.isnumeric():
            if int(hours) > 24 or int(minutes) > 59:
                return True
            else:
                return False
        else:
            return True
    else:
        return True


# Проверка времени на совпадение с уже существующей записью
def checkTimes(time, text_time):
    flag = False
    for i in range(len(text_time)):
        if text_time[i] == time:
            flag = True
            break
        else:
            flag = False
    return flag


# Проверка длительности процедуры на наличие времени у мастера
def checkDurations(time, text_time, text_duration):
    flag = False
    for i in range(len(text_time)):
        if ((int(time[0:2]) < int(text_time[i][0:2])) or (int(time[0:2]) == int(text_time[i][0:2]) and int(time[3:5]) <= int(text_time[i][3:5]))) or ((int(time[0:2]) > (int(text_time[i][0:2])) + int(text_duration[i][0:2])) or (int(time[0:2]) == (int(text_time[i][0:2]) + int(text_duration[i][0:2])) and int(time[3:5]) >= (int(text_time[i][3:5]) + int(text_duration[i][3:5])))):
            flag = False
        else:
            flag = True
            break
    return flag


# Проверка длительности процедуры на наличие этого времени у мастера
def checkDurationDeep(duration, text_time):
    # Формирование массива из времени, которое идет после введенного
    biggerTime = findBiggerTime(text_time)
    if len(biggerTime) >= 1:
        # Поиск минимального времени в массиве и проверка на наличие времени
        minEl = findMinTime(biggerTime)
        last = text_time[len(text_time)-1]
        if ((int(last[0:2]) + int(duration[0:2])) < int(minEl[0:2])) or ((int(last[0:2]) + int(duration[0:2])) == int(minEl[0:2]) and (int(last[3:5]) + int(duration[3:5])) <= int(minEl[3:5])):
            return False
        else:
            return True
    else:
        return False


# Формирование массива из времени, которое идет после введенного
def findBiggerTime(text_time):
    biggerTime = []
    if len(text_time) >= 1:
        last = text_time[len(text_time)-1]
        for i in range(len(text_time)-1):
            if (int(text_time[i][0:2]) > int(last[0:2])) or (int(text_time[i][0:2]) == int(last[0:2]) and int(text_time[i][3:5]) > int(last[3:5])):
                biggerTime.append(text_time[i])
    return biggerTime


# Поиск минимального времени в массиве
def findMinTime(bigger_time):
    minEl = bigger_time[0]
    for i in range(1, len(bigger_time)):
        if (int(minEl[0:2]) > int(bigger_time[i][0:2])) or (int(minEl[0:2]) == int(bigger_time[i][0:2]) and (int(minEl[3:5]) > int(bigger_time[i][3:5]))):
            minEl = bigger_time[i]
    return minEl


# Запись текста в бинарный файл
def inputFileText(text, path):
    file = open(path, "wb")
    for i in range(len(text)):
        line = text[i]
        nLine = line.encode()
        file.write(nLine)
    file.close()


# Чтение текста с бинарного файла
def readFileText():
    text = []
    file = open("input.dot", "rb")
    while True:
        line = file.readline().decode()
        if len(line) < 1:
            break
        text.append(line)
    file.close()
    return text


# Создание нового текста согласно условию
def changeFileText(text, text_time):
    newText = []
    for i in range(len(text_time)):
        if (int(text_time[i][0:2]) > 16) or (int(text_time[i][0:2]) == 16 and int(text_time[i][3:5]) > 30):
            newText.append(text[i])
    return newText


# Вывод содержимого бинарного файла
def printFileText(path):
    file = open(path, "rb")
    while True:
        line = file.readline().decode()
        if len(line) < 1:
            break
        if len(line) > 2:
            print(line, end='')
    file.close()
