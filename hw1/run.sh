for file in ./input/*
do
  python mipl.py $file &> ./output/$(basename $file)
done
