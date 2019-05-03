g++ A1C-810197654.cpp -std=c++11 -o a.out

for((i=1;i<=30;i++));
do
  ./a.out < testcases/$i.in > oo.out;
  if(diff -b oo.out testcases/$i.sol);
  then
    echo "Test case " $i "Corrcet! :)";
  else
    echo "Test case " $i "Wrong  ! :(";
  fi;
done

read -p "Press Enter..."
