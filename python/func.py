# Ввод многострочного текста с консоли
def readConsoleText():
    import sys
    # Ввод текста
    text = sys.stdin.read()

    # Убираем лишний символ \n
    text[:len(text)-1]
    return text


# Вывод содержимого файла
def printFileText(src):
    # Открытие файла для чтения
    file = open(src, 'rt')

    # Чтение содержимого файла
    text = file.read()

    # Закрытие файла
    file.close()

    # Удалаем лишний символ \n с текста
    text = text[:len(text)-1]
    print(text)


# Запись текста в файл
def inputText(text, src):
    # Открытие файла для записи
    file = open(src, 'wt')

    # Запись текста в файл
    file.write(text)

    # Закрытие файла
    file.close()


# Чтение записанного текста с файла input.txt
def readFileText():
    # Открытие файла для чтения
    file = open("input.txt", "rt")

    # Чтение файла
    text = file.read()

    # Закрытие файла
    file.close()

    # Убираем лишний символ \n
    text = text[:len(text)-1]
    return text


# Изменение текста согласно заданию
def changeText(text):
    import re
    newText = ''
    # Создание массива, который содержит строки текста
    lines = text.split('\n')

    for line in lines:
        # Создание массива, который содержит все числа в строке с помощью регулярных выражений
        arr = re.findall('[0-9]+', line)

        if len(arr) > 0:
            # Поиск максимального числа в строке
            maxNum = arr[0]
            id = 0
            for i in range(len(arr)):
                if int(maxNum) <= int(arr[i]):
                    maxNum = arr[i]
                    id = i

            # Создание нового текста, который начинается с самого большого числа в строке
            # Далее записываются оставшиеся числа через запятую
            newText += maxNum
            for i in range(len(arr)):
                if i != id:
                    newText += ', ' + arr[i]
            newText += '\n'
    return newText

