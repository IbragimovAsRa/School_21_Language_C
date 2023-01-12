#!/bin/bash
RED='\033[0;31m'   #  ${RED}
GREEN='\033[0;32m' #  ${GREEN}

cmp_file="a.txt" # s21
out_file="b.txt" # cat
log_file="log_file.txt"

function foo() {
  diff $out_file $cmp_file >$log_file
  echo -n "result : "
  if [ -s $log_file ]; then
    echo -en "${RED} FAILED \033[0m \n "
  else
    echo -en "${GREEN} SUCCESS \033[0m\n \n "
    rm -rf a.txt
    rm -rf b.txt
    rm -rf log_file.txt
  fi
}

function flag_b() {
  if [ "$target" == "b" ] || [ "$target" == "all" ]; then

    echo -en "-------- TESTING -b FLAG -------- \n \n "

    #TEST_1
    (cat files/file1.txt) >"$out_file"
    (./s21_cat files/file1.txt) >"$cmp_file"
    echo "input command : ./s21_cat files/file1.txt"
    foo

    #TEST_2
    (cat files/file1.txt files/file2.txt) >"$out_file"
    (./s21_cat files/file1.txt files/file2.txt) >"$cmp_file"
    echo "input command : ./s21_cat files/file1.txt files/file2.txt"
    foo

    #TEST_3
    (cat -b files/file1.txt) >"$out_file"
    (./s21_cat -b files/file1.txt) >"$cmp_file"
    echo "input command : ./s21_cat -b files/file1.txt "
    foo

    #TEST_4
    (./s21_cat --number-nonblank files/file1.txt) >"$out_file"
    (./s21_cat --number-nonblank files/file1.txt) >"$cmp_file"
    echo "input command : ./s21_cat --number-nonblank  files/file1.txt "
    foo
  fi
}
function flag_e() {
  if [ "$target" == "e" ] || [ "$target" == "all" ]; then

    echo -en "-------- TESTING -e FLAG -------- \n \n "

    #TEST_1
    (cat -e files/file4_v.txt) >"$out_file"
    (./s21_cat -e files/file4_v.txt) >"$cmp_file"
    echo "input command : ./s21_cat files/file4_v.txt"
    foo

  fi
}
function flag_E() {
  if [ "$target" == "E" ] || [ "$target" == "all" ]; then

    echo -en "-------- TESTING -E FLAG -------- \n \n "

    #TEST_1
    (./s21_cat -E files/file1.txt) >"$out_file"
    (./s21_cat -E files/file1.txt) >"$cmp_file"
    echo "input command : ./s21_cat -E files/file1.txt"
    foo

    #TEST_2
    (./s21_cat -E files/file2.txt) >"$out_file"
    (./s21_cat -E files/file2.txt) >"$cmp_file"
    echo "input command : ./s21_cat -E files/file2.txt"
    foo

    #TEST_3
    (./s21_cat -E files/file3.txt) >"$out_file"
    (./s21_cat -E files/file3.txt) >"$cmp_file"
    echo "input command : ./s21_cat -E files/file3.txt"
    foo

  fi
}
function flag_n() {
  if [ "$target" == "n" ] || [ "$target" == "all" ]; then

    echo -en "-------- TESTING -n FLAG -------- \n \n "

    #TEST_1
    (cat -n files/file1.txt) >"$out_file"
    (./s21_cat -n files/file1.txt) >"$cmp_file"
    echo "input command : ./s21_cat -n files/file1.txt"
    foo

    #TEST_2
    (cat -n files/file2.txt) >"$out_file"
    (./s21_cat -n files/file2.txt) >"$cmp_file"
    echo "input command : ./s21_cat -n files/file2.txt"
    foo

    #TEST_3
    (cat -n files/file3.txt) >"$out_file"
    (./s21_cat -n files/file3.txt) >"$cmp_file"
    echo "input command : ./s21_cat -n files/file3.txt"
    foo

    #TEST_4
    (./s21_cat --number files/file3.txt) >"$out_file"
    (./s21_cat --number files/file3.txt) >"$cmp_file"
    echo "input command : ./s21_cat --number files/file3.txt"
    foo

  fi
}
function flag_s() {
  if [ "$target" == "s" ] || [ "$target" == "all" ]; then

    echo -en "-------- TESTING -s FLAG -------- \n \n "
    #TEST_1
    (cat -s files/file1.txt) >"$out_file"
    (./s21_cat -s files/file1.txt) >"$cmp_file"
    echo "input command : ./s21_cat -s files/file1.txt"
    foo

    #TEST_2
    (cat -s files/file2.txt) >"$out_file"
    (./s21_cat -s files/file2.txt) >"$cmp_file"
    echo "input command : ./s21_cat -s files/file2.txt"
    foo

    #TEST_3
    (./s21_cat --squeeze-blank files/file3.txt) >"$out_file"
    (./s21_cat --squeeze-blank files/file3.txt) >"$cmp_file"
    echo "input command : ./s21_cat --squeeze-blank files/file3.txt"
    foo

    #TEST_4
    (cat -s files/file3.txt) >"$out_file"
    (./s21_cat -s files/file3.txt) >"$cmp_file"
    echo "input command : ./s21_cat -s files/file3.txt"
    foo

  fi
}
function flag_T() {
  if [ "$target" == "T" ] || [ "$target" == "all" ]; then

    echo -en "-------- TESTING -T FLAG -------- \n \n "
    #TEST_1
    (./s21_cat -T files/file1.txt) >"$out_file"
    (./s21_cat -T files/file1.txt) >"$cmp_file"
    echo "input command : ./s21_cat -T files/file1.txt"
    foo

    #TEST_2
    (./s21_cat -T files/file4_v.txt) >"$out_file"
    (./s21_cat -T files/file4_v.txt) >"$cmp_file"
    echo "input command : ./s21_cat -T files/file4_v.txt"
    foo

  fi
}
function flag_t() {
    if [ "$target" == "t" ] || [ "$target" == "all" ]; then

      echo -en "-------- TESTING -t FLAG -------- \n \n "

      #TEST_1
      (cat -t files/file4_v.txt) >"$out_file"
      (./s21_cat -t files/file4_v.txt) >"$cmp_file"
      echo "input command : ./s21_cat -t files/file4_v.txt"
      foo

    fi
}
echo -e "___________Start__test__CAT__options_______________ \n  "

# запрос на ввод тестируемого флага

echo -e -n "Какой флаг нужно протестировать: \n Ввод:"
# shellcheck disable=SC2034
read -r target

flag_b
flag_e
flag_E
flag_n
flag_s
flag_T
flag_t

echo "_____________Test__CAT__finished_______________"
