
check() {
  if [ $? -ne 0 ]; then
    exit 1
  fi
}

echo "Flex..."
flex willardorth.l
check
echo "Bison..."
bison willardorth.y
check
echo "Compiling..."
g++ willardorth.tab.c -o willardorth_parser
check
echo "Running Tests..."

for file in `ls inputs`; do
  echo -n "Running $file..."
  ./willardorth_parser < inputs/$file > temp.txt
  diff temp.txt outputs/$file.out > diff.txt
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

rm willardorth.tab.c willardorth_parser lex.yy.c temp.txt diff.txt
