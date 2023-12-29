
import sys

# Converts all instances of ";" to "@" in the given file
def convertAssemblyFileComments(filePath):
    # Open the file
    file = open(filePath, "r")

    # Read the file into a string
    fileString = file.read()

    # Close the file
    file.close()

    # Replace all instances of ";" with "@"
    fileString = fileString.replace(";", "@")

    # Write the new string to the file
    file = open(filePath, "w")
    file.write(fileString)
    file.close()

def main():
    convertAssemblyFileComments(sys.argv[1])

if __name__ == '__main__':
    main()
