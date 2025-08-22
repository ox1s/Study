#!/bin/python

import os
import sys
import subprocess
import glob
import re

class Colors:
    CYAN = '\033[1;36m'
    GREEN = '\033[1;32m'
    YELLOW = '\033[1;33m'
    RED = '\033[1;31m'
    PURPLE = '\033[1;35m'
    BOLD = '\033[1m'
    NC = '\033[0m'

def find_available_problems():
    """Находит доступные задачи по шаблону problem_*.c и извлекает их аббревиатуры."""
    problems = {}
    for c_file in glob.glob("dproblem_*/problem_*.c"):
        match = re.search(r'problem_([a-zA-Z0-9_]+)\.c', c_file)
        if match:
            abbreviation = match.group(1)
            test_dir = f"tests_{abbreviation}"
            if os.path.isdir(test_dir):
                problems[abbreviation] = {
                    "c_file": c_file,
                    "test_dir": test_dir
                }
    return problems

def compile_program(c_file, exec_name):
    """Компилирует .c файл в исполняемый."""
    print(f"\n{Colors.YELLOW}🏭 Компиляция {c_file} с помощью gcc...{Colors.NC}")
    try:
        result = subprocess.run(
            ["gcc", "-Wall", "-Werror", c_file, "-o", exec_name, "-lm"],
            capture_output=True, text=True, check=True
        )
        print(f"{Colors.GREEN}🫵👌 Успешно скомпилировано в {exec_name}{Colors.NC}")
        return True
    except subprocess.CalledProcessError as e:
        print(f"{Colors.RED}🥵 Ошибка компиляции!{Colors.NC}")
        print(e.stderr)
        return False
    except FileNotFoundError:
        print(f"{Colors.RED}💀 Команда 'gcc' не найдена. Убедитесь, что компилятор установлен и доступен в PATH.{Colors.NC}")
        return False


def run_tests(exec_name, folder_name, show_details):
    """Запускает тесты для скомпилированной программы."""
    print(f"\n{Colors.CYAN}{Colors.BOLD}👾 Запуск тестов из папки {folder_name}{Colors.NC}")

    passed_count = 0
    failed_count = 0
    no_ans_count = 0

    test_files = sorted(glob.glob(os.path.join(folder_name, '*.dat')))

    if not test_files:
        print(f"\n{Colors.YELLOW}🤔 В папке '{folder_name}' не найдено ни одного .dat файла.{Colors.NC}")
        return

    for test_file in test_files:
        ans_file = os.path.splitext(test_file)[0] + ".ans"
        base_name = os.path.basename(test_file)

        with open(test_file, 'r') as f:
            program_input = f.read()

        try:
            result = subprocess.run(
                [f"./{exec_name}"],
                input=program_input,
                capture_output=True, text=True, timeout=5  
                )
            program_output = result.stdout.strip()

            if os.path.exists(ans_file):
                with open(ans_file, 'r') as f:
                    expected_output = f.read().strip()

                if program_output == expected_output:
                    passed_count += 1
                    if show_details:
                        print(f"\n{Colors.BOLD}Тест: {test_file}{Colors.NC}")
                        print(f"Ввод программы:\n{program_input}")
                        print(f"{Colors.GREEN}✅ ОК{Colors.NC}")
                        print(f"{Colors.YELLOW}Вывод программы:{Colors.NC}\n{program_output}")
                    else:
                        print(f"{Colors.GREEN}✅ Тест {base_name} ... OK{Colors.NC}")
                else:
                    failed_count += 1
                    print(f"\n{Colors.BOLD}Тест: {test_file}{Colors.NC}")
                    print(f"Ввод программы:\n{program_input}")
                    print(f"{Colors.RED}Вывод программы:{Colors.NC}\n{program_output}")
                    print(f"{Colors.RED}❌ Неправильно! Ожидалось ({os.path.basename(ans_file)}):{Colors.NC}\n{expected_output}")
            else:
                no_ans_count += 1
                print(f"\n{Colors.BOLD}Тест: {test_file} (нет .ans файла для сверки){Colors.NC}")
                print(f"{Colors.YELLOW}Вывод:{Colors.NC}\n{program_output}")

        except subprocess.TimeoutExpired:
            failed_count += 1
            print(f"\n{Colors.RED}❌ Тест {base_name} ... Превышено время ожидания!{Colors.NC}")
        except Exception as e:
            failed_count += 1
            print(f"\n{Colors.RED}❌ Тест {base_name} ... Ошибка выполнения: {e}{Colors.NC}")


    print(f"\n{Colors.CYAN}{Colors.BOLD}🏁 Тесты завершены!{Colors.NC}")
    print(f"{Colors.GREEN}Прошло: {passed_count}{Colors.NC} | {Colors.RED}Завалено: {failed_count}{Colors.NC} | {Colors.YELLOW}Без проверки: {no_ans_count}{Colors.NC}\n")


def main():
    available_problems = find_available_problems()

    if not available_problems:
        print(f"{Colors.RED}💀 Не найдено ни одной задачи. Убедитесь, что есть файлы 'problem_*.c' и папки 'tests_*'.{Colors.NC}")
        sys.exit(1)

    print(f"{Colors.CYAN}{Colors.BOLD}🧐 Доступные для тестирования задачи:{Colors.NC}")
    for abbr in sorted(available_problems.keys()):
        print(f"  - {abbr}")

    try:
        abbr_input = input(f"\n{Colors.PURPLE}✍️ Введите аббревиатуру задачи: {Colors.NC}")
    except KeyboardInterrupt:
        print("\nВыход.")
        sys.exit(0)


    if abbr_input not in available_problems:
        print(f"{Colors.RED}🙊 Нет такой задачи. Вы ввели: {abbr_input}{Colors.NC}")
        sys.exit(1)

    problem = available_problems[abbr_input]
    c_file = problem["c_file"]
    test_dir = problem["test_dir"]
    exec_name = os.path.splitext(c_file)[0]

    if not compile_program(c_file, exec_name):
        sys.exit(1)

    try:
        details_input = input(f"\n{Colors.PURPLE}✨ Показывать детали для успешных тестов? (y/n): {Colors.NC}").lower()
    except KeyboardInterrupt:
        print("\nВыход.")
        sys.exit(0)
        
    show_details = details_input == 'y'

    run_tests(exec_name, test_dir, show_details)


if __name__ == "__main__":
    main()
