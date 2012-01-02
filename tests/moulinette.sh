#! /bin/sh

if ! [ -e "logs" ] ; then
  mkdir logs
fi;
rm -f logs/*

i=0
errors=0

while [ "$i" != "10000" ]; do
  python2 check.py > test
  du -sh test
  echo -e "Bistro :"
  r1=`time cat test | ./bistromathique`
  echo -e "Ref :"
  r2=`time cat test | ./ref`
  if [ "$r1" != "$r2" ] ; then
    echo -e "\033[34mfail\033[37m"
    errors=$((1 + $errors))
    cat test > logs/error${i}
    echo "My res  :" >> logs/error${i}
    echo $r1 >> logs/error${i}
    echo "Ref res :" >> logs/error${i}
    echo $r2 >> logs/error${i}
    #echo "My res  : $r1"
    #echo "Ref res : $r2"
  fi
  echo -e "-------------------------------------"
  echo -e "-------------------------------------"
  i=$((1 + ${i}))
done

echo
echo -e "\033[34m$errors fails\033[37m"
