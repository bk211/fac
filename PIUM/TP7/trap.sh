#!/bin/sh

trap 'increment' 2
trap 'stop' 3
trap 'none' 9

none(){
	echo "no one can kill me"
}

stop(){
	echo "Signal SIGQUIT received... OKAY, OKAY i’ll quit immediately"
	exit 1	
}

increment()
{
  echo "Caught SIGINT ..."
  #X=`expr ${X} + 500`
  X=`expr ${X}`
  if [ "${X}" -gt "2000" ]
  then
    echo "Okay, I'll quit ..."
    exit 1
  fi
  


}



### main script
X=0
while :
do
  echo "X=$X"
  X=`expr ${X} + 1`
  sleep 1
done
