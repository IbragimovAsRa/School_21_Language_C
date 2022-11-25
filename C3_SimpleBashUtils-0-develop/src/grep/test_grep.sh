#!/bin/bash
RED='\033[0;31m'         #  ${RED}
GREEN='\033[0;32m'      #  ${GREEN}

executable_program="./s21_grep"
options=""
command=""
pattern=""
cmp_file="a.txt"
out_file="b.txt"
log_file="log_file.txt"

echo "___________Start__test__GREP__options_______________"
echo "-- Testing -e flag --"

executable_program="./s21_grep"
command="$( ($executable_program -e 'test' files/file1.txt) > "$out_file")"
command
executable_program="grep"
command="$( ($executable_program -e 'test' files/file1.txt) > "$cmp_file")"
command
diff $out_file $cmp_file > $log_file

if [ -s $log_file ]
then
  echo -en "${RED} FAILED \033[0m"
else
  echo -en "${GREEN} SUCCESS \033[0m\n"
fi


echo "input command : $(pwd)"
echo "filename : "
echo "result : "
echo "-- Testing -i flag --"
echo "-- Testing -v flag --"
echo "-- Testing -c flag --"
echo "-- Testing -l flag --"
echo "-- Testing -n flag --"
echo "-- Testing -h flag --"
echo "-- Testing -f flag --"
echo "-- Testing -o flag --"
echo "_____________Test__GREP__finished_______________"