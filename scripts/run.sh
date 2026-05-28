if [[ $? -eq 0 ]]; then
	echo -e "Executing\n\n"
	./$EXE_FILENAME
else
	echo "Build failed, terminating..."
fi
