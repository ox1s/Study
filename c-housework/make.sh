#!/bin/bash

read -p "Введи название проблемы: " FILE_TO_MAKE

FILENAME="problem_${FILE_TO_MAKE}.c"

echo -e "#include <stdio.h>\n#include <assert.h>\n#include <stdlib.h>\n\nint main() {\n\n}" > "$FILENAME"

echo "Файл $FILENAME создан!"
