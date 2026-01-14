max=0
test=""

for i in {1..10000}
do
    args=$(shuf -i 0-1000 -n 500 | tr "\n" " ")
    res=$(./push_swap $args | wc -l)

    if [ "$res" -gt "$max" ]; then
        max=$res
        test="$args"
    fi
done

count=$(echo "$test" | wc -w)

echo "Worst input:"
echo "$test"
echo "Number of elements: $count"
echo "Max moves: $max"
