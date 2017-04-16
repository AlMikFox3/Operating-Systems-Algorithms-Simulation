cd backup
unzip backup.zip
cd backup
for file in *.backup
	do 
	cp $file /home/sinu/OS_lab/${file%.backup}.c   
	done
