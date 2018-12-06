
check() {
  if [ $? -ne 0 ]; then
    exit 1
  fi
}

echo "Flexing, bisoning, compiling Compiler..."
flex willardorth.l
check
bison willardorth.y
check
g++ willardorth.tab.c -o compiler
check
echo "Flexing, bisoning, compiling VM..."
flex oal.l
check
bison oal.y
check
g++ oal.tab.c -o vm
check
echo "Running Tests..."

for file in `ls inputs`; do
  echo -n "Running $file..."
  ./compiler inputs/$file > temp.txt
  ./vm temp.txt
  diff --ignore-space-change --ignore-case --ignore-blank-lines temp.txt outputs/$file.out > diff.txt
  if [ $? -eq 0 ]; then
    echo -e "PASS"
  else
    # If your file failed, uncomment the following lines
    echo -e "FAIL"
    echo -e "File Diff:"
    cat diff.txt
    #echo -e "\e[91mYour Output:\e[39m"
    #cat temp.txt
    #exit 1
  fi
done

rm willarde.tab.c willarde_parser lex.yy.c temp.txt diff.txt
