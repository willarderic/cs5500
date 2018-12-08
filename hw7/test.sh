
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
g++ willardorth.tab.c -o miplc
check

for file in `ls inputs`; do
  echo -n "Running $file..."
  ./miplc inputs/$file > tmp.s
  as tmp.s -o tmp.o
  ld tmp.o
  ./a.out > temp.txt 2>&1
  #diff --ignore-space-change --ignore-case --ignore-blank-lines temp.txt outputs/$file.out > diff.txt
  #if [ $? -eq 0 ]; then
  #  echo -e "PASS"
  #else
    # If your file failed, uncomment the following lines
  #  echo -e "FAIL"
  #  echo -e "File Diff:"
  #  cat diff.txt
  #  echo -e "\e[91mYour Output:\e[39m"
  #  cat temp.txt
  #  exit 1
  #fi
done

rm willardorth.tab.c miplc lex.yy.c temp.txt diff.txt tmp.o tmp.s a.out
