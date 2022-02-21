import func

# Ввод списка клиентов с клавиатуры
text, text_time = func.readConsoleText()

# Запись текста в бинарный файл input.dot
func.inputFileText(text, "input.dot")

# Чтение текста с бинарного файла
fileText = func.readFileText()

# Создание нового текста, который удовлетворяет условие
changedFileText = func.changeFileText(fileText, text_time)

# Запись нового текста в бинарный файл output.dot
func.inputFileText(changedFileText, "output.dot")

# Вывод содержимого бинарного файла input.dot
print("\nInput file text:")
func.printFileText("input.dot")

# Вывод содержимого бинарного файла output.dot
print("\nOutput file text:")
func.printFileText("output.dot")
