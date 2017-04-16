mkdir backupfiles
cd $1
mkdir backup 
case $2 in
	"python") for file in *.py
					do 
					cp $file ./backup/${file%.py}.backup
					done
					var=$(date +%d-%b-%H_%M_backup_python).zip
					zip -r $var ./backup
					cd
					mv $1/$var backupfiles 
	"c") for file in *.c
                  do 
					cp $file ./backup/${file%.c}.backup
					done
					var=$(date +%d-%b-%H_%M_backup_c).zip
					zip -r $var ./backup
					cd
					mv $1/$var backupfiles 
	"cpp") for file in *.cpp
                  do 
					cp $file ./backup/${file%.cpp}.backup
					done
					var=$(date +%d-%b-%H_%M_backup_cpp).zip
					zip -r $var ./backup
					cd
					mv $1/$var backupfiles 
	"shell") for file in *.sh
                  do 
					cp $file ./backup/${file%.sh}.backup
					done
					var=$(date +%d-%b-%H_%M_backup_shell).zip
					zip -r $var ./backup
					cd
					mv $1/$var backupfiles 
	"java") for file in *.java
                  do 
					cp $file ./backup/${file%.java}.backup
					done
					var=$(date +%d-%b-%H_%M_backup_java).zip
					zip -r $var ./backup
					cd
					mv $1/$var backupfiles 
esac
