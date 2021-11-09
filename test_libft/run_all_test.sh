make -s
for f in targets/* ; do
	echo "$f"
	./$f
done
