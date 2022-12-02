#!/bin/bash
RED='\033[0;31m'   #  ${RED}
GREEN='\033[0;32m' #  ${GREEN}

cmp_file="a.txt"
out_file="b.txt"
log_file="log_file.txt"

echo -e "___________Start__test__CAT__options_______________ \n  "

# запрос на ввод тестируемого флага

echo -e -n "Какой флаг нужно протестировать: \n Ввод:"
# shellcheck disable=SC2034
read -r target
if [ "$target" == "b" ] || [ "$target" == "all" ]; then
  echo "-------- TESTING -e FLAG --------"
  #TEST_1
  (cat files/file1.txt) >"$out_file"
  (./s21_cat files/file1.txt) >"$cmp_file"

  echo "input command : ./s21_cat files/file1.txt"
  diff $out_file $cmp_file >$log_file
  echo -n "result : "
  if [ -s $log_file ]; then
    echo -en "${RED} FAILED \033[0m \n "
  else
    echo -en "${GREEN} SUCCESS \033[0m\n \n "
  fi
  #TEST_2
  (cat files/file1.txt files/file2.txt) >"$out_file"
  (./s21_cat files/file1.txt files/file2.txt) >"$cmp_file"

  echo "input command : ./s21_cat files/file1.txt files/file2.txt"
  diff $out_file $cmp_file >$log_file
  echo -n "result : "
  if [ -s $log_file ]; then
    echo -en "${RED} FAILED \033[0m \n "
  else
    echo -en "${GREEN} SUCCESS \033[0m\n \n "
  fi
  #TEST_3
  (cat -b files/file1.txt) >"$out_file"
  (./s21_cat -b files/file1.txt) >"$cmp_file"

  echo "input command : ./s21_cat -b files/file1.txt "
  diff $out_file $cmp_file >$log_file
  echo -n "result : "
  if [ -s $log_file ]; then
    echo -en "${RED} FAILED \033[0m \n "
  else
    echo -en "${GREEN} SUCCESS \033[0m\n \n "
  fi
fi

echo "_____________Test__CAT__finished_______________"
