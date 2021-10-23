echo "some content" > _ex3.txt
chmod a-x _ex3.txt
ls -l _ex3.txt > ex3.txt
chmod uo+rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod uo+rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g=u _ex3.txt
ls -l _ex3.txt >> ex3.txt
echo "660 - user and his group can read and write, others can do nothing" >> ex3.txt
echo "775 - user and his group can read, write and execute, others can read and execute" >> ex3.txt
echo "777 - user, his group and others can read, write and execute" >> ex3.txt
