
dirs := `ls -F |grep /`
all:
	for dir in $(dirs); do make -C $$dir; done

clean:
	for dir in $(dirs); do make -C $$dir clean; done
