#!/bin/bash

CYAN='\033[1;36m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
RED='\033[1;31m'
PURPLE='\033[1;35m'
BOLD='\033[1m'
NC='\033[0m' 

echo -e "${CYAN}${BOLD}🧐Какую папку использовать для тестов?${NC}"
ls -d */

read -p "$(echo -e "${PURPLE}📂Введите имя папки: ${NC}")" FOLDER_NAME

if [[ !	-d "$FOLDER_NAME" ]]
then
	echo -e "${RED}💀Ужкс, такой папки няма, ты ввела $FOLDER_NAME${NC}"
	exit 1
fi

echo -e "\n${CYAN}${BOLD}✍ Какой скрипт протестировать?${NC}"
ls problem_*.c

read -p "$(echo -e "${PURPLE}📄Введите имя .c файла: ${NC}")" EXECUTABLE_SCRIPT

if [[ ! -f "$EXECUTABLE_SCRIPT" ]]
then
	echo -e "${RED}🙊А такого файла няма, ты ввела $EXECUTABLE_SCRIPT${NC}"
	exit 1
fi

EXEC_NAME="${EXECUTABLE_SCRIPT%.c}"

echo -e "\n${YELLOW}🏭gcc воркает...${NC}" 
if gcc "$EXECUTABLE_SCRIPT" -o "$EXEC_NAME"
then
	echo -e "${GREEN}🫵👌Скомпилился в $EXEC_NAME${NC}"
else
	echo -e "${RED}🥵Ошибка компиляции!${NC}"
	exit 1
fi

echo -e "\n${CYAN}${BOLD} 👾 Запуск тестов из папки $FOLDER_NAME${NC}"

for i in "$FOLDER_NAME"/*; do
	[ -f "$i" ] || continue

	echo -e "\n${BOLD}Тест: ${i}${NC}"
	echo -e "${YELLOW}Вход: ${NC}"
	cat "$i"

	echo -e "${YELLOW}Вывод: ${NC}"
	./"$EXEC_NAME" < "$i" 
done
echo -e
