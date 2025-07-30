#!/bin/bash

CYAN='\033[1;36m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
RED='\033[1;31m'
PURPLE='\033[1;35m'
BOLD='\033[1m'
NC='\033[0m' 

echo -e "${CYAN}${BOLD}🧐 Какую папку использовать для тестов?${NC}"
ls -d */

read -p "$(echo -e "${PURPLE}📂 Введите имя папки: ${NC}")" FOLDER_NAME

if [[ !	-d "$FOLDER_NAME" ]]
then
	echo -e "${RED}💀 Ужкс, такой папки няма, ты ввела $FOLDER_NAME${NC}"
	exit 1
fi

echo -e "\n${CYAN}${BOLD}✍ Какой скрипт скомпилировать и протестировать?${NC}"
ls problem_*.c

read -p "$(echo -e "${PURPLE}📄 Введите имя .c файла: ${NC}")" EXECUTABLE_SCRIPT

if [[ ! -f "$EXECUTABLE_SCRIPT" ]]
then
	echo -e "${RED}🙊А такого файла няма, ты ввела $EXECUTABLE_SCRIPT${NC}"
	exit 1
fi

EXEC_NAME="${EXECUTABLE_SCRIPT%.c}"

echo -e "\n${YELLOW}🏭 gcc воркает...${NC}" 
if gcc -Wall -Werror "$EXECUTABLE_SCRIPT" -o "$EXEC_NAME" -lm
then
	echo -e "${GREEN}🫵👌 Скомпилился в $EXEC_NAME${NC}"
else
	echo -e "${RED}🥵 Ошибка компиляции!${NC}"
	exit 1
fi

read -p "$(echo -e "\n${PURPLE}✨ Показывать детали для успешных тестов? (y/n): ${NC}")" SHOW_DETAILS
SHOW_DETAILS=$(echo "$SHOW_DETAILS" | tr '[:upper:]' '[:lower:]')

echo -e "\n${CYAN}${BOLD}👾 Запуск тестов из папки $FOLDER_NAME${NC}"

passed_count=0
failed_count=0
no_ans_count=0
tests_found=0

for test_file in "$FOLDER_NAME"/*.dat
do
	[ -f "$test_file" ] || continue
	((tests_found++))
	
	ans_file="${test_file%.dat}.ans"
	base_name=$(basename "$test_file")
	program_output=$(./"$EXEC_NAME" < "$test_file")
	if [ -f "$ans_file" ]
	then
		expected_output=$(cat "$ans_file")
		if [[ "$program_output" == "$expected_output" ]]
		then
			((passed_count++))
			if [[ "$SHOW_DETAILS" == "y" ]]
			then
				echo -e "\n${BOLD}Тест: ${test_file}${NC}"
                		echo -e "${GREEN}✅ ОК${NC}"
                		echo -e "${YELLOW}Вывод программы:${NC}\n$program_output"
           		else
                		echo -e "${GREEN}✅ Тест ${base_name} ... OK${NC}"
            		fi
		else
			((failed_count++))
			echo -e "\n${BOLD}Тест: ${test_file}${NC}"
            		echo -e "${RED}Вывод программы:${NC}\n$program_output"
            		echo -e "${RED}❌ Неправильно! Ожидалось согласно $(basename "$ans_file"):${NC}\n$expected_output"
		fi
	else
		((no_ans_count++))
		echo -e "\n${BOLD}Тест: ${test_file} (нет .ans файла для сверки)${NC}"
        	echo -e "${YELLOW}Вывод:${NC}\n$program_output"
    	fi
done
			
if [ $tests_found -eq 0 ]
then
    	echo -e "\n${YELLOW}🤔 В папке '$FOLDER_NAME' не найдено ни одного .dat файла.${NC}"
else
	echo -e "\n${CYAN}${BOLD}🏁 Тесты завершены!${NC}"
	echo -e "${GREEN}Прошло: $passed_count${NC} | ${RED}Завалено: $failed_count${NC} | ${YELLOW}Без проверки: $no_ans_count${NC}\n"
fi
