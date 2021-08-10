
running = True
while running:
    file_path = input('File name (or path if file is not in the same directory as this script): ')
    split = input('what character is the file split by? (ex. \"line\", \"tab\", \",\", etc):' )
    new_file_name = str(input('New file name: '))

    file = open(file_path, 'r')
    new_file = open(new_file_name, 'w+')
    with file as i:
         if split == 'line':
             item = i.readline().strip()
             while item:
                new_file.write(item + ',')
                item = i.readline().strip()

    file.close()
    new_file.close()



    answer = input('convert another file? (yes/no): ')

    if answer[0] == 'n':
        running = False
        print('Thanks for using convert to CSV! Have a nice day.')

    print('-----\tNEXT FILE\t-----')