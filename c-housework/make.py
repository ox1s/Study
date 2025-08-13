#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import re
import sys
from pathlib import Path

CONTESTS_ROOT = Path.home() / "Desktop/c-graduate/coursework/contests"
WORKING_DIR = Path.cwd()


C_TEMPLATE = """#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main() {
    int n;
    int res = scanf("%d", &n);
    if (res != 1) {
        printf("Wrong input!");
        abort();
    }
    return 0;
}
"""

def find_available_problems(root_dir: Path) -> list[dict]:
    if not root_dir.is_dir():
        print(f"Ошибка: Корневая директория контестов не найдена: {root_dir}")
        sys.exit(1)

    found_problems = []
    for contest_dir in sorted(root_dir.glob('hw*')):
        if not contest_dir.is_dir():
            continue

        statements_dir = contest_dir / 'statements'
        tests_dir = contest_dir / 'tests'

        if not statements_dir.is_dir() or not tests_dir.is_dir():
            continue

        problem_short_names = set()
        
        for statement_file in statements_dir.glob('problem_*'):
            match = re.match(r'problem_([a-zA-Z0-9]+)', statement_file.name)
            if match:
                problem_short_names.add(match.group(1))

        for short_name in sorted(list(problem_short_names)):
            tests_target_dir = tests_dir / f'problem_{short_name}'
            if tests_target_dir.is_dir():
                found_problems.append({
                    "short_name": short_name,
                    "contest_name": contest_dir.name,
                    "tests_path": tests_target_dir,
                })
                
    return found_problems

def select_problem(problems: list[dict]) -> dict:
    print("Пожалуйста, выберите задачу для работы:")
    for i, p_info in enumerate(problems, 1):
        print(f"{i:>3}) {p_info['short_name']:<10} (из курса: {p_info['contest_name']})")

    while True:
        try:
            choice_str = input("Ваш выбор (введите номер): ")
            if not choice_str.isdigit():
                print("Ошибка: Введите число.")
                continue
            
            choice_idx = int(choice_str) - 1
            if 0 <= choice_idx < len(problems):
                return problems[choice_idx]
            else:
                print("Ошибка: Неверный номер. Попробуйте еще раз.")
        except (ValueError, IndexError):
            print("Ошибка: Неверный ввод. Попробуйте еще раз.")
        except (KeyboardInterrupt, EOFError):
            print("\nОтмена операции.")
            sys.exit(0)

def main():
    print(f"Поиск доступных задач в {CONTESTS_ROOT}...")
    available_problems = find_available_problems(CONTESTS_ROOT)

    if not available_problems:
        print("Не найдено ни одной задачи с соответствующей папкой тестов.")
        sys.exit(1)

    selected_problem = select_problem(available_problems)
    short_name = selected_problem['short_name']
    tests_path = selected_problem['tests_path']
    
    print(f"\nВыбрана задача: {short_name} из курса {selected_problem['contest_name']}")

    c_file_path = WORKING_DIR / f"problem_{short_name}.c"
    symlink_path = WORKING_DIR / f"tests_{short_name}"

    if c_file_path.exists() or c_file_path.is_symlink():
        print(f"Ошибка: Файл или ссылка '{c_file_path.name}' уже существует. Прерывание.")
        sys.exit(1)
    
    if symlink_path.exists() or symlink_path.is_symlink():
        print(f"Ошибка: Файл или ссылка '{symlink_path.name}' уже существует. Прерывание.")
        sys.exit(1)

    try:
        print(f"Создание файла решения: {c_file_path.name}")
        c_file_path.write_text(C_TEMPLATE, encoding='utf-8')
    except IOError as e:
        print(f"Не удалось создать файл {c_file_path.name}: {e}")
        sys.exit(1)

    try:
        print(f"Создание ссылки на тесты: {symlink_path.name} -> {tests_path}")
        os.symlink(tests_path, symlink_path)
    except OSError as e:
        print(f"Не удалось создать символическую ссылку {symlink_path.name}: {e}")
        c_file_path.unlink() # Откатываем создание файла
        print(f"Файл {c_file_path.name} был удален из-за ошибки.")
        sys.exit(1)

    print("\nГотово! Успешно создано в текущей директории:")
    print(f"1. Файл решения: {c_file_path.name}")
    print(f"2. Ссылка на тесты: {symlink_path.name}")

if __name__ == "__main__":
    main()
