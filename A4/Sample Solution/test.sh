make

counter=0
for i in {1..10}
do
    if ! ./Scheduler.out < Testcases/input/$i.in | diff -rq Testcases/output/$i.out -; then
        echo "$i - Failed!"
    else
        echo "$i - Passed!"
        counter=$(( counter + 1 ));
    fi
done

echo -e "\n########\t$counter test cases passed!\t########"
