import func

print("Enter text:")
# Ввод многострочного текста с консоли
text = func.readConsoleText()

# Запись введенного текста в файл input.txt
func.inputText(text, "input.txt")

# Чтение записанного текста с файла input.txt
mainText = func.readFileText()

# Изменение текста согласно заданию
mainText = func.changeText(mainText)

# Запись введенного текста в файл output.txt
func.inputText(mainText, "output.txt")

# Вывод содержимого файла input.txt
print("\nInput file text:")
func.printFileText("input.txt")

# Вывод содержимого файла output.txt
print("\nOutput file text:")
func.printFileText("output.txt")
