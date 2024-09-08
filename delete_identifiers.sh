#!/bin/bash
# Set base directory to where the script is executed
BASE_DIR=$(pwd)

# Find and delete all files ending with .Identifier, including those in subdirectories
find "$BASE_DIR" -type f -name "*.Identifier" | while read -r file; do
	echo "Deleting file: $file"
	rm -f "$file"

	# Check if the file was successfully deleted
	if [ $? -eq 0 ]; then
		echo "Successfully deleted $file"
	else
		echo "Failed to delete $file"
	fi
done

echo "Script execution completed."