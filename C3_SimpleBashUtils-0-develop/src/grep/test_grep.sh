#!/bin/bash
RED='\033[0;31m'         #  ${RED}
GREEN='\033[0;32m'      #  ${GREEN}

cmp_file="a.txt"
out_file="b.txt"
log_file="log_file.txt"

echo -e "___________Start__test__GREP__options_______________ \n \n "
echo "-------- TESTING -e FLAG --------"


(./s21_grep -e 'test' files/file1.txt) > "$out_file"
(grep -e 'test' files/file1.txt) > "$cmp_file"

echo "input command : ./s21_grep -e 'test' files/file1.txt"
diff $out_file $cmp_file > $log_file
echo -n "result : "
if [ -s $log_file ]
then
  echo -en "${RED} FAILED \033[0m \n "
else
  echo -en "${GREEN} SUCCESS \033[0m\n \n "
fi

echo "-------- TESTING -i FLAG --------"
(./s21_grep -i -e 'test' files/file1.txt) > "$out_file"
(grep -i -e 'test' files/file1.txt) > "$cmp_file"

echo "input command : ./s21_grep -i -e 'test' files/file1.txt"
diff $out_file $cmp_file > $log_file
echo -n "result : "
if [ -s $log_file ]
then
  echo -en "${RED} FAILED \033[0m \n "
else
  echo -en "${GREEN} SUCCESS \033[0m\n \n "
fi
echo "-------- TESTING -v FLAG --------"
(./s21_grep -v -e 'test' files/file1.txt) > "$out_file"
(grep -v -e 'test' files/file1.txt) > "$cmp_file"

echo "input command : ./s21_grep -v -e 'test' files/file1.txt"
diff $out_file $cmp_file > $log_file
echo -n "result : "
if [ -s $log_file ]
then
  echo -en "${RED} FAILED \033[0m \n "

else
  echo -en "${GREEN} SUCCESS \033[0m\n \n "
fi

echo "-------- TESTING -c FLAG --------"
(./s21_grep -c -e 'test' files/file1.txt) > "$out_file"
(grep -c -e 'test' files/file1.txt) > "$cmp_file"

echo "input command : ./s21_grep -c -e 'test' files/file1.txt"
diff $out_file $cmp_file > $log_file
echo -n "result : "
if [ -s $log_file ]
then
  echo -en "${RED} FAILED \033[0m \n "

else
  echo -en "${GREEN} SUCCESS \033[0m\n \n "
fi

echo "-------- TESTING -l FLAG --------"


(./s21_grep -l -e 'test' files/file1.txt) > "$out_file"
(grep -l -e 'test' files/file1.txt) > "$cmp_file"

echo "input command : ./s21_grep -l -e 'test' files/file1.txt"
diff $out_file $cmp_file > $log_file
echo -n "result : "
if [ -s $log_file ]
then
  echo -en "${RED} FAILED \033[0m \n "

else
  echo -en "${GREEN} SUCCESS \033[0m\n \n "
fi


echo "-------- TESTING -n FLAG --------"

(./s21_grep -n -e 'test' files/file1.txt) > "$out_file"
(grep -n -e 'test' files/file1.txt) > "$cmp_file"

echo "input command : ./s21_grep -n -e 'test' files/file1.txt"
diff $out_file $cmp_file > $log_file
echo -n "result : "
if [ -s $log_file ]
then
  echo -en "${RED} FAILED \033[0m \n "

else
  echo -en "${GREEN} SUCCESS \033[0m\n \n "
fi

echo "-------- TESTING -h FLAG --------"

(./s21_grep -h -e 'test' files/file1.txt) > "$out_file"
(grep -h -e 'test' files/file1.txt) > "$cmp_file"

echo "input command : ./s21_grep -h -e 'test' files/file1.txt"
diff $out_file $cmp_file > $log_file
echo -n "result : "
if [ -s $log_file ]
then
  echo -en "${RED} FAILED \033[0m \n "

else
  echo -en "${GREEN} SUCCESS \033[0m\n \n "
fi

echo "-------- TESTING -f FLAG --------"

(./s21_grep -f files/pat1.txt -e test files/file1.txt) > "$out_file"
(grep -f files/pat1.txt files/file1.txt) > "$cmp_file"
echo "input command : ./s21_grep -f files/pat1.txt -e \"test\" files/file1.txt"
diff $out_file $cmp_file > $log_file
echo -n "result : "
if [ -s $log_file ]
then
  echo -en "${RED} FAILED \033[0m \n "

else
  echo -en "${GREEN} SUCCESS \033[0m\n \n "
fi

echo "-------- TESTING -o FLAG --------"

(./s21_grep -o -e "test"  files/file1.txt) > "$out_file"
(grep -o -e "test"  files/file1.txt) > "$cmp_file"
echo "input command : ./s21_grep -o -e \"test\"  files/file1.txt"
diff $out_file $cmp_file > $log_file
echo -n "result : "
if [ -s $log_file ]
then
  echo -en "${RED} FAILED \033[0m \n "

else
  echo -en "${GREEN} SUCCESS \033[0m\n \n "
fi

echo "_____________Test__GREP__finished_______________"