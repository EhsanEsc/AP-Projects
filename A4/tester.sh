
make

./Scheduler.out < sample.in > oo.txt ;

if(diff -b oo.txt sample.out);
then
  echo "Right!"
else
  echo "Wrong!"
fi;

read -p "Press Enter..."

make clean
