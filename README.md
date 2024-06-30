run cipher.exe with numeric argument to set rotation amount:
`./build/cipher.exe 20`

run cipher.exe with -d flag to decrypt with given rotation amount:
`./build/cipher.exe 20 -d`

Example run:
`cat file.txt | ./build/cipher.exe 20 > encrypted.txt` - Pipes contents of file.txt into cipher.exe and outputs encrypted text into encrypted.txt
`cat encrypted.txt | ./build/cipher.exe 20 -d > decrypted.txt` - Pipes contents of encrypted.txt into cipher.exe and outputs decrypted text into decrypted.txt