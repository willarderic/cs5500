echo "Flex..."
flex mipl.l
echo "Bison..."
bison mipl.y
echo "Compiling..."
g++ mipl.tab.c -o mipl_parser
echo "Running Tests..."

for file in `ls inputs`; do
  echo -n "Running your output against $file..."
  ./mipl_parser < inputs/$file > temp.txt
  diff --ignore-space-change --side-by-side --ignore-case --ignore-blank-lines temp.txt outputs/$file.out > diff.txt
  if [ $? -eq 0 ]; then
    echo -e " PASS"
  else
    # If your file failed, uncomment the following lines
    # To get the full diff between your output and the expected output
    echo -e " FAIL"
    echo -e "File Diff:"
    cat diff.txt
  fi
done

rm mipl.tab.c mipl_parser lex.yy.c temp.txt diff.txt
