
grep -oE '\w+' words.txt | sort | uniq -c | sort -nr | awk '{print $2, $1}'
