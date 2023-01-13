#!/bin/bash
RED='\033[0;31m'   #  ${RED}
GREEN='\033[0;32m' #  ${GREEN}

cmp_file="a.txt"
out_file="b.txt"
log_file="log_file.txt"
pattern_e_1="because"
pattern_e_2="normal"
pattern_i="when"

function foo() {
  diff $out_file $cmp_file >$log_file
  echo -n "result : "
  if [ -s $log_file ]; then
    echo -en "${RED} FAILED \033[0m \n "
  else
    echo -en "${GREEN} SUCCESS \033[0m\n \n "
  fi
}

function flag_e() {
    if [ "$target" == "e" ] || [ "$target" == "all" ]; then
      echo "-------- TESTING -e FLAG --------"
      #TEST_1
      (grep -e $pattern_e_1 files/file1.txt) >"$out_file"
      (./s21_grep -e $pattern_e_1 files/file1.txt) >"$cmp_file"

      echo "input command : ./s21_grep -e '$pattern_e_1' files/file1.txt"
      foo

      #TEST_2
      (grep -e $pattern_e_1 -e $pattern_e_2 files/file1.txt) >"$out_file"
      (./s21_grep -e $pattern_e_1 -e $pattern_e_2 files/file1.txt) >"$cmp_file"

      echo "input command : ./s21_grep -e '$pattern_e_1' -e '$pattern_e_2' files/file1.txt"
      foo

      #TEST_3
      (grep -e $pattern_e_1 files/file1.txt files/file2.txt) >"$out_file"
      (./s21_grep -e $pattern_e_1 files/file1.txt files/file2.txt) >"$cmp_file"

      echo "input command : ./s21_grep -e '$pattern_e_1' files/file1.txt files/file2.txt"
      foo
    fi
}
function flag_i() {

if [ "$target" == "i" ] || [ "$target" == "all" ]; then
  echo "-------- TESTING -i FLAG --------"
  # TEST_1
  echo " - TEST_1"
  (./s21_grep -i -e $pattern_i files/file1.txt) >"$out_file"
  (grep -i -e $pattern_i files/file1.txt) >"$cmp_file"

  echo "input command : ./s21_grep -i -e '$pattern_i' files/file1.txt"
  foo

  # TEST_2
  echo "- TEST_2"
  (./s21_grep -i $pattern_i files/file1.txt) >"$out_file"
  (grep -i $pattern_i files/file1.txt) >"$cmp_file"

  echo "input command : ./s21_grep -i '$pattern_i' files/file1.txt"
  foo

  # TEST_3
  echo "- TEST_3"
  (./s21_grep -ie $pattern_i files/file1.txt) >"$out_file"
  (grep -ie $pattern_i files/file1.txt) >"$cmp_file"

  echo "input command : ./s21_grep -ie '$pattern_i' files/file1.txt"
  foo
fi
}
function flag_v() {
    if [ "$target" == "v" ] || [ "$target" == "all" ]; then
      echo "-------- TESTING -v FLAG --------"
      # TEST_1
      echo " - TEST_1"
      (./s21_grep -v -e $pattern_e_1 files/file1.txt) >"$out_file"
      (grep -v -e $pattern_e_1 files/file1.txt) >"$cmp_file"

      echo "input command : ./s21_grep -v -e '$pattern_e_1' files/file1.txt"
      foo

      # TEST_2
      echo "- TEST_2"
      (./s21_grep -ve $pattern_e_1 files/file1.txt) >"$out_file"
      (grep -ve $pattern_e_1 files/file1.txt) >"$cmp_file"

      echo "input command : ./s21_grep -ve '$pattern_e_1' files/file1.txt"
      foo

      # TEST_3
      echo "- TEST_3"
      (./s21_grep -v $pattern_e_1 files/file1.txt) >"$out_file"
      (grep -v $pattern_e_1 files/file1.txt) >"$cmp_file"

      echo "input command : ./s21_grep -v  '$pattern_e_1' files/file1.txt"
      foo
    fi
}
function flag_c() {
    if [ "$target" == "c" ] || [ "$target" == "all" ]; then
      echo "-------- TESTING -c FLAG --------"
      # TEST_1
      echo "- TEST_1"
      (./s21_grep -c $pattern_e_1 files/file1.txt) >"$out_file"
      (grep -c $pattern_e_1 files/file1.txt) >"$cmp_file"

      echo "input command : ./s21_grep -c  '$pattern_e_1' files/file1.txt"
      foo
      # TEST_2
      echo "- TEST_2"
      (./s21_grep -c -e $pattern_e_1 files/file1.txt) >"$out_file"
      (grep -c -e $pattern_e_1 files/file1.txt) >"$cmp_file"

      echo "input command : ./s21_grep -c -e '$pattern_e_1' files/file1.txt"
      foo
      # TEST_3
      echo "- TEST_3"
      (./s21_grep -ce $pattern_e_1 files/file1.txt) >"$out_file"
      (grep -ce $pattern_e_1 files/file1.txt) >"$cmp_file"

      echo "input command : ./s21_grep -ce  '$pattern_e_1' files/file1.txt"
      foo
    fi
}
function flag_l() {
    if [ "$target" == "l" ] || [ "$target" == "all" ]; then
      echo "-------- TESTING -l FLAG --------"
      # TEST_1
      echo "- TEST_1"
      (./s21_grep -l $pattern_e_1 files/file1.txt files/file2.txt) >"$out_file"
      (grep -l $pattern_e_1 files/file1.txt files/file2.txt) >"$cmp_file"

      echo "input command : ./s21_grep -l  '$pattern_e_1' files/file1.txt files/file2.txt"
      foo
    fi
}
function flag_n() {
    if [ "$target" == "n" ] || [ "$target" == "all" ]; then
      echo "-------- TESTING -n FLAG --------"
      # TEST_1
      echo "- TEST_1"
      (./s21_grep -n $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$out_file"
      (grep -n $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$cmp_file"

      echo "input command : ./s21_grep -n  '$pattern_e_1' files/file1.txt files/file2.txt files/file3.txt"
      foo

    fi
}
function flag_h() {
    if [ "$target" == "h" ] || [ "$target" == "all" ]; then
      echo "-------- TESTING -h FLAG --------"
      # TEST_1
      echo "- TEST_1"
      (./s21_grep -h $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$out_file"
      (grep -h $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$cmp_file"

      echo "input command : ./s21_grep -h  '$pattern_e_1' files/file1.txt files/file2.txt files/file3.txt"
      foo

      # TEST_2
      echo "- TEST_2"
      (./s21_grep -h $pattern_e_1 files/file1.txt) >"$out_file"
      (grep -h $pattern_e_1 files/file1.txt) >"$cmp_file"

      echo "input command : ./s21_grep -h  '$pattern_e_1' files/file1.txt"
      foo
    fi
}
function flag_f() {
    if [ "$target" == "f" ] || [ "$target" == "all" ]; then
      echo "-------- TESTING -f FLAG --------"
      (./s21_grep -f files/pat1.txt files/file1.txt) >"$out_file"
      (grep -f files/pat1.txt files/file1.txt) >"$cmp_file"
      echo "input command : ./s21_grep -f files/pat1.txt  files/file1.txt"
      foo
      (./s21_grep -f files/pat1.txt -e $pattern_e_1 files/file1.txt) >"$out_file"
      (grep -f files/pat1.txt -e $pattern_e_1 files/file1.txt) >"$cmp_file"
      echo "input command : ./s21_grep -f files/pat1.txt -e '$pattern_e_1' files/file1.txt"
      foo
    fi
}
function flag_s() {
    if [ "$target" == "s" ] || [ "$target" == "all" ]; then
      echo "-------- TESTING -o FLAG --------"
      echo "- TEST_1"
      (./s21_grep -s $pattern_e_1 files/file1.txt files/file2.txt) >"$out_file"
      (grep -s $pattern_e_1 files/file1.txt files/file2.txt) >"$cmp_file"
      echo "input command : ./s21_grep -s  '$pattern_e_1' files/file1.txt files/file2.txt"
      foo

      echo "- TEST_2"
      (./s21_grep -s $pattern_e_1 files/file1.txt files/file2.txt files/file6.txt) >"$out_file"
      (grep -s $pattern_e_1 files/file1.txt files/file2.txt files/file6.txt) >"$cmp_file"
      echo "input command : ./s21_grep -s  '$pattern_e_1' files/file1.txt files/file2.txt files/file6.txt"
      foo
    fi
}
function flag_o() {
    if [ "$target" == "o" ] || [ "$target" == "all" ]; then
      echo "-------- TESTING -o FLAG --------"
      # TEST_1
      echo "- TEST_1"
      (./s21_grep -o $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$out_file"
      (grep -o $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$cmp_file"

      echo "input command : ./s21_grep -o  '$pattern_e_1' files/file1.txt files/file2.txt files/file3.txt"
      foo

      # TEST_2
      echo "- TEST_2"
      (./s21_grep -o $pattern_e_1 files/file1.txt) >"$out_file"
      (grep -o $pattern_e_1 files/file1.txt) >"$cmp_file"

      echo "input command : ./s21_grep -o  '$pattern_e_1' files/file1.txt "
      foo
    fi
}
function multi_flags() {
        if [ "$target" == "m" ] || [ "$target" == "all" ]; then
          echo "-------- TESTING multi_flags FLAG --------"

          # TEST_1
          echo "- TEST_1"
          (./s21_grep -iv $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$out_file"
          (grep -iv $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$cmp_file"
          echo "input command : ./s21_grep -iv  '$pattern_e_1' files/file1.txt files/file2.txt files/file3.txt"
          foo

          # TEST_2
          echo "- TEST_2"
          (./s21_grep -i -v $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$out_file"
          (grep -i -v $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$cmp_file"
          echo "input command : ./s21_grep -i -v  '$pattern_e_1' files/file1.txt"
          foo

          # TEST_3
          echo "- TEST_3"
          (./s21_grep -in $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$out_file"
          (grep -in $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$cmp_file"
          echo "input command : ./s21_grep -in  '$pattern_e_1' files/file1.txt"
          foo

          # TEST_4
          echo "- TEST_4"
          (./s21_grep -ic $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$out_file"
          (grep -ic $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$cmp_file"
          echo "input command : ./s21_grep -ic  '$pattern_e_1' files/file1.txt"
          foo

          # TEST_5
          echo "- TEST_4"
          (./s21_grep -il $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$out_file"
          (grep -il $pattern_e_1 files/file1.txt files/file2.txt files/file3.txt) >"$cmp_file"
          echo "input command : ./s21_grep -il  '$pattern_e_1' files/file1.txt files/file2.txt files/file3.txt"
          foo

        fi
}

echo -e "___________Start__test__GREP__options_______________ \n  "
echo -e -n "Какой флаг нужно протестировать: \n Ввод:"
# shellcheck disable=SC2034
read -r target

flag_e
flag_i
flag_v
flag_c
flag_l
flag_n
flag_h
flag_f
flag_s
flag_o
multi_flags

echo "_____________Test__GREP__finished_______________"
