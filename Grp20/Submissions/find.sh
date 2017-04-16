case $2 in
	"python") grep  -r -s -l  --include=*.py "$1" * >find.txt
                  echo "The files are"
                  cat find.txt
                  echo -n "Do you want to delete all the files(Y/N)?"
                  read text
                  if [ "$text" == "Y" ]
                  then  
                        while read line; do
                              rm $line
                              done< find.txt
                        echo "Files deleted"                 
                  else
                        echo "Files are not deleted"
                  fi                
	"c") grep  -r -s -l  --include=*.c "$1" * >find.txt
                  echo "The files are"
                  cat find.txt
                  echo -n "Do you want to delete all the files(Y/N)?"
                  read text
                  if [ "$text" == "Y" ]
                  then  
                        while read line; do
                              rm $line
                              done< find.txt 
                        echo "Files deleted"          
                  else
                        echo "Files are not deleted"
                  fi 
	"cpp") grep  -r -s -l  --include=*.cpp "$1" * >find.txt
                  echo "The files are"
                  cat find.txt
                  echo -n "Do you want to delete all the files(Y/N)?"
                  read text
                  if [ "$text" == "Y" ]
                  then  
                        while read line; do
                              rm $line
                              done< find.txt
                        echo "Files deleted"                
                  else
                        echo "Files are not deleted"
                  fi 
esac
